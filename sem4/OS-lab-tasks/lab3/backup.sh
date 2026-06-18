#!/bin/bash
SRC_DIR=/path/to/source/directory
DST_DIR=/path/to/backup/directory
if [ ! -d "$DST_DIR" ]; then
mkdir -p "$DST_DIR"
fi
for file in "$SRC_DIR"/*; do
cp "$file" "$DST_DIR"
done
if [ ! -d "$SRC_DIR" ]; then
echo "Error: Source directory does not exist"
exit 1
fi