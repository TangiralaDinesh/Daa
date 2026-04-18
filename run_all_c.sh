#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$ROOT"

mkdir -p bin output input
RUN_TIMEOUT=5

declare -A sample_inputs
sample_inputs[approximation]=$'4\n0 1 0 0\n1 0 1 1\n0 1 0 1\n0 1 1 0'
sample_inputs[fib]=$'6'
sample_inputs[first_fit_bin]=$'4\n10\n2\n5\n4\n3'
sample_inputs[fra_knap]=$'3\n10 20 30\n60 100 120\n50'
sample_inputs[linear]=''
sample_inputs[mst]=$'4\n0 2 0 6\n2 0 3 8\n0 3 0 0\n6 8 0 0'
sample_inputs[network_flow]=$'4\n0 16 13 0\n0 0 10 12\n0 4 0 14\n0 0 0 0\n0 3'
sample_inputs[perm]=$'3\n1 2 3'
sample_inputs[randomised]=$'5\n5 1 4 2 3'
sample_inputs[shortest_path]=$'4\n0 3 0 7\n8 0 2 0\n5 0 0 1\n2 0 0 0\n0'
sample_inputs[tsp]=$'4\n0 20 42 35\n20 0 30 34\n42 30 0 12\n35 34 12 0'
sample_inputs[toh]=$'3'
# binary_search.c is empty in this repository and cannot be run without code
sample_inputs[binary_search]=''

for src in ./*.c; do
  if [[ ! -f "$src" ]]; then
    continue
  fi

  base="$(basename "$src" .c)"
  exe="bin/$base.exe"
  link="bin/$base"
  out="output/$base.out"
  input_file="input/$base.in"

  echo "Compiling $src -> $exe"
  if ! gcc -std=c17 -O2 "$src" -o "$exe" 2> "output/$base.build.log"; then
    printf "Compilation failed for %s\n" "$src" > "$out"
    printf "See build log: output/%s.build.log\n" "$base" >> "$out"
    continue
  fi

  if [[ -e "$link" ]]; then
    rm -f "$link"
  fi
  ln -sf "$exe" "$link" || true

  input_text="${sample_inputs[$base]:-}"
  if [[ -n "$input_text" ]]; then
    printf '%s\n' "$input_text" > "$input_file"
    printf "=== Input for %s ===\n%s\n\n" "$base" "$input_text" > "$out"
    echo "Running $exe with sample input -> $out"
    if ! stdbuf -o0 -e0 timeout "${RUN_TIMEOUT}s" "$exe" < "$input_file" >> "$out" 2>&1; then
      echo "Program $base did not complete within ${RUN_TIMEOUT}s. Output saved to $out"
      printf "\n=== Program did not complete within %s seconds ===\n" "$RUN_TIMEOUT" >> "$out"
    fi
  else
    printf "=== Running %s without stdin ===\n\n" "$base" > "$out"
    echo "Running $exe with no stdin -> $out"
    if ! stdbuf -o0 -e0 timeout "${RUN_TIMEOUT}s" "$exe" >> "$out" 2>&1; then
      echo "Program $base did not complete within ${RUN_TIMEOUT}s. Output saved to $out"
      printf "\n=== Program did not complete within %s seconds ===\n" "$RUN_TIMEOUT" >> "$out"
    fi
  fi

done

echo "Finished. Executables are in bin/, sample inputs in input/, and outputs in output/."
