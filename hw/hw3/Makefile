EXE: String fork filemain
OBJECTS: String.o testString.o fork.o filemain.o
SOUCRCES: String.cpp testString.cpp fork.cpp filemain.cpp
HEADERS: String.h Timer.h
CXX: g++
FLAGS: -g

all: String.cpp testString.cpp 
	g++ -g String.cpp testString.cpp -o String 
	$(CXX) $(FLAGS) fork.cpp -o fork
	$(CXX) $(FLAGS) filemain.cpp Timer.h -o filemain

filemain: filemain.o Timer.h
	$(CXX) $(FLAGS) filemain.cpp Timer.h -o filemain

filemain.o: filemain.cpp
	$(CXX) $(FLAGS) -c filemain.cpp

fork: fork.cpp
	$(CXX) $(FLAGS) fork.cpp -o fork

fork.o: fork.cpp
	$(CXX) $(FLAGS) -c fork.cpp

String: String.o testString.o
	$(CXX) $(FLAGS) -o String String.o testString.o

String.o: String.cpp String.h
	$(CXX) $(FLAGS) -c String.cpp String.h

testString.o: testString.cpp
	$(CXX) $(FLAGS) -c testString.cpp

clean:
	rm String fork filemain
