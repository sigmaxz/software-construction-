#ifndef MYCSTRING_H
#define MYCSTRING_H
#include <iostream>

using namespace std;

int my_strlen(const char* source)
{
	int len = 0;
	for(;source[len] != '\0';len++);
	return len;
}

char* my_strcpy (char* & destination, const char* source)
{
//	if(destination[0] == '\0') delete[] destination;
	int temp = my_strlen(source);
	destination = new char[temp];
	for(int i = 0; i < temp; i++)
		destination[i] = source[i];
	return  destination;
}

char* my_strcat ( char* & destination, const char* source)
{
	if(!source) return destination;
	int temp = my_strlen(destination) + my_strlen(source) -1;
	char* tempc = new char[temp];

	for(int i = 0 ; i < my_strlen(destination) ; i++)
		tempc[i] = destination[i];
	int j = my_strlen(destination);

	for(int i= 0 ; i < my_strlen(source); i++,j++)
		tempc[j] = source[i];
	my_strcpy(destination,tempc);
	return destination;
}

int my_strcmp( const char* str1, const char* str2)
{
	for(int i = 0 ; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if( str1[i] > str2[i]) return 1;
		if( str1[i] < str2[i]) return -1;
	}
	return 0;
}

char* my_strchr( char* str, int character)
{
	for(unsigned i = 0 ; i < my_strlen(str)  ; i++)
	{
		int temp = str[i];
		if( temp == character) return str + i ;
	}
	return '\0';
}

char* my_strstr( char* str1, const char* str2)
{
	for(unsigned i = 0; i < my_strlen(str1); i++)
	{
		if(str1[i] == str2[i])
		{
			int a = my_strlen(str2);
			int k = i;
			bool stop = false;
			for(unsigned j = 0; j < my_strlen(str2); j++)
			{
				if(str1[k] != str2[j] ) 
				{
					stop = true;
					break;
				}
				k++;
			}

			if(!stop) return str1 + k - a ;	
		}
	}

	return NULL;
}
#endif
