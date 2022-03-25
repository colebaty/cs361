# Space Station

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