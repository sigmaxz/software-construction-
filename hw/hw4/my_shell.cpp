#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
using namespace std;

char* makec(string s)
{
	char* s1 = new char[s.size()+1];
	for(int i = 0; i < s.size() ; i++)
		s1[i] = s[i];
	s1[s.size()] = '\0';
	return s1;
}

int main(int argc , char* argv[])
{	
	while(1)
	{

	char** cmd = new char*[10];
	pid_t pid;
	int i = 0;
	char* n = '\0';
	string c = "\0";
	cout << "%";
	cin.clear();
		while(cin >> c  )
		{
			char* temp = makec(c);
			cmd[i] = temp;
			i++;
		//	if(c.find('\n')) break;
		}
		if( (pid = fork()) == -1) exit(2);
		if(pid == 0)
		{	cin.clear();
			if((execve(cmd[0],cmd, NULL)) == -1)
				execvp(cmd[0],cmd);
			return 0;
		}
		if(pid > 0)
			i = 0;
		wait(&pid);
	}
	return 0;
}
