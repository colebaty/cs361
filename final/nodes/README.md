# CS 361 - Final Exam, Part B, Question 2

Cole Baty
UIN 01187002

This is my "third best" solution.

## Running

To run this program, type `make` at the command prompt. This will produce an 
executable named `main`, which can be run by typing the command.

```bash
$> ./main
```

## Problem description

Menu-driven.  User supplies number of nodes (N) and number of letters (M) to be
generated.  Letters are randomly generated capital letters [A-Z].  Letters
are distributed to the N nodes as though they were dealt out like a hand of
cards.

Menu options are:
 - enter N and M
 - generate N nodes and M characters (and distribute them as outlined above)
 - search for all nodes containing a given character
 - display all characters associated with a given node
 - erase the current data collection
 - exit

## Implementation

Letters are generated randomly by a `uniform_int_dist` random number generator,
which are then implicltly converted to `char` types during assignment.

Since the underlying queue element has only two access points, in order to
display or search the queue, I implemented a pseudo in-place solution. An early
naive approach just copied the queue to a temporary queue and just printed/searched
by popping each element, but for very large sets of letters this is 
space-inefficient.

The in-place solution rotates the underlying queue once entirely through, 
returning all elements to their original positions.

If the underlying queue is empty, `node::display` just says so.

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