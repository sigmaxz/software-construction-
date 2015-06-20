#ifndef DUCK
#define DUCK

#include "animal.cpp"
#include <iostream>

using namespace std;

class duck: public animal
{
public:
	duck(int p = 0)
	:animal(p) {}
	virtual void speak()
	{
		cout << "population of :" << getp() << " duck(s) say quack";
	}
};

#endif 
