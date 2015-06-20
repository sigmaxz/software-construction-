#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> > data;
	cout << "enter number of ints you want processed :";
	int num;
	cin >> num;
	for(;num > 0; num--)
	{
		int temp;
		cin >> temp;
		data.push(temp);
	}
	ofstream out1("odd.txt");
	ofstream out2("even.txt");
	while( !data.empty())
	{
		num = data.top();
		data.pop();
		if(num % 2 == 0) out2 << num << endl;
		else out1 << num << endl;
	}
	
return 0;
}
