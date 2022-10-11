CC = g++
FLAGS = -g -Wall -std=c++17
LINK_SFML = `pkg-config --cflags --libs sfml-all`
OUT = -o bin/liberty_space_invaders_C64

SOURCE_FILES = src/main.cpp src/game.cpp

build:
	$(CC) $(FLAGS) $(SOURCE_FILES) $(LINK_SFML) $(OUT)

test:
	echo TBD