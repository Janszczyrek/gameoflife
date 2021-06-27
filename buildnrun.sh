#!/bin/bash
g++ -c life.cpp
g++ life.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app 