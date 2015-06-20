all: freq.cpp oddOrEven.cpp
	g++ -ggdb freq.cpp -o freq
	g++ -ggdb oddOrEven.cpp -o OorE

OorE: oddOrEven.cpp
	g++ -ggdb oddOrEven.cpp -o OorE

freq: freq.cpp
	g++ -ggdb freq.cpp -o freq

clean: 
	rm freq OorE
