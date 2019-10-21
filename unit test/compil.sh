#!/bin/bash

if [ "$1" != "quick" ]; then
../setup.sh $1 $2
fi
gcc test.c $lib -lud_utils -lud_memory -lud_string -o executable
./executable