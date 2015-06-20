all: iclient.cpp iserver.cpp cserver.cpp cclient.cpp
	g++ -ggdb iclient.cpp -o iclient
	g++ -ggdb iserver.cpp -o iserver
	g++ -ggdb cserver.cpp -o cserver
	g++ -ggdb cclient.cpp -o cclient
iclient: iclient.cpp
	g++ -ggdb iclient.cpp -o iclient
iserver: iserver.cpp
	g++ -ggdb iserver.cpp -o iserver
cserver: cserver.cpp
	g++ -ggdb cserver.cpp -o cserver
cclient: cclient.cpp
	g++ -ggdb cclient.cpp -o cclient
clean:
	rm iclient iserver cserver cclient

