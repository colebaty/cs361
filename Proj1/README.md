# Shipyard: Phase 1 Deliverable - CS 360 with Prof. Jay D. Morris

by Cole Baty, UIN 01187002, tbaty002@odu.edu

## Compiling

Running the command `make` will produce an executable file named `main`.

## Notes

This project was tested on the ODU CS Linux servers on Feb 13, 2022, and it 
behaved as expected.

This program increments in timesteps of 10, prompting the user to continue after
every 10 timesteps, terminating when all `switchTrack`s are full. For expedience,
you may uncomment lines 62-72, which will pre-fill the tracks with a random
number of `container`s between 35 and 39 - this also simulates loading `container`s
onto `switchTrack`s of non-uniform fullness.

Additionally, `crane`s 0, 3, and 4 are pre-loaded with `container`s, in order
to better simulate in-progress unloading.

The `ship` object does instantiate a cargo element full of dynamically
allocated `container` objects with randomly assigned destination codes. The cargo
element is a 2-D vector of stacks. I haven't yet developed a method to keep
track of which stack was visited last (in order to determine whether it is empty), 
so that the "next" container can be fed from the `ship` to the `crane`.

To this end, I have created a stub for `ship::getNext()` that produces a dynamically
allocated `container` each time it is called. For the time being, this is the proof
of concept for passing a `container` generated on the heap along the following path:

```
generated on ship -> loaded into crane -> unloaded onto track
```
