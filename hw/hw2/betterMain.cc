#include <iostream>
#include "Coins.h"

using namespace std;

int main()
{
	Coins pocket(5,6,3,8);
	Coins piggyBank(50,50,50,50);

	cout << "pocket has: " << pocket << endl;
	cout << "piggyBank has: " << piggyBank << endl;

	Coins payForChips = pocket.extractChange( 68);
	cout << "buy chips for 68cents for" << "cents using " << payForChips
	<< endl;
	cout << " I have " << pocket << " left in my pocket " << endl;

	Coins fromBank = piggyBank.extractChange(877);
	cout << "withdrawing from bank the amount of 877 ";
	cout << "i got " << fromBank << " from the bank" << endl;
	pocket.depositChange(fromBank);
	cout << "in my pocket i have " << pocket << endl;
	cout << "in the bank there is " << piggyBank << endl;

	Coins couchCoins(10,3,5,1);
	cout << "while vacuuming you i found " << couchCoins << endl;
	cout << "i place them in my bank\n";
	piggyBank.depositChange(couchCoins);
	cout << "bank now has " << piggyBank << endl;

	return 0;
}
	

