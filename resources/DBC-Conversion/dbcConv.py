import re
import cantools

def dbc_to_header(dbc_path, header_path):
    # Load the DBC file using cantools
    db = cantools.database.load_file(dbc_path)

    with open(header_path, 'w') as header_file:
        # Write the header guard and includes
        header_file.write("""
/*
 * Generated Header File from DBC
 * Auto-generated using Python
 */
#ifndef SYSTEM_LIB_SYSTEM_DBC_H
#define SYSTEM_LIB_SYSTEM_DBC_H

#include <inttypes.h>
#include <stdbool.h>

""")

        # Generate union for CAN messages with bitfields
        for message in db.messages:
            header_file.write(f"// ----------------------------- {message.name} ----------------------------\n")
            header_file.write(f"#define {message.name.upper()}_ID {hex(message.frame_id)}\n")
            header_file.write(f"#define {message.name.upper()}_DLC {message.length}         // Number of Bytes\n\n")
            header_file.write(f"union {message.name}_UNION\n{{\n")
            header_file.write(f"    uint64_t data;\n")
            header_file.write(f"    struct\n    {{\n")
            bit_position = 0
            for signal in message.signals:
                header_file.write(f"        uint64_t {signal.name} : {signal.length};\n")
                bit_position += signal.length
            remaining_bits = 64 - bit_position
            if remaining_bits > 0:
                header_file.write(f"        uint64_t reserved : {remaining_bits};\n")
            header_file.write("    };\n};\n\n")

        # Close the header guard
        header_file.write("""
#endif // SYSTEM_LIB_SYSTEM_DBC_H
""")

# Example usage:
dbc_to_header('BODY-CAN_24.dbc', 'generated_system_DBC.h')
