#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main()
{
	pid_t p = fork();
	if( p == 0)
	{
		cout << "pid";
		cout.flush();
		char* buf[] = {"ls","-l","/bin"};
	char* args = {"/bin/ls"};
	execvp(args, buf);
	}
	int stat;
	waitpid(p,&stat,0);
	cout << "main";
	cout.flush();
return 0;
}

