#!/usr/bin/env bash

set -u

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

DIRS=(
    "$ROOT_DIR/CodeForces"
    "$ROOT_DIR/CSES"
    "$ROOT_DIR/LeetCode"
)

echo "Formatting DSA solutions..."
echo

# ------------------------------------------------------------
# C++
# ------------------------------------------------------------

# Replace #include <bits/stdc++.h> with explicit standard library headers

find "${DIRS[@]}" \
    -type f \
    -name "*.cpp" \
    -exec perl -0pi -e 's/#include\s*<bits\/stdc\+\+\.h>/
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>/g' {} +

# clang-tidy only on CodeForces/CSES.
# LeetCode submissions may intentionally omit includes / using namespace std.
if command -v clang-tidy >/dev/null 2>&1; then
    echo "Running clang-tidy..."

    while IFS= read -r -d '' file; do
        if clang-tidy \
            -checks='-*,misc-include-cleaner' \
            -fix \
            "$file" \
            -- \
            -std=c++17; then
            :
        else
            echo "  🟡 clang-tidy failed: ${file#$ROOT_DIR/}"
        fi
    done < <(
        find \
            "$ROOT_DIR/CodeForces" \
            "$ROOT_DIR/CSES" \
            -type f \
            -name "*.cpp" \
            -print0
    )

    echo "🟢 clang-tidy"
else
    echo "🟡 clang-tidy not found"
fi

if command -v clang-format >/dev/null 2>&1; then
    find "${DIRS[@]}" \
        -type f \
        -name "*.cpp" \
        -exec clang-format -i {} +

    echo "🟢 C++"
else
    echo "🔴 clang-format not found"
fi

# ------------------------------------------------------------
# Python
# ------------------------------------------------------------

if command -v ruff >/dev/null 2>&1; then
    if ruff format "${DIRS[@]}"; then
        echo "🟢 Python"
    else
        echo "🟡 Python: some files could not be formatted"
    fi
else
    echo "🔴 ruff not found"
fi

# ------------------------------------------------------------
# Go
# ------------------------------------------------------------

if command -v gofmt >/dev/null 2>&1; then
    echo "Formatting Go..."

    while IFS= read -r -d '' file; do
        # LeetCode solutions often omit the package declaration.
        if ! grep -qE '^[[:space:]]*package[[:space:]]+[A-Za-z_][A-Za-z0-9_]*' "$file"; then
            sed -i '' '1s/^/package main\n\n/' "$file"
        fi

        if gofmt -w "$file"; then
            :
        else
            echo "  🟡 Skipped invalid Go: ${file#$ROOT_DIR/}"
        fi
    done < <(
        find "${DIRS[@]}" \
            -type f \
            -name "*.go" \
            -print0
    )

    echo "🟢 Go"
else
    echo "🔴 gofmt not found"
fi

# ------------------------------------------------------------
# Rust
# ------------------------------------------------------------

if command -v rustfmt >/dev/null 2>&1; then
    echo "Formatting Rust..."

    while IFS= read -r -d '' file; do
        if rustfmt "$file"; then
            :
        else
            echo "  🟡 Skipped invalid Rust: ${file#$ROOT_DIR/}"
        fi
    done < <(
        find "${DIRS[@]}" \
            -type f \
            -name "*.rs" \
            -print0
    )

    echo "🟢 Rust"
else
    echo "🟡 rustfmt not found"
fi

echo
echo "Done."
