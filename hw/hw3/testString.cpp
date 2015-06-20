#include "String.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "constructing a variable s which contains HELLO and printing\n";
	String s = "HELLO";
	cout << s << " size: " << s.size() << endl;
	cout << "using default on variable e and printing now :";
	String e;
	cout << e << "done e has been printed " << endl;
	cout << "e size : " << e.size() << endl;
	cout << "using assignment operator to make copy of s and printing :";
	String s2 = s;
	cout << s2 << endl;
	cout << "using assignment operator to make copy of s and printing now:";
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
	cout << "making String r a reverse if s and printing :";
	String r = s.reverse();
	cout << r << endl;
	cout << "reversing r back to match s and printing :";
	r = r.reverse();
	cout << r << endl;

	cout << "finding index of H and printing :";
	int index = s.indexOf('H');
	cout << index << endl;
	cout << "finding index of O and printing :";
	index = s.indexOf('O');
	cout << index << endl;
	cout << "finding index of z(not found) :";
	index = s.indexOf('z');
	cout << index << endl;

	cout << "finding pattern HE in s :";
	String pat = "HE";
	index = s.indexOf(pat);
	cout << index << endl;
	cout << "finding pattern LO in s :" ;
	String pat2 = "LO";
	index = s.indexOf(pat2);
	cout << index << endl;
	cout << "finding pattern as(no found) in s :" ;
	String pat3 = "as";
	index = s.indexOf(pat3);
	cout << index << endl;

	if( s == s) cout << " s is equal to s" << endl;
	if( s != pat3) cout << "s is not equal to pat3" << endl;
	if( pat3 > s) cout << "pat3 is greater than s" << endl;
	if( s < pat3) cout << " s is less than pat3 " << endl;
	if( s >= s) cout << " s is greater than or equal to s" << endl;
	if( pat3 >= s) cout << " pat3 is greater than or equal to s" << endl;
	if ( s <= s) cout << " s is less than or equal to s " << endl;
	if(s <= pat3) cout << "s is less than or equal to pat3 " << endl;
	cout << "using s + s and storing in pat then printing :";
	pat = s + s;
	cout << pat << endl;
	cout << "using += on pat itself then printing :";
	pat += pat;
	cout << pat << endl;
	cout << "testing read insert some input :";
	String read;
	cin >> read;
	cout << endl << read << endl;
	return 0;
}
