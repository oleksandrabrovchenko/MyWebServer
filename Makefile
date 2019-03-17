all: hello

hello:  test.o cards.o 
	g++ -std=c++11 test.o cards.o -o hello_alex -s -static -pthread

test.o: test.cpp
	g++ -std=c++11 -c test.cpp

cards.o: cards.cpp
	 g++ -std=c++11 -c cards.cpp

clean:
	rm -rf *.o hello

install:
	cp hello_alex.exe C:\Apache24\cgi-bin\