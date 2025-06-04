#!/bin/bash
set -e

ROOT="$(git rev-parse --show-toplevel)"
cd "$ROOT"

for file in $(find . -name '*.cpp'); do
    echo "Compiling $file"
    g++ -std=c++17 -c "$file" -o /dev/null
done

echo "All files compiled successfully."
