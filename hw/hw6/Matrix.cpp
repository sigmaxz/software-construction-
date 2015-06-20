#include "Matrix.h"
using namespace std;

template 
<typename Element>
Matrix<Element>:: Matrix( int newRows, int newCols )
   : rows( newRows ), cols( newCols ), m( rows )
 {
   for (int i = 0; i < rows; i++ )
     m[i] = new Array<Element>( cols );
 } 

template
<typename Element>
int Matrix < Element> :: numRows() const
 {
   return rows;
 }

template
<typename Element>
 int Matrix<Element>::numCols() const
 {
   return cols;
 }

template
<typename Element>
 Array< Element > & Matrix<Element>::operator [] ( int row ) const
 {
   return * m[row];
 }

template
<typename Element>
 void Matrix<Element>::print( ostream & out ) const
 {
   // You can write this one too, but use the Array::operator<<
     for (int i = 0; i < rows; i++ )
     out << *(m[i]) << endl;

	
 }

