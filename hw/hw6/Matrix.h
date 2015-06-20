#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"
#define INDEXOUTOFBOUNDSEXCEPTION = -1;

template
   < class Element >
class Matrix
{
private:
 int rows, cols;
 Array< Array <Element>* > m;
public:
 Matrix<Element>( int newRows, int newCols );
 int numRows() const;
 int numCols() const;
 Array < Element > & operator [] ( int row ) const;
 void print( ostream & out ) const;
 friend ostream & operator << ( ostream & out, Matrix & m )
 {
   m.print( out );
   return out;
 }

};
#include "Matrix.cpp"
#endif 
