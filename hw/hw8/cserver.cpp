#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/sendfile.h>
#include <stdlib.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std;

//my port
#define PORT 1553
#define MAXDATASIZE 400
#define BL 15

	

int main()
{
	int sockfd, newfd;
	struct sockaddr_in myaddr;
	struct sockaddr_in theiraddr;
	int sin_size;

	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("socket() !");
		exit(1);
	}
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(PORT);
	myaddr.sin_addr.s_addr = INADDR_ANY;


	memset(&(myaddr.sin_zero),0,8);

	if(bind(sockfd,(struct sockaddr *) &myaddr, sizeof(struct sockaddr)) <0)
	{
		perror("bind !");
		exit(1);
	}
	cout << "CSERVER is UP and READY !\n";
//	while(1)
//	{
		if( listen(sockfd,BL) < 0)
		{
			perror("listen !");
			exit(1);
		}
//service
	sin_size = sizeof(struct sockaddr_in);
	if((newfd = accept(sockfd, (struct sockaddr *)&theiraddr, (socklen_t *)&sin_size)) < 0)
	{
		perror("accept !");
		exit(1);
	}
//do the file transfer
	char buf[MAXDATASIZE];
	int rc;
	if((rc = recv(newfd, buf, MAXDATASIZE-1, 0)) < 0)
	{
			perror("recv failed");
			exit(1);
	}
	cout << buf;
	buf[rc] = '\0';
    if (buf[strlen(buf)-1] == '\n')
      buf[strlen(buf)-1] = '\0';
    if (buf[strlen(buf)-1] == '\r')
      buf[strlen(buf)-1] = '\0';
	pid_t pid = fork();
	if(pid == 0)
	{
		int src, dest;
		struct stat stat_buf;
		off_t offs = 0;
		src = open(buf, O_RDONLY);
		if(src == -1)
		{
			perror("src ");
			exit(1);
		}
		fstat(src,&stat_buf);
		if((sendfile(newfd,src, &offs, stat_buf.st_size)) < 0)
		{
			perror("sendfile() ");
			exit(1);
		}
		return 0;
	}
	else
	{
		shutdown(newfd, 2);
		close(newfd);
		close(sockfd);
	}
//	}
return 0;
}

