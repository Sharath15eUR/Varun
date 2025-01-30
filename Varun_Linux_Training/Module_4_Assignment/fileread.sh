#!/bin/bash

# Check if the input file is provided
if [ $# -ne 1 ]; then
    echo "Input File is not provided"
fi

INPUT_FILE="$1"
OUTPUT_FILE="output.txt"

# Clear the output file
> "$OUTPUT_FILE"

# Check if the input file exists
if [ ! -f "$INPUT_FILE" ]; then
  echo "Error: File does not exist"
fi

# Read the input file line by line
while IFS= read -r line; do
    echo "$line" | grep '"frame.time"\|"wlan.fc.type"\|"wlan.fc.subtype"' | sed 's/$/,/' >> "$OUTPUT_FILE"
done < "$INPUT_FILE"

# Remove the last comma to keep correct formatting
sed -i '$s/,$//' "$OUTPUT_FILE"
echo "Extraction complete. Results saved in '$OUTPUT_FILE'."
