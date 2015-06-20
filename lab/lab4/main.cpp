#include "myCString.h"
#include <iostream>

using namespace std;

int main()
{
	char* a = "hi";
	char* b = "bye";
	cout << " a contains :" << a << endl;
	cout << " a len :" << my_strlen(a) << endl;
	cout << " b len :" << my_strlen(b) << endl;

	char* c;
	my_strcpy(c,a);
	cout << "c contains :" << c << endl;
	my_strcpy(c,b);
	cout << "c now contains :" << c << endl;

	my_strcat(c,a);
	cout << "c is cat a : " << c << endl;
	my_strcat(c,b);
	cout << "c is cat b : " << c << endl;

	cout << "zero due to a being equal to a :" << my_strcmp(a,a);
	cout << "\n 1 if a < c :" << my_strcmp(a,c);
	cout << "\n -1 if a > c :" << my_strcmp(c,a) << endl;
    char* d = "dog goes out today";
	cout << "\ntest string is: " << d << endl;
	char* pch = my_strchr(d,'e');
	cout <<" index num of \'e\': " <<  pch - d + 1  << endl;
    pch = my_strchr(pch + 1 ,'s');
	cout <<" index num of \'s\': " <<  pch - d + 1  << endl;
	pch = my_strchr(pch+1, 'q');
	if(pch == '\0') cout << "CHAR NOT FOUND! " << endl;

  	char str[] ="This is a simple string";
  	char * pch2;
  	pch2 = my_strstr (str,"simple");
   	cout << pch2 << endl;
///	char* temp = my_strstr(str,"zz");
	
return 0;
}	
