#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
  Stack chars;
  char c;
  do
  {
    cin >> c;
    if(cin.good())
    {
      chars.push(c);
    }
  } while(cin.good());
  while(!chars.isEmpty())
  {
    cout << chars.pop();
  }
  
  return 0;
}
