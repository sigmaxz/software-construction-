#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;


//my port
#define PORT 1552
#define MAXDATASIZE 400
#define BL 5

int main()
{
	int sockfd, newfd;
	struct sockaddr_in myaddr;
	struct sockaddr_in their_addr;
	int sin_size;

	if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		perror("socket() error!");
		exit(1);
	}

	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(PORT);
	myaddr.sin_addr.s_addr = INADDR_ANY;
	
	memset(&(myaddr.sin_zero),0, 8);

	if(bind(sockfd, (struct sockaddr *) &myaddr, sizeof(struct sockaddr)) == -1)
	{
		perror("bind() error !");
		exit(1);
	}
	cout << "SERVER is UP and READY!\n";
	if(listen(sockfd,BL) == -1)
	{
		perror("listen() error !");
		exit(1);
	}

	sin_size = sizeof(struct sockaddr_in);
	if((newfd = accept(sockfd, (struct sockaddr *)&their_addr, (socklen_t *)&sin_size)) < 0)
	{
		perror("accept() error !");
		exit(1);
	}

//do the ls part
	char buf[MAXDATASIZE];
	if(recv(newfd, buf, MAXDATASIZE-1, 0)< 0)
	{
		perror("recv failed");
		exit(1);
	}
	pid_t pid;
	pid = fork();
	if( pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)
	{
		dup2(newfd,1);
		char* bufq[4] = {"ls","-l"};
		bufq[2] = buf;
		bufq[3] = '\0';
		char* args = {"/bin/ls"};
		execvp(args, bufq);
		exit(0);
	}
	int stat;
	waitpid(pid,&stat,0);

	
	/*while(fgets(buf,400, stdout ) != NULL)
	{
	 	if(write(newfd, buf , MAXDATASIZE-1) < 0)
		{
		perror("send() error !");
		exit(1);
		}
	}*/
	

	shutdown(newfd, SHUT_RDWR);
	close(newfd);
	close(sockfd);
	return 0;
}
