#!/usr/bin/env bash
ptxdist clean game
ptxdist compile game
ptxdist targetinstall game
ptxdist image root.romfs
ptxdist test flash-rootfs 
miniterm.py -b 115200 -p /dev/ttyUSB0
