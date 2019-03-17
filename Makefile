all: hello

hello:  test.o cards.o 
	g++ -std=c++11 test.o cards.o -o hello_alex -s -pthread -lpthread

test.o: test.cpp
	g++ -std=c++11 -c test.cpp -pthread -lpthread

cards.o: cards.cpp
	 g++ -std=c++11 -c cards.cpp -pthread -lpthread

clean:
	rm -rf *.o hello

install:
	cp hello_alex.exe C:\Apache24\cgi-bin\