data-structures-and-algorithms-cpp
==================================

Data structures and algorithms in C++ for learning.

## Install Dependencies

Requires cmake and a compiler

```
brew install cmake
```

Uses Google Test
https://github.com/google/googletest

Download Google Test from the above link

Add an environment variable to where it is installed, I used

```
export GTEST_HOME=$HOME/bin/googletest-release-1.10.0
```

Build Google Mock
The mybuild directory is arbitrary, but the build scripts used in this repo assume that name. If you wish to change it, you will also need to change all the CMakeLists.txt files


Build Google Test

```
cd $GTEST_HOME
mkdir mybuild
cd mybuild
cmake -DCMAKE_CXX_FLAGS=-std=c++11 ..
make

# On MacOS do this:
cp -a ../googletest/include/ /usr/local/include
cp -a ../googlemock/include/ /usr/local/include
find . -name "*.a" -exec cp -a {} /usr/local/lib \;

export CPLUS_INCLUDE_PATH=/usr/local/include
export LIBRARY_PATH=/usr/local/lib
```

## Build the project

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Run the Unit tests:

```
$ ./test
```
