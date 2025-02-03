#!/bin/bash

logFile="errors.log"

# Function to log errors
logError() {
    echo "[ERROR]: $1" | tee -a "$logFile"
}

# Function to show help message
showHelp() {
    cat << EOF
Usage:
    -d <directory>   : Search in a directory
    -k <keyword>     : Keyword to search
    -f <file>        : Search in a file
    --help           : Show help menu
EOF
}

# Function to perform search in a directory
searchInDir() {
    local dir=$1
    local keyword=$2
    local found=0

    if [[ ! -d "$dir" ]]; then
        logError "Invalid or inaccessible directory: $dir"
        return
    fi

    for file in "$dir"/*; do
        if [[ -d "$file" ]]; then
            searchInDir "$file" "$keyword"  # Recursively search subdirectories
        elif [[ -f "$file" ]]; then
            if grep -q "$keyword" "$file"; then
                echo "Found in: $file"
                found=1
            fi
        fi
    done

    if [[ $found -eq 0 ]]; then
        logError "Keyword '$keyword' not found in directory: $dir"
    fi
}

# Function to perform search in a file
searchInFile() {
    local file=$1
    local keyword=$2

    if [[ ! -f "$file" ]]; then
        logError "File not found: $file"
        return
    fi
    if grep -q "$keyword" "$file"; then
        echo "Found in: $file"
    else
        logError "Keyword '$keyword' not found in file: $file"
    fi
}

# Parse command-line arguments
while getopts "d:f:k:" opt; do
    case "$opt" in
        d) dir="$OPTARG" ;;
        f) file="$OPTARG" ;;
        k) keyword="$OPTARG" ;;
        ?) logError "Invalid option"; showHelp; exit 1 ;;
    esac
done

# Validate keyword and check if it is provided
if [[ -z "$keyword" ]]; then
    logError "Keyword cannot be empty."
    showHelp
    exit 1
fi

# Validate that the keyword has allowed characters
if ! echo "$keyword" | grep -Eq '^[a-zA-Z0-9._ @-]+$'; then
    logError "Invalid keyword: $keyword"
    exit 1
fi

# Perform search based on arguments
if [[ -n "$dir" ]]; then
    searchInDir "$dir" "$keyword"
elif [[ -n "$file" ]]; then
    searchInFile "$file" "$keyword"
else
    logError "Please provide a directory (-d) or file (-f) to search."
    showHelp
    exit 1
fi
