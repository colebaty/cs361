# Shipyard simulation

Simulating a working shipyard, a la Pourtsmouth Shipyard. Loaded container ships 
dock with the port.  Cranes unload the containers from the ships and place them
onto one of a number of switching tracks. Containers are moved from switching
tracks to a shipping track associated with the container's destination code.

If the container at the head of the switching track has no match for its destination
code on the shipping tracks, that container is pushed onto a "siding" track associated
with switching track.

Once the shipping train is full, or else enough time has passed, the train departs
for its desination, and another empty train with a new destination code takes its
place.

## Quantities

- cranes: 9
- switch/side tracks: 5
- shipping tracks: 4
- minimum containers per ship: 750
- maximum containers per ship: 1000

# Ship class

Collection of containers: 3-d array or vector

## 3D array
```cpp
container contents[10][40][4]; //static implementation
container ***contents; //dynamic implementation
```

## 3D vector
```cpp
vector<vector<vector<container>>> contents; //vector of layers; each layer is a vector of vectors

vector<container> row;
vector<row> layer;
vector<layer> contents;
```

# crane class

load unload algorithm
```cpp
//ship docks; begin unloading
//crane loads container
    //while ship not empty
        //if any switching track has space
            //crane n loads any container from top-level stack
            //if any switching track has space
                //crane n unloads container to next available switching track
            //crane finds next container
        //else wait for free switching track
```