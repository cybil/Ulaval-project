#!/bin/bash

rm -r build ; mkdir build && cd build && cmake .. && make && mv mySolitaire.exe ../ && cd .. && ./mySolitaire.exe && rm -r build

#EOF