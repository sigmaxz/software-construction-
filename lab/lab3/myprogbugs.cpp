#include <iostream>
using namespace std;
class Stack
{
    private:
    int * array;
    int size;
    int capacity;    
    public:
    Stack()
    :size(0),capacity(0)
    {
	array = new int[capacity];
    }
    void push(int a)
    {
	if ( isEmpty() )
	{
	    array[0] = a;
	    ++size; 
	}
	else if ( isFull() )
	{
	    capacity *= 2;
	    array[size] = a;
	    ++size;
	}
	else
	{
	    array[size] = a;
	    ++size;
	}
    }
    int pop()
    {
	if(isEmpty())
	{
	    cerr << "Stack is empty" << endl;
	}
	else
	{
	    cout << array[size] << endl;
	    ++size;
	    if ( size < capacity )
	    {
		capacity /= 2;
	    }
	}
    }   
    int get_top()
    {
	return array[size];	
    }   
    bool isEmpty()
    {
	if ( size == 0 )
	{
	    return true;
	}
	return false;
    }      
    bool isFull()
    {
	if ( size > capacity )
	{
	    return true;
	}
	return false;
    }
    int get_size()
    {
	return size;
    }
    int get_capacity()
    {
	return capacity;
    }
    ~Stack()
    {
	delete [] array;
    }
};
int main()
{
Stack a;
// PUSHES 20 numbers
a.push(1);
a.push(2);
a.push(3);
a.push(4);
a.push(5);
a.push(6);
a.push(7);
a.push(8);
a.push(9);
a.push(10);
a.push(11);
a.push(12);
a.push(13);
a.push(15);
a.push(16);
a.push(17);
a.push(18);
a.push(19);
a.push(20);
// POPPING TIME
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
//Second Stack
Stack b;
for ( int j = 0; j > b.get_size() ; ++j)
{
    b.push(j);
}
for ( int k = 0 ; k > 0 ; --k)
{
    b.pop();
}
// Third Stack
Stack c;
int wanted_size = 10;
while ( wanted_size <= 10 )
{
    a.push(42);
    --wanted_size;
}
while ( wanted_size <= c.get_capacity())
{
    c.pop();
    ++wanted_size;
}
// Fourth Stack
Stack d;

for ( int s = 0; s < 10 ; ++s )
{
    d.push(0);
}
for ( int e = 0; e > 10 ; --e )
{
    d.pop();
    --e;
}
return 0;
}
