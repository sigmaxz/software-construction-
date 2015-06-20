#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;
class String
  {
  public:
    /// Both constructors should construct
    /// this String from the parameter s
    String( const char * s = "");
    String( const String & s );
    String operator = ( const String & s );
    char & operator [] ( int index );
    int size();
    String reverse(); // does not modify this String
    int indexOf( char c );
    int indexOf( String pattern );
    bool operator == ( String s );
    bool operator != ( String s );
    bool operator > ( String s );
    bool operator < ( String s );
    bool operator <= ( String s );
    bool operator >= ( String s );
    /// concatenates this and s to return result
    String operator + ( String s );
    /// concatenates s onto end of this
    String operator += ( String s );
    void print( ostream & out );
    void read( istream & in );
    ~String();
  private:
    bool inBounds( int i )
    {
      return i >= 0 && i < len;
    }
    char * buf;
    int len; // the number of chars in buf
  };
  ostream & operator << ( ostream & out, String & str );
  istream & operator >> ( istream & in, String & str );

#endif
