# Space Station

## NOTES

I am deliberately turning this in unfinished - I just don't have the time and I'm
confident that what I'm submitting demonstrates my knowledge of the concepts.

The `main` program is very sparse, and not really worth looking into.

The bulk of the work will be in the testing files.

Please use `make` to run test files:

```bash
$ make TARGET=<cpp test file without extension>

#example

$ make TARGET=moduleTest
```

### Noteworthy tests

- `dataFileTest2.cpp`: creates four modules, moves them, and then completes
the requisite steps to draw it to the output file `output2.png` using `gnuplot`
- `rotationTest.cpp`: this test is unfinished. The idea was to determine which 
walls of a source and target were available for connection, and then rotate the
*source* module (i.e. the unconnected module) so that it was in the proper 
orientation to make the connection. Then, align the appropriate corners, and figure
out where to place the remaining corners, update the walls, etc. I got as far as
aligning corners of the connecting walls.

## Description

A menu-driven application for building, arranging, and drawing a space station.

The space station is composed of modules, which can be attached according to certain rules.

The base module is a 5x5 hallway type, from which all other module types are derived.

User will have ability to
- create new modules and add them to the space station
- save and load space station configurations for later retreival
- draw the space station from a top-down view using `gnuplot`

## Conventions

### Connections

- Connections are assumed to be made *from* an unattached `src` module *to* an attached `dst` module (except the very first module, obviously).
- Positive angles are measured counter-clockwise


### Orientation

There are two frames of reference for orientation: statiton-north and module-north.

Station-north is simply the "north" heading of the first-placed module.

Module-north is the heading of the north-facing wall of any given module; that is,
on an x-y plane (top-down view), module-north is the positive x-axis, 90º from due East.
In other words, the heading is a unit vector normal to the (imagined) 3-D plane
that represents the North wall.

While station-north can be any arbitrary heading, module-north values will be
at 0º, 90º, 180º, and 270º angles relative to station-north.


## `module::align`

Automatically handles module alignment.

Walls represented as pseudo-vectors, so computing dot- and cross-products to 
obtain headings should be trivial.  With these headings, a rotation matrix can
be applied to compute the desired headings