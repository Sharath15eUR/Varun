#!/bin/bash

#check if the number of arguments passed matches the required one
if [ "$#" -ne 3 ]; then
  echo "Usage: $0 <source_directory> <backup_directory> <file_extension>"
  exit 1
fi

# Read command-line arguments
SOURCE_DIR="$1"
BACKUP_DIR="$2"
FILE_EXT="$3"

# Validate source directory
if [ ! -d "$SOURCE_DIR" ]; then
  echo "Error: Source directory '$SOURCE_DIR' does not exist."
  exit 1
fi

# Create backup directory if it doesn't exist
if [ ! -d "$BACKUP_DIR" ]; then
  echo "Creating backup directory '$BACKUP_DIR'..."
  mkdir -p "$BACKUP_DIR" || { echo "Error: Failed to create backup directory."; exit 1; }
fi

# Globbing and storing files in an array
FILES=($(find "$SOURCE_DIR" -type f -name "*${FILE_EXT}"))

# Check if there are matching files
if [ "${#FILES[@]}" -eq 0 ]; then
  echo "No files found with extension '$FILE_EXT' in '$SOURCE_DIR'. Exiting."
  exit 0
fi

#exporting the variable for global access
export BACKUP_COUNT=0
TOTAL_SIZE=0
REPORT_FILE="$BACKUP_DIR/backup_report.log"
> "$REPORT_FILE"  # Clear previous report

for FILE in "${FILES[@]}"; do
  FILE_NAME=$(basename "$FILE")
  DEST_FILE="$BACKUP_DIR/$FILE_NAME"
  FILE_SIZE=$(stat -c%s "$FILE")
  TOTAL_SIZE=$((TOTAL_SIZE + FILE_SIZE))
  echo "Copying: $FILE_NAME ($FILE_SIZE bytes)" >> "$REPORT_FILE"

  [ ! -f "$DEST_FILE" ] || [ "$FILE" -nt "$DEST_FILE" ] && cp "$FILE" "$DEST_FILE"
done

echo "Total files: ${#FILES[@]}" >> "$REPORT_FILE"
echo "Total size: $TOTAL_SIZE bytes" >> "$REPORT_FILE"
echo "Backup directory: $BACKUP_DIR" >> "$REPORT_FILE"
echo "Backup complete. Report at '$REPORT_FILE'."

