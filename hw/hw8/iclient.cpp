#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define PORT 1552
#define MAXDATASIZE 400

int main(int argc, char *argv[])
{
	int sockfd, numb;
	char buf[MAXDATASIZE];
	strcpy(buf,argv[2]);
	struct hostent *he;
	struct sockaddr_in theiraddr;
	if(argc != 3)
	{
		perror("Client usage: must give 2 argument for hostname/path");
		exit(1);
	}

	if( (he = gethostbyname(argv[1])) == NULL)
	{
		perror("gethostname()");
		exit(1);
	}
	else
		printf("the remote host is %s", argv[1]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0 )
	{
		perror("socket()");
		exit(1);
	}
	theiraddr.sin_family = AF_INET;
	theiraddr.sin_port = htons(PORT);
	theiraddr.sin_addr = *((struct in_addr *)he->h_addr);
	memset(&(theiraddr.sin_zero), '\0', 8);

	if(connect(sockfd, (struct sockaddr *)&theiraddr, sizeof (struct sockaddr)) == -1)
	{
		perror("connect()");
		exit(1);
	}

	if((numb = send(sockfd,buf, MAXDATASIZE -1, 0)) == -1)
	{
		perror("send()");
		exit(1);
	}
	while( read(sockfd,buf,400))
	{
		cout << buf;
	}
	cout << "\ndone reading\n";
	close(sockfd);
	return 0;
}

