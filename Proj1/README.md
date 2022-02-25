# Shipyard: Phase 2 Deliverable - CS 360 with Prof. Jay D. Morris

by Cole Baty, UIN 01187002, tbaty002@odu.edu

## Compiling and Running

Running the command `make` will produce an executable file named `main`.

Included in the `.zip` fle is a file named `in`, which simply contains the character
`y` many times (captured by piping the output of `yes` run for approximately 1 second).
It is therefore possible to automatically supply an affirmative answer at the 
prompt to continue which occurs every ten timesteps by running the command

```bash
./main < in | less
```

The pipe to `less` will capture the output in the pager, allowing you to
examine the results in more detail.

## Notes

This project was tested on the ODU CS Linux servers on Feb 24, 2022, and it 
behaved as expected.

This program increments in timesteps of 10, prompting the user to continue after
every 10 timesteps.  The program terminates when all `switchTrack`s are full.

### `shipTrack`

Assignment instructions specified that the `shipTrack`s should have a maximum
capacity of 100, and an unspecified depart time.

I chose to implement the depart time like the ICMP 'time to live' or TTL parameter.
I chose a default TTL of 20 for each train, based on the best-case scenario of 
all five `switchTrack`s unloading one container per timestep to any given `shipTrack`;
i.e. 100 / 5 = 20.

However, during testing with the prescribed `shipTrack` parameters, I found that 
the `switchTrack`s would fill (and thus terminate the program) before any train
had a chance to depart. 

Therefore, I recommend changing the values of the constants found in `shipTrack.h`
as follows:

- `SHIPTRACK_TTL = 20`
- `SHIPTRACK_CAP = 20`

Compiled with these values, I found trains were departing with more frequency.

### `crane`

By default, `crane`s 1, 4, 7, and 8 are pre-loaded with `container`s, in order
to better simulate in-progress unloading. Commenting out line 53 will prevent this.

### `ship`

The cargo hold of a `ship` is a 2D vector of stacks. `ship::getNext()` will 
retrieve the element at `_cargo[0][0]` until there are no more containers in the hold.
To me, this was the most straightforward way of drawing containers from the cargo hold,
since vectors and stacks keep track of themselves.