#ifndef STACK_H
#define STACK_H

#define STACK_CAPACITY 1000

#include <iostream>

using namespace std;

class Stack
{
  private:
    char* c_ptr;
    unsigned size;
    
  public:
  
    Stack()
    {
      c_ptr = new char[STACK_CAPACITY] ;
      size = 0;
    }
    
    void push(char c)
    {
      if(size >= STACK_CAPACITY)
      {
        cerr << "overflow err" << endl;
        return;
      }
      c_ptr[size] = c;
      size++;
    }
    
    char pop()
    {
      if( size < 1) 
      {
        cerr << "underflow err" << endl;
        return '1';
      }
      char c = c_ptr[size-1];
      c_ptr[size-1] = '\0';
      size--;
      return c;
    }
    
    char top()
    {
      if(size < 1) 
      {
        cerr << "err empty" << endl;
        return '1';
      }
      return c_ptr[size-1];
    }
    
    bool isEmpty()
    {
      if (size > 0) return false;
      return true;
    }
    
    ~Stack()
    {
      delete[] c_ptr;
    }
};

#endif
