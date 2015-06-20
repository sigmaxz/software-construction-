#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "Timer.h" 

using namespace std;

void gets(ifstream & i, ofstream & o)
{
	char c;
	while(i.good())
	{
		i.get(c);
		o << c;
	}
}

void rw( char* & a, char* & b)
{
	int f,f2,n,n2;
	int size = sizeof(char);
	char c[1];
	f = open(a, O_RDONLY , S_IREAD);
	f2 = open(b,O_WRONLY, S_IWRITE);
	while( (n = read(f,c,size))>0)
		n2 = write(f2,c,size);
	close(f);
	close(f2);

}

void brw( char* & a, char* & b)
{
	int f,f2,n;
	int size = BUFSIZ;
	char c[size];
	f = open(a, O_RDONLY , S_IREAD);
	f2 = open(b, O_WRONLY, S_IWRITE);
	if( (n = read(f,c,size)) >0)
		write(f2,c,n);
	close(f);
	close(f2);

}



int main(int argc,char* argv[])
{
	char* a = argv[1];
	char* b = argv[2];
	int num = atoi(argv[3]);
	ifstream input;
	ofstream output;
	input.open(a);
	output.open(b);
	
	Timer t;
	double time,time2,time3;
	t.start();
	for(int i = 0; i < num ; i++)
		gets(input,output);
	t.elapsedWallclockTime(time);
	t.elapsedUserTime(time2);
	t.elapsedSystemTime(time3);
	cout << "using get char took wall:" << time << " user:" << time2;
	cout << " system:" << time3 << endl;

	input.close();
	output.close();

	Timer t2;
	for(int i = 0; i < num; i++)
		rw(a,b);
	t2.elapsedWallclockTime(time);
	t2.elapsedUserTime(time2);
	t2.elapsedSystemTime(time3);
	cout << "using read char took wall:" << time << " user:" << time2;
	cout << " system:" << time3 << endl;

	Timer t3;
	for(int i = 0; i < num; i++)
		brw(a,b);
	t3.elapsedWallclockTime(time);
	t3.elapsedUserTime(time2);
	t3.elapsedSystemTime(time3);
	cout << "using read buf took wall:" << time << " user:" << time2;
	cout << " system:" << time3 << endl;


	return 0;
}
