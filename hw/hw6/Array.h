#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;
template
<typename T>
 class Array
{
private:
 int len;
 T * buf;
public:
 Array<T>( int newLen  );
 Array<T>( Array & l );
 int length() const ;
 T & operator [] ( int i ) const ;
 void print( ostream & out ) const ;
 friend ostream & operator << ( ostream & out, Array<T> & a )
 {
   a.print( out );
   return out;
 }
};
#include "Array.cpp"
#endif 
