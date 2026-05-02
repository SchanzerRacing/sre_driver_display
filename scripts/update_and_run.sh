#!/bin/bash

# Configuration
REPO_URL="https://github.com/SchanzerRacing/sre_driver_display.git"
PROJECT_DIR="$HOME/driver-display"
GTK_WORKSPACE_DIR="$PROJECT_DIR/gtkWorkspace"
BUILD_DIR="$GTK_WORKSPACE_DIR/build"
EXECUTABLE="$BUILD_DIR/driver-display.out"
MAX_RETRIES=5
RETRY_INTERVAL=10

cd "$PROJECT_DIR" || exit 1

# Ensure the executable exists before running
if [ ! -f "$EXECUTABLE" ]; then
    echo "Error: Executable not found: $EXECUTABLE"
    exit 1
fi

# Set the DISPLAY variable for the GUI application
export DISPLAY=:0  # Ensure the display is correct

# Run the program from the correct directory (gtkWorkspace)
echo "Starting the application..."
cd "$GTK_WORKSPACE_DIR" || exit 1
"$EXECUTABLE"
