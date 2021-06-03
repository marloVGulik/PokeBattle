#!/bin/bash

function pause() {
	read -p "$*"
}

while :
do
	clear
	echo "Compiling program..."
	g++ src/main.cpp -o bin/PB

	pause "Done compiling! Press enter to do it again."
done
