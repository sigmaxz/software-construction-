#ifndef coins_h
#define coins_h

#include <iostream>
#include "Coins.h"
using namespace std;

Coins::Coins(int q, int d, int n, int p)
:quarters(q), dimes(d), nickels(n), pennies(p) {}

void Coins::depositChange( Coins c)
{
	quarters += c.quarters;
	dimes += c.dimes;
	nickels += c.nickels;
	pennies += c.pennies;
}

bool Coins::hasSufficientAmount( int amount)
{
	int total = quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME;
	total += nickels*CENTS_PER_NICKEL + pennies*CENTS_PER_NICKEL;
	if(total > amount)
		return true;
	return false;
}

Coins Coins::extractChange(int amount)
{
	if(!hasSufficientAmount(amount))
	{
		cout << "not enough money" << endl;
		return Coins(0,0,0,0);
	}
	int newQ, newD, newN, newP;
	int amountLeft = amount;
	newQ = amountLeft / CENTS_PER_QUARTER;
	amountLeft = amountLeft % CENTS_PER_QUARTER;
	newD = amountLeft / CENTS_PER_DIME;
	amountLeft = amountLeft % CENTS_PER_DIME;
	newN = amountLeft / CENTS_PER_NICKEL;
	amountLeft = amountLeft % CENTS_PER_NICKEL;
	newP = amountLeft;
	quarters -= newQ;
	dimes -= newD;
	nickels -= newN;
	pennies -= newP;

	return Coins(newQ, newD, newN, newP);
}

void Coins::print( ostream & out)
{
	cout << "Q: " << quarters << " D: " << dimes << " N: " << nickels
	<< " P: " << pennies << endl;
}

ostream &  operator << ( ostream & out, Coins & c)
{
	c.print( out);
	return out;
}

#endif 



