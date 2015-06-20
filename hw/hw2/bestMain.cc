#include <iostream>
#include "Coins.h"

using namespace std;

int main()
{
	char input;
	int q,d,n,p;
	Coins myCoins(0,0,0,0);
	cout << "Welcome to myCoin management\n";
	do
	{
		cout << "commands are d:deposit e:extract p:print q:quit\n";
		cin >> input;

		switch(input)
		{
			case 'p':
				cout << myCoins << endl;
				break;
			case 'd':
				cout << "give num of quarters,dimes,nickels, and pennies\n";				cin >> q >> d >> n >> p;
				//Coins deposit(q,d,n,p);
				myCoins.depositChange(Coins(q,d,n,p));
				break;
			case 'e':
				cout << "enter amount wanted amount\n";
				cin >> q;
				Coins ex = myCoins.extractChange(q);
				break;
		}
	}while(input != 'q');

	return 0;
}



