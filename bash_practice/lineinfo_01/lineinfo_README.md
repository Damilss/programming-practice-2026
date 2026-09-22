# `lineinfo` Bash Practice

Write a Bash script called:

```bash
lineinfo.sh
```

## Usage

```text
Usage: lineinfo [file]
```

`file` is optional.

- If a file is provided, read input from that file.
- If no file is provided, read from standard input (`stdin`).

Examples:

```bash
./lineinfo.sh data.txt
```

```bash
cat data.txt | ./lineinfo.sh
```

## Goal

For each input line, print:

```text
<line_number>: <word_count> words - <original line>
```

After all input has been processed, print:

```text
Total lines: <number>
Total words: <number>
```

## Example

Input:

```text
hello world
this is bash
one
```

Expected output:

```text
1: 2 words - hello world
2: 3 words - this is bash
3: 1 words - one
Total lines: 3
Total words: 6
```

## Requirements

Practice using:

- `$#` to check the number of arguments
- `$1` for the optional filename
- `readonly`
- `[[ ... ]]`
- `while IFS= read -r line`
- input redirection with `<`
- `wc -w`
- arithmetic with `$(( ... ))` or `(( ... ))`
- stdout and stderr
- exit statuses
- reading from `stdin`

## Argument Rules

The script accepts either:

```bash
./lineinfo.sh
```

or:

```bash
./lineinfo.sh filename
```

If more than one argument is provided, print:

```text
Usage: lineinfo.sh [file]
```

to standard error and exit with status `1`.

## File Errors

If a filename is provided but it does not exist or is not readable, print:

```text
lineinfo.sh: unable to read filename
```

to standard error and exit with status `1`.

Successful execution should exit with status `0`.

## Useful Reminder

A standard loop for reading a file line-by-line looks like:

```bash
while IFS= read -r line; do
    # process "$line"
done < "$filename"
```

Remember:

```text
IFS=              controls how whitespace is handled
read -r line      reads one line into the variable "line"
< "$filename"     tells the loop where stdin comes from
```

If no filename was provided, `read` can simply inherit the script's normal stdin.

## Suggested Variables

You may find variables like these useful:

```text
filename
line
line_number
word_count
total_words
```

Initialize counters before the loop.

## Things to Test

Try:

```bash
./lineinfo.shdata.txt
```

```bash
cat data.txt | ./lineinfo.sh
```

```bash
./lineinfo.sh
```

Then manually type a few lines and send EOF with:

```text
Ctrl-D
```

Also test:

```bash
./lineinfo.sh file1 file2
```

and:

```bash
./lineinfo.sh no_such_file
```

Check the exit code afterward with:

```bash
echo $?
```

## Optional Challenge

After finishing `lineinfo.sh`, modify it so blank lines are reported as:

```text
3: 0 words -
```

and are still included in the total line count.
