data-structures-and-algorithms-cpp
==================================

Data structures and algorithms in C++ for learning.

This code should not be used in a production, for simplicity I am not using templates for the data structures, and there is a relatively large amount of undefined behavior (ie. removing an element from an empty list).

# Install Instructions

Instructions tested on Ubuntu 14.04

Requires cmake and a compiler

```
sudo apt-get install cmake build-essential
```

Uses Google Mock and Google Test
https://code.google.com/p/googlemock/

Requires gcc 4.7 or above (note that if you are using ubuntu 12.04 the version in the repositories is from the 4.6 branch, you will need a newer version).

Download Google Mock from the above link

Add an environment variable to where it is installed, I used

```
export GMOCK_HOME=$HOME/bin/gmock-1.7.0
```

Build Google Mock
The mybuild directory is arbitrary, but the build scripts used in this repo assume that name. If you wish to change it, you will also need to change all the CMakeLists.txt files

```
cd $GMOCK_HOME
mkdir mybuild
cd mybuild
cmake ...
make
```

Build Google Test

```
cd cd $GMOCK_HOME/gtest
mkdir mybuild
cd mybuild
cmake ..
make
```

# Build the project

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Run the Unit tests:

```
$ ./test
```
