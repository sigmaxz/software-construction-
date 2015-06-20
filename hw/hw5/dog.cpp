#ifndef DOG
#define DOG

#include "animal.cpp"
#include <iostream>

using namespace std;

class dog: public animal
{
public:
	dog(int p = 0)
	:animal(p) {}
	virtual void speak()
	{
		cout << "population of :" << getp() <<  " dog(s) says woof";
	}
};

#endif 
