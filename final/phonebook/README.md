# CS 361 - Final Exam, Part B, Question 1

Cole Baty
UIN 01187002

## Running

```bash
$> make
$> ./main
```

## Problem description

Menu-driven phonebook. Searchable by name, address, phone number.

## Implementation

Entries are stored in `record` objects. All fields are stored as strings.

`record`s are refereneced by a `std::map` mapping each name, address, and phone
number to an individual record (stored on the heap).

Lookup/access is O(log n) time for `map`s, so while this implementation may not 
be spatially conservative, lookup is relatively fast.

I believe my implementation could be called a naive database implementation.

The data file is randomly generated.  For simplicity, only "last names" are
included.  Names of people and streets are all lowercase.  Phone numbers are
seven digits long, no hyphens (or parentheses).