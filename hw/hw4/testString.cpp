#include "String.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "constructing a variable s which contains HELLO and printing\n";
	char* buf = "HELLO";
	String s(buf);
	cout << s;
	cout << " length: " << s.length() << endl;
	cout << "using default on variable e and printing now :";
	String e;
	cout << e << "done e has been printed " << endl;
	cout << "e length : " << e.length() << endl;
	cout << "using assignment operator to make copy of s and printing :";
	String s2 = s ;
	cout << s2 << endl;
	cout << "using assignment operator to make copy of e and printing now:";
	String ecopy(e);
	cout << ecopy << "done printing" << endl;
	cout << "making a copy of s2 in s3 with 2nd constructor and printing:";
	String s3(s2);
	cout << s3 << endl;
	cout << "using empty e with assignment to equal s and printing :";
	e = s;
	cout << e << endl;
	cout << "printing index 0 of s :";
	cout << s[0] << endl;
	cout << "printing index 4 of s(should be O) :";
	cout << s[4] << endl;
	cout << "printing index 5 of s should be out of bonds and return 0 :";
	cout << s[5] << endl;
	
	cout << "finding index of H and printing :";
	int index = s.indexOf('H');
	cout << index << endl;
	cout << "finding index of O and printing :";
	index = s.indexOf('O');
	cout << index << endl;
	cout << "finding index of z(not found) :";
	index = s.indexOf('z');
	cout << index << endl;


	cout << "using += on s itself then printing :";
	s += s;
	cout << s << endl;
	cout << "testing read insert some input :";
	String read;
	cin >> read;
	cout << endl << read << endl; 
	return 0;
}
