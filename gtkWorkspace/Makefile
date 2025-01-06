# Compiler
CC = gcc

# Compiler flags
CFLAGS = `pkg-config --cflags gtk4` -g -O0

# Linker flags
LDFLAGS = `pkg-config --libs gtk4`

# Source files
SRC = main.c

# Output folder
OUT_DIR = build

# Output executable
OUT = $(OUT_DIR)/driver-display.out

.PHONY: all rebuild clean

# New rules
driver-display: $(OUT_DIR)/main.o $(OUT_DIR)/debug_panel.o $(OUT_DIR)/endurance_panel.o $(OUT_DIR)/parameters_panel.o $(OUT_DIR)/sre_logic.o $(OUT_DIR)/sre_can.o
	$(CC) $(OUT_DIR)/main.o $(OUT_DIR)/debug_panel.o $(OUT_DIR)/endurance_panel.o $(OUT_DIR)/parameters_panel.o $(OUT_DIR)/sre_logic.o $(OUT_DIR)/sre_can.o $(LDFLAGS) -o $(OUT)

$(OUT_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OUT_DIR)/main.o

$(OUT_DIR)/debug_panel.o: debug_panel.c
	$(CC) $(CFLAGS) -c debug_panel.c -o $(OUT_DIR)/debug_panel.o

$(OUT_DIR)/endurance_panel.o: endurance_panel.c
	$(CC) $(CFLAGS) -c endurance_panel.c -o $(OUT_DIR)/endurance_panel.o

$(OUT_DIR)/parameters_panel.o: parameters_panel.c
	$(CC) $(CFLAGS) -c parameters_panel.c -o $(OUT_DIR)/parameters_panel.o

$(OUT_DIR)/sre_logic.o: sre_logic.c
	$(CC) $(CFLAGS) -c sre_logic.c -o $(OUT_DIR)/sre_logic.o

$(OUT_DIR)/sre_can.o: sre_can.c
	$(CC) $(CFLAGS) -c sre_can.c -o $(OUT_DIR)/sre_can.o


all: rebuild

rebuild: clean
	$(MAKE) -B driver-display

clean:
	rm -f $(OUT_DIR)/*.o $(OUT)

# Create output directory if it doesn't exist
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# Ensure output directory is created before compiling
$(OUT_DIR)/main.o: | $(OUT_DIR)
$(OUT_DIR)/debug_panel.o: | $(OUT_DIR)
$(OUT_DIR)/endurance_panel.o: | $(OUT_DIR)
$(OUT_DIR)/parameters_panel.o: | $(OUT_DIR)
$(OUT_DIR)/sre_logic.o: | $(OUT_DIR)