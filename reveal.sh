#!/usr/bin/env bash

NAME="hardware-hackathon-talk"

docker run --rm --name $NAME -d  -p 8000:1948 -v $PWD:/usr/src/app containersol/reveal-md
