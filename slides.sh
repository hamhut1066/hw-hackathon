#!/usr/bin/env bash

NAME="hardware-hackathon-talk"

docker exec -it $NAME reveal-md arduino/slides.md  --theme cs --static docs
