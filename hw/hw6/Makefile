all: Mmain.cpp my_shell.cpp
	g++ -ggdb my_shell.cpp -o my_shell
	g++ -ggdb Mmain.cpp -o Matrix
Matrix: Mmain.cpp
	g++ -ggdb Mmain.cpp -o Matrix
my_shell: my_shell.cpp
	g++ -ggdb my_shell.cpp -o my_shell
#Mmain.o: Mmain.cpp
#	g++ -ggdb -c Mmain.cpp
#Matrix.o: Matrix.h Matrix.cpp
#	g++ -ggdb -c Matrix.cpp
#Array.o: Array.cpp Array.h
#	g++ -ggdb -c Array.cpp
clean: 
	rm Matrix my_shell
