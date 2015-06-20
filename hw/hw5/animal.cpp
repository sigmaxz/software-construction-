#ifndef ANIMAL
#define ANIMAL

#include <iostream>

class animal
{
public:
	int population;
	animal(int p = 0)
	:population(p)
	{}
	virtual void speak() = 0;
	int getp() { return population;}

};

#endif 
