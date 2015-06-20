#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

using namespace std;

struct sigaction act;

pid_t pid;

char* makec(string s)
{
	char* s1 = new char[s.size()+1];
	for(int i = 0; i < s.size() ; i++)
		s1[i] = s[i];
	s1[s.size()] = '\0';
	return s1;
}

void handt(int num, siginfo_t* info, void* ptr)
{
	if(num == SIGINT && pid == 0) return;
	if(num == SIGINT)
		kill(pid, SIGTERM);
	int status = 0;
	if(num == SIGCHLD) waitpid(-1, &status, WNOHANG);
	
	
}

int main(int argc , char* argv[])
{
	act.sa_sigaction = handt;
	act.sa_flags = SA_SIGINFO;
	while(1)
	{

	char** cmd = new char*[10];
	pid = -1;
	int i = 0;
	char* n = '\0';
	string c = "\0";
	char* amp = '\0';
	cout << "%";
	cin.clear();
	while(cin >> c  )
		{
			if(c == "<" || ">" == c) //new
				break;
			if(c == "&")
			{
				amp = makec(c);
				c = -1;
			}
			else 
			{
			char* temp = makec(c);
			cmd[i] = temp;
			i++;
			}
		//	if(c.find('\n')) break;
		}
		char* tempi = NULL;
		char* tempo = NULL;

		if( c == "<" || ">" == c) //new
		{
			while(1)
			{
				if( c == "<" && tempi == NULL)
				{
					cin >> c;
					tempi = makec(c);
				}
				if ( c == ">"&& tempo == NULL)
				{
					cin >> c;
					tempo = makec(c);
				}
				if ( c == "&")
				{
					amp = makec(c);
					break;
				}
				if( cin >> c);
				else  break;
			}
		}
		int in,out;
		if(tempi)
			in = open(tempi, O_RDONLY, S_IREAD);
		if(tempo)
			out = open(tempo, O_WRONLY | O_CREAT | O_TRUNC, S_IWRITE | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP);
		if( (pid = fork()) == -1) exit(2);
		if(pid == 0 && cmd[0])
		{	cin.clear();
		cerr << "sleepy time\n";
		sleep(5);
		cerr << "sleep ends\n";
		if(tempi) dup2(in,0);
		if(tempo) dup2(out,1);
		char* path;
		path = getenv("PATH");
		if(path == NULL) 
		{
			cout << "env error" ;
			exit(0);
		}
		char* temp;
		temp = strtok(path, ":");
		while(temp)
		{
			string z = temp;
			string z2 = "/";
			string z3 = cmd[0];
			z = z + z2 + z3;
			if((execve(makec(z) ,cmd, NULL)) == -1);
			else break;
			temp = strtok( NULL, ":");
		}
				cerr << "failed" << endl;
			return 0;
		
		}
		if(pid == 0) exit(0);
		if(pid > 0)
			i = 0;
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGCHLD, &act, NULL);
		
		if(amp == '\0') wait(&pid);
		if(tempi) close(in);
		if (tempo) close(out);
		cin.clear();

	}
	return 0;
}
