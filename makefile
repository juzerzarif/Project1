Project1: main.o
	g++ -std=c++11 -g -Wall -o Project1 main.o

main.o: exec.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o Project1
