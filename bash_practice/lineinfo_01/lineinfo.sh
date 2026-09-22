#!/bin/bash

# lineinfo.sh
# If a file is provided, read from that file. If no file is provided,
# read from stdin
#<line_number>: <word_count> words - <original line>

set -euo pipefail

# Usage: 
readonly USAGE='Usage: lineinfo [file]'

# check for number of parameters 
if [[ "$#" -gt 1 ]]; then
	echo "$USAGE" >&2
	exit 2
fi

# sets filename to "$#2" or an empty string
filename="${1:-/dev/stdin}"

# if file exists, checks
if [[ "$#" -eq 1 ]] && { [[ ! -e "$filename" ]] || [[ ! -r "$filename" ]]; }; then
	echo "lineinfo.sh: unable to read $filename" >&2
	exit 2
fi

# preserve total line and word count
line_count=0
total_word_count=0

# iterate through each line and perform each applicable action
while IFS=  read -r line; do
	line_count=$((line_count + 1))
	# preserved_line = "$line"
	
	# subshell into arithmetic expansion gets rid of surplus white space that
	# wc throws in
	word_count=$(( $( echo "$line" | wc -w) ))
	total_word_count=$((total_word_count + word_count))
	
	echo "$line_count: $word_count words - $line"

done < "$filename"	

echo "Total lines: $line_count" && echo "Total words: $total_word_count"
exit 0
