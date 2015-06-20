#ifndef COW
#define COW

#include "animal.cpp"
#include <iostream>

using namespace std;

class cow: public animal
{
public:
	cow(int p = 0)
	:animal(p) {}
	virtual void speak()
	{
		cout << "population of :" << getp() <<  " cow(s) say Moo";
	}
};

#endif 
