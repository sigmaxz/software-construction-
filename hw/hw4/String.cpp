#include "String.h"
#include <iostream>

using namespace std;

String::String(const char* s)
{
	if(s[0] == '\0')
	{
	 head = NULL;
	 return;
	}
	ListNode* temp = NULL;
	head = new ListNode(s[0],NULL);
	temp = head;
	for(int i = 1; s[i] != '\0' ; i++)
	{
		temp->next = new ListNode(s[i], NULL);
		temp = temp->next;
	}
}

String::String( const String & s)
{
	if(s.head == NULL){ 
		head = NULL;
		return;
	}
	ListNode* temp;
	ListNode* temp2 = s.head;
  head = new ListNode(temp2->info,NULL);
  temp = head;
  temp2 = temp2->next;
	while(temp2)
	{
		temp->next = new ListNode(temp2->info,NULL);
		temp = temp->next;
		temp2 = temp2->next;
	}
}

String String::operator =(const String & s)
{
	if(head != NULL) this->~String();
	if(s.head == NULL){ 
		head = NULL;
		return *this;
	}
  ListNode* temp = NULL;
	ListNode* temp2 = s.head;
  head = new ListNode(temp2->info,NULL);
  temp = head;
  temp2 = temp2->next;
	while(temp2)
	{
		temp->next = new ListNode(temp2->info,NULL);
		temp = temp->next;
		temp2 = temp2->next;
	}
  return *this;
}

char & String::operator [](const int index)
{
	if(!inBounds(index)){
		cerr<< index << " not inbound " << endl;
		 return (*this)[0];
	}
	ListNode* temp = head;
	for(size_t i = 0; i < index; i++)
		temp = temp->next;
	return temp->info;
}

int String::length() const
{
	ListNode* temp = head;
	int i = 0;
	for(; temp; i++)
		temp = temp->next;
	return i;
}

int String::indexOf(char c) const
{
	ListNode* temp = head;
	for(int i = 0; temp; i++)
	{
		if(temp->info == c) return i;
		temp = temp->next;
	}
	cerr << c << " not found returning -1" << endl;
	return -1;
}

bool String::operator ==( const String & s) const
{
	if(length() != s.length()) return false;
	ListNode* temp = head;
	ListNode* temp2 = s.head;
	while(temp && temp2)
	{
		if(temp->info != temp2->info) return false;
		temp = temp->next;
		temp2 = temp2->next;
	}
	return true;
}

String String::operator +(const String & s) const
{
	int len = s.length();
	len += length();
	char* buf = new char[len];
	ListNode* temp = head;
	for(int i = 0; i < length(); i++)
	{
		buf[i] = temp->info;
		temp = temp->next;
	}
	temp = s.head;
	for(int i = 0, j =length(); i < s.length(); i++, j++)
	{
		buf[j] = temp->info;
		temp = temp->next;
	}
	String temp1(buf);
	delete[] buf;
	return temp1;
}

String String::operator +=(const String & s)
{
	(*this) = (*this) + s;
	return *this;
}

void String:: print(ostream & out)
{
  if (head == NULL) return;
	ListNode* temp = head;
	while(temp)
	{
		cout << temp->info;
		temp = temp->next;
	}
}

void String:: read(istream & in)
{
	char* buf = new char[2];
	while(in >> buf)
  {
		*this += String(buf);
	}
}

String::~String()
{
  if(head == NULL) return;
	ListNode* temp = head;
	ListNode* temp2;
	while(temp)
	{
		temp2 = temp;
		temp = temp->next;
		delete temp2;
	}
}
	
ostream & operator << (ostream & out , String & str)
{
	str.print(out);
	 return out;
}

istream & operator >> (istream & in, String & str)
{
	str.read(in);
	return in;
}

