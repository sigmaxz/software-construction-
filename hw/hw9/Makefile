all: client.cpp server.cpp perserver.cpp poolserver.cpp flserver.cpp
	g++ client.cpp -lpthread -o client
	g++ server.cpp -lpthread -o server
	g++ perserver.cpp -lpthread -o perserver
	g++ poolserver.cpp -lpthread -o poolserver
	g++ flserver.cpp -lpthread -o flserver
cli: client.cpp
	g++ client.cpp -lpthread -o client
ser: server.cpp 
	g++ server.cpp -lpthread -o server
per: perserver.cpp
	g++ perserver.cpp -lpthread -o perserver
pool: poolserver.cpp
	g++ poolserver.cpp -lpthread -o poolserver
fl: flserver.cpp
	g++ flserver.cpp -lpthread -o flserver
clean:
	rm -R Thread* 
	rm client server poolserver perserver flserver
