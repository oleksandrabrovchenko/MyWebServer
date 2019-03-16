all: hello

hello:  test.o cards.o 
	g++ test.o cards.o -o hello_alex -s -static

test.o: test.cpp
	g++ -c test.cpp

cards.o: cards.cpp
	 g++ -c cards.cpp

clean:
	rm -rf *.o hello

install:
	cp hello_alex.exe C:\Apache24\cgi-bin\