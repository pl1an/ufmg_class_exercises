all: list.o main.o link

list.o: src/list.cpp
	g++ -c src/list.cpp -o build/list.o

main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o

link: list.o main.o
	g++ -o vpl_execution build/main.o build/list.o

