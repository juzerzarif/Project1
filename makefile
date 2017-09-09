Project1: exec.o node.o linkedList.o date.o
	g++ -std=c++11 -g -Wall exec.o node.o linkedList.o date.o -o Project1

exec.o: exec.hpp linkedList.h date.h
	g++ -std=c++11 -g -Wall -c exec.hpp

node.o: node.h node.hpp 
	g++ -std=c++11 -g -Wall -c node.hpp

linkedList.o: linkedList.h linkedList.hpp node.h
	g++ -std=c++11 -g -Wall -c linkedList.hpp

date.o: date.h date.hpp
	g++ -std=c++11 -g -Wall -c date.hpp

clean:
	rm *.o Project1
