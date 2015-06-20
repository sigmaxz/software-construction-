SOURCES = main.cc Coins.cc betterMain.cc bestMain.cc my_ls.cc
OBJECTS = main.o betterMain.o bestMain.o my_ls.o Coins.o
HEADERS = Coins.h
CXX = g++
CXXFLAGE = -ggdb 

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(SOURCES) $(HEADERS)

Coins.o: Coins.cc Coins.h
	$(CXX) $(CXXFLAGS) -c Coins.cc
main.o: main.cc
	$(CXX) $(CXXFLAGS)-c main.cc 

main: main.o Coins.o; touch main.o
	$(CXX) $(CXXFLAGS) main.o Coins.o -o main

betterMain.o: betterMain.cc 
	$(CXX) $(CXXFLAGS) -c betterMain.cc  

better: betterMain.o Coins.o ; touch betterMain.o
	$(CXX) $(CXXFLAGS) betterMain.o Coins.o -o better

bestMain.o: bestMain.cc 
	$(CXX) $(CXXFLAGS) -c bestMain.cc

best: bestMain.o Coins.o ; touch bestMain.o 
	$(CXX) $(CXXFLAGS) bestMain.o Coins.o -o best

my_ls: my_ls.cc
	$(CXX) $(CXXFLAGS) my_ls.cc -o myls

clean:
	rm *.o

