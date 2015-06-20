#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;


class String
 {
 public:
   /// Both constructors should construct
   /// from the parameter s
   String( const char * s = "");
   String( const String & s );
   String operator = ( const String & s );
   char & operator [] ( const int index );
   int length() const;
   int indexOf( char c ) const;
   bool operator == ( const String & s ) const;
   /// concatenates this and s
   String operator + ( const String & s ) const;
   /// concatenates s onto end of this
   String operator += ( const String & s );
   void print( ostream & out );
   void read( istream & in );
   ~String();
 private:
   bool inBounds( int i )
   {
     return i >= 0 && i < length();
   }
   struct ListNode
   {
     char info;
     ListNode * next;
     ListNode(char newInfo, ListNode * newNext)
       : info( newInfo ), next( newNext )
     {
     }
     // you may add static methods here
   };
   ListNode * head;
 };
 ostream & operator << ( ostream & out, String & str );
 istream & operator >> ( istream & in, String & str );

#endif
