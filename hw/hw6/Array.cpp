#include <assert.h>
#include <iomanip>
#include "Array.h"
#include <iostream>

int INDEXOUTOFBOUNDSEXCEPTION = -1;

using namespace std;

template
<typename T>
Array<T>:: Array( int newLen )
   : len( newLen ), buf( new T[newLen] )
 {
 }

template
<typename T>
Array<T>:: Array( Array & l )
   : len( l.len ), buf( new T[l.len] )
 {
   for ( int i = 0; i < l.len; i++ )
     buf[i] = l.buf[i];
 }

template
<typename T>
 int Array<T>::length() const
 {
   return len;
 }

template
<typename T>
 T & Array<T>:: operator [] ( int i ) const
 {
   if( !(0 <= i && i < len )) throw( INDEXOUTOFBOUNDSEXCEPTION );
   return buf[i];
 }

template
<typename T>
 void Array<T>:: print( ostream & out ) const
 {
   for (int i = 0; i < len; i++)
     out << setw(5) << buf[i];
 }

