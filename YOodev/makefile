all: compile run

compile:
	g++ -I ./include/ -o ./lib/Arraylist.o -c ./src/Arraylist.cpp
	g++ -I ./include/ -o ./lib/Hesaplama.o -c ./src/Hesaplama.cpp
	g++ -I ./include/ -o ./lib/factorial.o -c ./src/Faktoriyel.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Arraylist.o ./lib/Hesaplama.o ./lib/factorial.o   ./src/Test.cpp

run:
	./bin/Test