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