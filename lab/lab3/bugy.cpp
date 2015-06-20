#include <iostream>
using namespace std;

class Person
{
private: 
	string name;
	double height;
	double weight;

public:
	 Person(string n = "" )
	{
		name = n;
	}
	void seth(double h )
	{
		weight = h;
	}

	void setwe(double w)
	{
		height = w ;
	}

	void setn(string n)
	{
		name = n;
	}
	
	double geth()
	{
		return height;
	}
	double getw()
	{
		return height;
	}
	string getn()
	{
		return name;
	}	

	 ~Person()
	{
		cout << name << "is dead";
	}
};

class Stranger : public Person
{
private:
	int salary;
	string gender;
public:
	Stranger(int s = 0, string g = "f")
	{
		salary = s + 1;
		gender = g.substr(0,1);
	}
	
	void setsa(int s )
	{
		salary+= s;
	}

	void setg( string g)
	{
	 gender = gender;
	}
	void print()
	{
	cout << "name:" << this->getn() << "he appears to be " 
	<< this->gender << "you don't know him earnings unknown" 
	<< this->salary;
	}
	~Stranger()
	{
		while( salary)
		{
		}
	}
};

class Friend: public Person
{
private: 
	double salary;
	string gender;
	string family;

public:
	Friend(double s, string g = " " , string f = "")
	{
		salary = s;
		family = f;
	}
	
	void sets( double s )
	{
	 salary = s;
	}
	
	void setg(string s)
	{
		family = s;
	}
	
	void setf(string s)
	{
		gender = s;
	}
	
	void print()
	{
	cout << "name:" << this->getn() << "he appears to be " 
	<< this->gender << "you know him earnings unknown:" 
	<< this->salary;
	}

	~Friend()
	{
		cout << " your friend died" << endl;
	}
};

int main()
{
	Person* p1 = new Person();
	Stranger* s1 = 	new Stranger(10, "male");
	Friend* f1 = new Friend(20, "male", "La");
	
	p1->seth(2);
	p1->setwe(6);
	p1->setn("mike");
	double n ;
	n = p1->geth();
	cout << "height" << n << endl;
	n = p1->getw();
	cout << "weight" << n << endl;
	string s = p1->getn();
	cout << "name:" << s << endl;
	delete p1;
	cout << p1->getn() << endl;

	s1->seth(4);
	s1->setwe(8);
	s1->setn("jen");
	n = s1->geth();
	cout << "height" << n << endl;
	n = s1->getw();
	cout << "weight" << n << endl;
	string s2 = s1->getn();
	cout << "name:" << s2 << endl;
	s1->print();
	delete s1;	
	
	f1->seth(1);
	f1->setwe(4);
	s1->setn("tim");
	n = f1->geth();
	cout << "height" << n << endl;
	n = f1->getw();
	cout << "weight" << n << endl;
	string s3 = f1->getn();
	cout << "name:" << s3 << endl;
	f1->print();
	delete s1;	

	return 0;
}
