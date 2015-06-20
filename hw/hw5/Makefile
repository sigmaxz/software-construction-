SOURCE= animal.cpp duck.cpp dog.cpp cow.cpp mainp.cpp my_shell.cpp 
HEADERS=
OBJECTS= duck.o cow.o dog.o animal.o mainp.o my_shell.o
EXE= abprog my_shell
CXX= g++
FLAGS= -ggdb

abprog: mainp.o duck.o dog.o cow.o animal.o 
	$(CXX) $(FLAGS) mainp.o duck.o dog.o cow.o animal.o -o abprog
mainp.o: mainp.cpp
	$(CXX) $(FLAGS) -c mainp.cpp
duck.o: duck.cpp
	$(CXX) $(FLAGS) -c duck.cpp
dog.o: dog.cpp
	$(CXX) $(FLAGS) -c dog.cpp
cow.o: cow.cpp
	$(CXX) $(FLAGS) -c cow.cpp

animal.o: animal.cpp
	$(CXX) $(FLAGS) -c animal.cpp

my_shell: my_shell.o
	$(CXX) $(FLAGS) my_shell.o -o my_shell

my_shell.o: my_shell.cpp
	$(CXX) $(FLAGS) my_shell.cpp -c
clean:
	rm $(OBJECTS)
	rm $(EXE)

strip: my_shell
	strip my_shell

print: 
	cat $(SOURCE) | lpr
	cat $(HEADERS) | lpr
