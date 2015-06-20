#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

const int TIMES = 10000;

int main()
{
	pid_t pid = 0;
	pid = fork();
	if(pid > 0)
	{
		cout << " i am child:" << pid << endl;
		cout.flush();
	}
		//
	pid_t pid2 = 0;
	if(pid > 0)
		pid2 = fork();
	if(pid2> 0)
	{
		cout << " i am child:" << pid2 << endl;
		cout.flush();
	}
		//
	pid_t pid3 = 0;
	if(pid2 > 0 && pid >0)
		pid3 = fork();
	if(pid3 > 0)
	{
		cout << " i am child:" << pid3 << endl;
		cout.flush();
	}
		//
	if( pid > 0 && pid2 > 0 && pid3 > 0 )
	{
		for(int i = 0; i < TIMES; i++)
		{
			cout << "a";
			cout.flush();
		}
	}
	if(pid == 0)
	{
		for(int i = 0; i < TIMES; i++)
		{
			cout << "b";
			cout.flush();
		}
	}
	if(pid2 == 0)
	{
		for(int i = 0; i < TIMES; i++)
		{
			cout << "c";
			cout.flush();
		}
		return 0;
	}
	if(pid3 == 0)
	{
		for(int i = 0; i < TIMES; i++)
		{
			cout << "d";
			cout.flush();
		}

		return 0;
	}


	pid_t child1 = wait(&pid);
	pid_t child2 = wait(&pid2);
	pid_t child3 = wait(&pid3);

	return 0;
}
