#!/bin/bash

# Stop the build if an error is encountered
set -e

# Define the variables
BUILD_DIR="build"
COMPILER="gcc"
MAIN_FILE="src/main.c"
MAIN_BIN="$BUILD_DIR/main"
RAYLIB_COMPILE="-lraylib -lGL -lm -lpthread -ldl -lrt -lX11"
EXE_FILE="squared"

# Remove the build directory if it exists
if [ -d $BUILD_DIR ]; then
    rm -r $BUILD_DIR
fi

# And re-create it
mkdir $BUILD_DIR

# Compile main file
echo "Compiling $MAIN_FILE..."
$COMPILER -o $MAIN_BIN $MAIN_FILE $RAYLIB_COMPILE