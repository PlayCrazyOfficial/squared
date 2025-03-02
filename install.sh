#!/bin/bash

# Please notice that this file must be executed as root

$EXE_FILE="squared"
$INSTALL_DIR="/usr/local/bin"

if [ ! -e $EXE_FILE ]; then
    echo "Executable not found. Please build the game first or download the executable."
else
    mv $EXE_FILE "$INSTALL_DIR/squared"
    echo "Squared is now installed in $INSTALL_DIR"
fi