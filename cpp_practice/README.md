# C++ Practice

Coming from Java, Python, and C. The goal here isn't to learn syntax — it's to build
intuition for the three things C++ adds that neither Java nor C has: **value semantics**,
**RAII**, and **the standard library as the default toolbox**.

## Build

```sh
g++ -std=c++17 -Wall -Wextra -g -o wordfreq main.cpp
./wordfreq input.txt
./wordfreq < input.txt        # also works: falls back to stdin
```

Always compile with `-Wall -Wextra`. Warnings in C++ catch real bugs far more often than
they do in C, especially around implicit conversions and unused-after-move values.

For debugging memory issues later:

```sh
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined -o wordfreq main.cpp
```

---

## Exercise 01 — Word frequency counter

Read text, count how often each word appears, print the top N.

### Spec

- Read from a file given as `argv[1]`; if no argument, read from stdin.
- A "word" is a maximal run of alphabetic characters and apostrophes. Everything else is a
  separator.
- Case-insensitive: `The` and `the` are the same word.
- Print the top 10 words as `count  word`, one per line, sorted by descending count, ties
  broken alphabetically.
- Then print the total word count and the unique word count.

### Constraints

These exist to force idiomatic C++ rather than C-with-classes.

- No `new`, `delete`, `malloc`, or raw arrays. Only `std::string`, `std::vector`,
  `std::unordered_map`.
- No `printf`. Use `std::cout` and stream manipulators from `<iomanip>` for column
  alignment.
- Split into at least three functions: `read_text`, `tokenize`, `count_words`.
- Pass containers by `const&` wherever you only read them.
- Use `std::sort` with a lambda for the ordering.
- Use range-based `for` loops and structured bindings:
  `for (const auto& [word, count] : counts)`.

### Stretch goals, in order

1. Wrap the counting in a `class WordCounter` with `add_text(const std::string&)` and
   `top(int n) const`. Note the trailing `const` on the method — Java has no equivalent.
2. Add a constructor taking a stopword list, and skip those words.
3. Make `top` return `std::vector<std::pair<std::string, int>>`. Confirm you understand
   why returning a large vector by value is fine here (move semantics and RVO) even though
   it would have been a bad idea in C.

---

## Gotchas to keep re-reading

**Copies are silent.** `std::vector<std::string> f(std::vector<std::string> v)` copies
every string on the way in. In C you'd have passed a pointer and there'd be no ambiguity.
Default to `const std::vector<std::string>&` for read-only parameters.

**`map[key]` on a missing key inserts** a default-constructed value and returns a reference
to it. That's exactly what makes `counts[word]++` work — the `int` starts at 0 — but it
also means using `map[key]` in a read-only context silently grows the map. Use `.at()` to
get an exception instead, or `.find()` for an iterator.

**`auto` strips references and const.** `auto x = v[0];` copies. `auto& x = v[0];` doesn't.
This is the most common early bug for people arriving from C or Java.

**`std::string` is a value type**, not a `char*`. It copies on assignment, concatenates
with `+`, compares with `==`. Nothing like `strcmp` is needed, and it owns and frees its
own buffer.

**Prefer `std::getline(in, line)`** over `>>` when you want whole lines. Stream `>>` stops
at whitespace and leaves the newline in the buffer, which causes the classic
"my next read returned an empty string" confusion.

**`const` is load-bearing here.** Unlike Java's `final`, C++ `const` propagates: a `const`
object only lets you call `const` methods, and a `const&` parameter documents and enforces
that you won't mutate the caller's data. Put it everywhere you can.

---

## Roadmap

| # | Exercise | What it teaches |
|---|----------|-----------------|
| 01 | Word frequency counter | Standard library, value semantics, `const&`, lambdas |
| 02 | `MyVector<T>` with destructor, copy constructor, copy assignment | RAII, rule of three, templates |
| 03 | (to add) | |

Exercise 02 is the one where RAII actually clicks, and your C background makes it
straightforward: you already know what the underlying `malloc`/`free` pairing looks like,
so the point is seeing the destructor take that responsibility off your hands.

## Suggested folder layout

```
cpp-practice/
├── README.md
├── 01-wordfreq/
│   ├── main.cpp
│   └── input.txt
└── 02-myvector/
    └── main.cpp
```
