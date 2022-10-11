#!/bin/sh

apt update -y

# install needed build tools (g++, make, pkg-config)
apt install build-essential pkg-config -y

# install SFML
apt install libsfml-audio2.5 libsfml-dev libsfml-graphics2.5 libsfml-network2.5 libsfml-system2.5 libsfml-window2.5 -y
