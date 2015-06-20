#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>


using namespace std;

int main()
{
	int pid = fork();
	switch(pid)
	{
		case 0://child client
		{
			sleep(2);
			int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
			if( socket_fd < 0) cerr << "Error opening socket" << endl;
			struct sockaddr_un serv_address;
			bzero((char *) &serv_address, sizeof(serv_address));
			serv_address.sun_family = AF_UNIX;
			char arr[] = "my_server";
			for( int i = 0; i < 9; ++i)
			{
				serv_address.sun_path[i] = arr[i];
			}
			
			if( connect(socket_fd, (const struct sockaddr *) &serv_address, sizeof(serv_address)) < 0 )
				cerr << "Error while connecting" << endl;
			char buf[10];
			if( read(socket_fd, buf, 10) < 0) cerr << "Error while reading" << endl;
			for( int i = 0; i < 9; ++i)
			{
				cout << buf[i];
			}
			cout << endl;
			close(socket_fd);
			exit(0);
			break;
		}



		default://parent server
		{
			int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
			if( socket_fd < 0) cerr << "Error opening socket" << endl;

			struct sockaddr_un serv_address;
			bzero((char *) &serv_address, sizeof(serv_address));
			serv_address.sun_family = AF_UNIX;

			char arr[] = "my_server";
			for( int i = 0; i < 9; ++i)
			{
				serv_address.sun_path[i] = arr[i];
			}

			if( bind(socket_fd, (const struct sockaddr *) &serv_address, sizeof(serv_address) ) < 0)
				cerr << "Error while binding" << endl;

			listen(socket_fd, 5);
			struct sockaddr_un cli_address;
			bzero((char *) &cli_address, sizeof(cli_address));
			socklen_t c_adr = sizeof(cli_address);
			int newsocket_fd = accept(socket_fd, (struct sockaddr *) &cli_address, &c_adr );
			if( newsocket_fd < 0) cerr << "Error on accept" << endl;
			if( write(newsocket_fd, "1 2 3 4 5", 9) < 0) cerr << "Error while writing" << endl;
			wait();
			close(socket_fd);
			unlink(serv_address.sun_path);
		}

	}


	return 0;
}
