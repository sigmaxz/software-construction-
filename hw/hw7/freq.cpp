#include <iostream>
#include <map>
#include <set>
#include <fstream>


using namespace std;

int main()
{
	map<string, int> counter;
	string ignore[] = {"a", "an", "or", "but", "the", "and"};
	set<string> exclusions(ignore, ignore+6);
	map<string,int>::iterator i;
	set<string>::iterator is;

	ifstream in("input.txt");
	while(in)
	{
		string a;
		in >> a;
		cout << a << " ";
		is = exclusions.find(a);
		if(is == exclusions.end())
		{
			counter[a] = counter[a] + 1;
		}
	}
	cout << endl;
	for(i = counter.begin(); i != counter.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}


return 0;
}
