#!/bin/bash

writefile=$1
writestr=$2

if [ -z "$writefile" ] || [ -z "$writestr" ]; then
    echo "Error: Missing parameters"
    exit 1
fi

# Create the directory if it doesn't exist
mkdir -p "$(dirname "$writefile")"

echo "$writestr" > "$writefile"
