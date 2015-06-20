SOURCES = String.cpp testString.cpp handel_signals.cpp my_shell.cpp
HEADERS = String.h 
OBJECTS = String.o testString.o
CXX = g++
FLAGS = -ggdb
EXE = String handel_signals my_shell
ALL: $(0BJECTS) $(SOURCES) $(HEADERS) 
	$(CXX) $(FLAGS) String.cpp String.h testString.cpp -o String
	$(CXX) $(FLAGS) handel_signals.cpp -o handel_signals
	$(CXX) $(FLAGS) my_shell.cpp -o my_shell

shell: my_shell.cpp
	$(CXX) $(FLAGS) my_shell.cpp -o my_shell

handel: handel_signals.cpp
	$(CXX) $(FLAGS) handel_signals.cpp -o handel_signals

String: String.o testString.o
	$(CXX) $(FlAGS) String.o testString.o -o String

String.o: String.h String.cpp
	$(CXX) $(FLAGS) -c String.h String.cpp 

testString.o: testString.cpp
	$(CXX) $(FLAGS) -c testString.cpp 

clean:
	rm $(EXE)
	rm $(OBJECTS)

Strip:
	strip String

print: String.h String.cpp testString.cpp
	less String.h String.cpp testString.cpp 



