# CS 361 - Final Exam, Part B, Question 6

Cole Baty
UIN 01187002

This is my "second best" solution.

## Running

```bash
$> make
$> ./main
```
## Problem description

Quaternary search tree. Child nodes are assigned by quartile, per the intervals
described in assignment instructions.  User supplies an integer N representing 
the number of nodes to generate with random integer values on [1, 1000].

Integers were generated randomly by the `uniform_int_dist` random number
generator from the `<random>` STL.

## Implementation

For sufficiently large values of N, the number of nodes generated *may be less 
than* N.  This is because there is no specific guidance on how to handle duplicate
values to be inserted, so they are ignored in this implementation.  During testing,
I discovered that duplicates were being added to Q4 children, and therefore were
being printed (in order!) last during depth-first display.  This behaviour was
corrected by explicitly describing the Q4 interval as being <= the Q4 comparison
value, .e.g

```cpp
void node::add()
{
    //before
    ...
    else if (_val < data && data < (_val * 3 / 2))
    {
        //add to Q3
    }
    else
    {
        //add to Q4
    }

    ...

    //after
    ...
    else if (_val < data && data < (_val * 3 / 2))
    {
        //add to Q3
    }
    else if ((_val * 3 / 2) <= data)
    {
        //add to Q4
    }
}
```

## Tests

To build and run tests, comment out `line 55` of the Makefile (`TARGET=main`).
Then run the following commands.

```bash
$> make TARGET=<name of test file without extension>
$> ./<name of test file without extension>
```

## Misc.

This program was tested on the ODU CS Department Linux servers on 24 April 2022.
The program behaved as intended.