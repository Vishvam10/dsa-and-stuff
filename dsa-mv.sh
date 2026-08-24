#!/bin/bash

SCRATCHPAD="$(pwd)/scratchpad"
DSA="$(pwd)/dsa-and-stuff/CodeForces"

move_problem() {
    file="$1"
    problem="$(basename "$file" .cpp)"
    dest="$DSA/$problem/main.cpp"

    if [[ -f "$dest" ]]; then
        echo "SKIP: $problem"
        return
    fi

    mkdir -p "$DSA/$problem"
    mv "$file" "$dest"
    echo "MOVED: $problem"
}

# Dated folders
find "$SCRATCHPAD"/07-2026 "$SCRATCHPAD"/08-2026 \
    -type f -name '*.cpp' -print0 2>/dev/null |
while IFS= read -r -d '' file; do
    move_problem "$file"
done

# others/
find "$SCRATCHPAD/others" \
    -type f -name '*.cpp' -print0 2>/dev/null |
while IFS= read -r -d '' file; do
    move_problem "$file"
done

# Root-level .cpp files
for file in "$SCRATCHPAD"/*.cpp; do
    [[ -f "$file" ]] || continue

    problem="$(basename "$file" .cpp)"

    # Utility files, not problems
    case "$problem" in
        simple|template)
            echo "SKIP: $problem (utility)"
            continue
            ;;
    esac

    move_problem "$file"
done
