#include "String.h"
//#include <iostream>

using namespace std;

String::String( const char * s )
{
	int l = 0;
	for(;s[l] != '\0';l++);
	buf = new char[l];
	len = l;
	for(int i = 0; i < len ; i++)
		buf[i] = s[i];
	
}

String::String( const String & s)
{
	len = s.len;
	buf = new char[len];
	for( int i = 0; i < len ; i++)
		buf[i] = s.buf[i];
}

String String::operator = ( const String & s)
{
	if(buf)
		delete[] buf;
	len = s.len;
	buf = new char[len];
	for(int i = 0; i < s.len; i++)
		buf[i] = s.buf[i];

	return *this;
}

char & String::operator []( int index)
{
	if(inBounds(index))
		return buf[index];
	cout << "out of bounds\n";
	return buf[0];
}

int String::size()
{
	return len;
}

String String::reverse()
{
	String temp;
	temp.len = len;
	temp.buf = new char[len];
	temp.buf[len-1] = '\0';
	for(int i = len-1 , j = 0 ; j < len ; i-- ,j++)
		temp.buf[j] = buf[i];
	return temp;
}

int String::indexOf(char c )
{
	for(int i = 0; i < len ; i++)
		if(buf[i] == c)
			return i;
	cerr << "index of " << c << " not found in " << *this << endl;
	return -1;
}

int String::indexOf( String pattern)
{
	int temp = indexOf(pattern.buf[0]);
	for(; temp < len; temp++)
	{
		if(buf[temp] == pattern.buf[0] )
		{
			for(int i = 0; i < pattern.len; i++)
			{
				if( buf[temp+i] != pattern.buf[i])
					break;
				if(i+1 >= pattern.len)
				return temp;
			}
		}
	}
	cerr << "pattern " << pattern << " is not found in " << *this << endl;
	return -1;
}

bool String::operator ==( String s)
{
	if(len != s.len)
		return false;
	for(int i = 0 ; i < len; i++)
		if(buf[i] != s.buf[i])
			return false;
	return true;
}

bool String:: operator !=(String s)
{
	return !( *this == s);
}

bool String:: operator >(String s)
{
	if( *this  == s) return false;
	int index = 0;
	for(; this->buf[index] != '\0' && s.buf[index] != '\0' ; index++)
		{
			if( this->buf[index] > s.buf[index]) return true;
			if( this->buf[index] < s.buf[index]) return false;
		}
	if(index == this->len && index != s.len) return true;
	return false;
}

bool String:: operator < (String s)
{
	if(*this == s) return false;
	if( *this > s) return false;
	return true;
}

bool String:: operator >= (String s)
{
	return !( *this < s);
}

bool String:: operator <= (String s)
{
	return ! (*this > s);
}

String String:: operator +( String s) // possible pro with the new
{
	char* temp = new char[len + s.len - 1];
	temp[len + s.len - 2] = '\0';
	for(int i = 0; i < len; i++)
		temp[i] = buf[i];
	for(int j = len , i = 0; i < s.len; j++,i++)
		temp[j] = s.buf[i];
	return String(temp);
}

String String:: operator += (String s)
{
	*this = *this + s;
	return *this;
}

void String::print( ostream & out)
{
	for(int i = 0; i < this->len; i++) // possibly giving null out
		out << this->buf[i];
}	

void String::read( istream & in)
{
	char* temp = new char[2];
	while( in >> temp )
	{
		*this += String(temp);
	}
	delete temp;
}

String::~String()
{
	delete[] buf;
}	

ostream & operator << ( ostream & out, String & str)
{
	str.print(out);
	return out;
}

istream & operator >> ( istream & in , String & str)
{
	str.read(in);
	return in;
}
