# Compiler
CC = gcc

# Compiler flags
CFLAGS = `pkg-config --cflags gtk4`

# Linker flags
LDFLAGS = `pkg-config --libs gtk4`

# Source files
SRC = main.c

# Output executable
OUT = gtkapp

# New rules
driver-display: main.o debug_panel.o endurance_panel.o parameters_panel.o
	$(CC) main.o debug_panel.o endurance_panel.o parameters_panel.o $(LDFLAGS) -o driver-display

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

debug_panel.o: debug_panel.c
	$(CC) $(CFLAGS) -c debug_panel.c

endurance_panel.o: endurance_panel.c
	$(CC) $(CFLAGS) -c endurance_panel.c

parameters_panel.o: parameters_panel.c
	$(CC) $(CFLAGS) -c parameters_panel.c

clean:
	rm -f *.o driver-display