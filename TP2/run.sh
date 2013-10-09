#!/bin/bash

rm -r build ; mkdir build && cd build && cmake .. && make && mv air-GLOIFT.exe ../ && cd .. && ./air-GLOIFT.exe && rm -r build

#EOF