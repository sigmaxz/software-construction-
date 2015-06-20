#include "Matrix.h"
#include <iostream>
using namespace std;

template
 < class T >
void fillMatrix(const Matrix <T> & m )
{
 int i, j;
 for ( i = 0; i < m.numRows(); i++ )
   m[i][0] = T();
 for ( j = 0; j < m.numCols(); j++ )
   m[0][j] = T();
 for ( i = 1; i < m.numRows(); i++ )
   for ( j = 1; j < m.numCols(); j++ )
   {
     m[i][j] = T(i * j);
   }
}
int main()
{
try{
 Matrix < int > m(10,5);
 fillMatrix( m );
 cout << m;
 Matrix < double > M(8,10);
 fillMatrix( M );
 cout << M;
 cout.flush();
m[20];
} catch(...) { cout << "exception caught for rows\n" ;}

try{
Matrix<int> t(5,5);
fillMatrix(t);
t[1][10]; } catch(...) {cout << "exception caught for cols";}

return 0;
}


