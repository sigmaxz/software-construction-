#include <iostream>

using namespace std;


class stack
{
  private:
    int capacity;
    int size;
    int* s ;
    int top;
    
  public:
    stack ()
    {
      capacity = 2;
      size = 0;
      s = new int[capacity];
        top = -1;
        
    }
      
    void push(int object)
    {
      if ( size == capacity)
      {
        int newcapacity = capacity * 2;
        int* newstack = new int[newcapacity];
        for(unsigned int i = 0; i < size; i++)
        {
          newstack[i]  = s[i];
        }
        capacity = newcapacity;
        delete[] s;
        s = newstack;
      } 
      s[size++] = object;
      top ++;
    }
    
    void pop()
    {
      size--;
      if(size == 0)
          cout << "empty stack";
      else if (size < capacity/2 )
      {
        int newcapacity = capacity/2;
        int* newstack = new int[newcapacity];
        
        for(unsigned int i = 0; i < size; i++)
        {
          newstack[i]  = s[i];
        }
        delete[] s;
        capacity  = newcapacity;
        s = newstack;
      }
      top--;
      
    }
    
    ~stack()
    {
      delete[] s;
    }
    
    int getTop()
    {
      return s[top];
    }
    
    int getSize()
    {
      return size;
    }
    
    int getCap()
    {
      return capacity;
    }
    
};

int main()
{
  stack a;
  a.push(1);
  a.push(2);
  cout << "top:" << a.getTop() << " size: " << a.getSize() << " cap:" << a.getCap();
  a.push(3);
  cout << endl;
  cout << "top:" << a.getTop() << " size: " << a.getSize() << " cap:" << a.getCap();
  
  a.pop();
  a.pop();
  cout << endl;
  cout << "top:" << a.getTop() << " size: " << a.getSize() << " cap:" << a.getCap();
  return 0;
}

      
