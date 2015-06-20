#include "dog.cpp"
#include "animal.cpp"
#include "duck.cpp"
#include "cow.cpp"
#include <iostream>

using namespace std;

void polyfunc(animal** a, int num)
{
	for(int i = 0 ; i < num ; i++)
		(a[i])->speak() , cout << endl;

}

int main()
{
	dog d(1);
	dog d2(4);
	dog d3(10);
	duck du(1);
	duck du2(5);
	duck du3(30);
	cow c(30);
	cow c2(50);
	cow c3(133);
	
	animal** ap = new animal*[9];
	ap[0] = &d;
	ap[1] = &d2;
	ap[2] = &d3;
	ap[3] = &du;
	ap[4] = &du2;
	ap[5] = &du3;
	ap[6] = &c;
	ap[7] = &c2;
	ap[8] = &c3;

	polyfunc(ap, 9);

	
return 0;
}
