// Coins.h        ///  The name of this file.
#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
public:
Coins( int q, int d, int n, int p );
void depositChange( Coins c );
bool hasSufficientAmount( int amount );
Coins extractChange( int amount );
void print( ostream & out );
private:
int quarters, dimes, nickels, pennies;
};
ostream & operator << ( ostream & out, Coins & c );

// Coins.cc will have definitions of all Coins methods
