all: compile

compile:
	gcc -Wall -std=c99 main.c functions.c functions.h myLib.c myLib.h -lm -o run

go: compile
	clear
	./run
