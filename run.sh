#!/bin/bash

mkdir build && cd build && cmake .. && make && mv mySolitaire.exe ../ && cd .. && ./mySolitaire.exe && rm -r build

#EOF