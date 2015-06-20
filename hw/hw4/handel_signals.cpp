#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>


using namespace std;

struct sigaction act;


int i = 0, q = 0, s = 0;

void handt(int num, siginfo_t* info, void* ptr)
{
	if(num == SIGINT)
	{
	if( i < 2)
	{
		i++;
		printf("i DO NOT abort\n");
		return;
	}
	else
	{
		i++;
		printf("Quits:%d",q);
		printf("\n");//	cout << "Quits:" << q << endl;
		printf("Stops:%d",s);
		printf("\n");//cout << "Stops:" << s << endl;
		printf("Interupt:%d",i);
		printf("\n");//cout << "Interupt:" << i << endl;
		cout.flush();
		exit(0);
	}
	}
	if(num == SIGQUIT)
	{
	printf("i DO NOT quit\n");
	q++;
	return;
	}
	if(num == SIGTSTP)
	{
	printf("i Do NOT stop\n");
	s++;
	}
}
	

int main() {

// Turn off output buffering here if you like

//init_signal_handlers();

act.sa_sigaction = handt;
act.sa_flags = SA_SIGINFO;



while (1)
	{
		printf("X");
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGQUIT, &act, NULL);
		sigaction(SIGTSTP, &act, NULL);
		
			cout.flush();
	}
 return 0;
}
