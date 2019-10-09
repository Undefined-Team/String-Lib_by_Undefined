#!/bin/bash

if [ -z $1 ]; then
../setup.sh
lib=""
for pparam in "$@"
do
    lib="$pparam $lib"
done
fi
gcc test.c $lib -lud_array -lud_utils -lud_string -lud_memory -o executable
./executable