#include <iostream> 
#include <fstream>
#include <iomanip>

using namespace std;

#define SIZE 30
class rolodex
{
  // acts a a node containing info the card would
  struct card
  {
    string fname, lname, address, phoneNumber;
    card* next;
    
    // all in one constructor 
    card(string f = "", string l= "" ,string a = "",string p = "",card* ne = NULL)
    : fname(f), lname(l) , address(a), phoneNumber(p), next(ne) {}

    ~card(){}
  };
  
  private:
    card* start;
    
  public:
  
    rolodex( card* r = NULL)
    : start(r) {}
    
    ~rolodex()
    {
      card* temp = start;
      while( temp)
      {
        card* temp2 = temp;
        temp = temp->next;
        delete temp;
      }
    }
    
    void insert( string f, string l  , string a , string p)
    {
      card* temp = start;
      card* ncard = new card(f,l,a,p);
      if(!temp)
      {
        start = ncard;
        return;
      }
      if(temp->next == NULL && temp->lname < ncard->lname )
      {
        temp->next = ncard;
        return;
      }
      card* pre = NULL;
      while( temp && temp->lname < ncard->lname)
      {
        pre = temp;
        temp = temp->next;
      }
      if(temp && pre && temp->lname > ncard ->lname)
      {
        card* temp2 = pre->next; 
        pre->next = ncard;
        ncard->next = temp2;
      }
      else if(temp && !pre)
      {
        ncard->next = temp;
        start = ncard;
      }
      else
        pre->next = ncard;
        
    }
    
    string find(string ln) const
    {
      card* temp = start;
      while( temp != NULL)
      {
        if( temp->lname == ln) return temp -> address;
        temp = temp->next ;
      }
      return string("not found") ;
    }
        
    void d(string ln)
    {
      card* temp = start;
      if(temp->lname == ln)
      {
        start = temp->next;
        delete temp;
        return;
      }
      card* pre = NULL;
      while( temp != NULL)
      {
        if( temp-> lname == ln) 
        {
          if( pre && temp->next)
          {
            pre ->next = temp->next;
          }
          else if(!pre && !temp->next)
           start = NULL;
          else if(!pre && temp->next)
            start = temp->next;
          else
            pre->next = NULL;
          delete temp;
          return;
        }
        pre = temp;
        temp = temp->next;
      }
    }
        
    void print() const
    {
      cout << setw(SIZE/2) << "First Name-" << setw(SIZE/2) << "Last Name-" 
      << setw(SIZE/2) << "Address" << setw(SIZE/2) << "Number" << endl;
      card* temp = start;
      while( temp)
      {
        cout << setw(SIZE/2) << temp->fname << " " << setw(SIZE/2) 
        << temp->lname << " " << setw(SIZE/2) << temp->address;
        cout << " " << setw(SIZE/2) << temp->phoneNumber << endl;
        temp = temp->next;
      }
    }
    
    void load( const char* file)
    {
      string f, l, a, p;
      ifstream info(file);
      
      while( info >> f >> l >> a >> p)
      {
        this->insert(f,l,a,p);
      }
      info.close();
    }
    
    void save( const char* file)
    {
      ofstream outInfo(file);
      card* temp = start;
      while( temp)
      {
        outInfo << temp->fname << " " << temp->lname << " " << temp->address
        << " " << temp->phoneNumber << endl;
        temp = temp->next;
      }
      outInfo.close();
    }
    
    void quit()
    {
      ofstream outInfo("save");
      card* temp = start;
      while( temp)
      {
        outInfo << temp->fname << " " << temp->lname << " " << temp->address;
        outInfo << " " << temp->phoneNumber << endl;
        temp = temp->next;
      }
      outInfo.close();
    }
};

int main()
{
  rolodex* r = new rolodex();
  string f,l,a,p;
  char* file = new char[SIZE];

  char c;
  cout << "Welcome to your rolodex!" << endl;
  do
  {
  
  cout << "i:insert f:get address d:delete p:print l:load s:save q:quit\n";
  cin >> c;
  switch(c)
  {
    case 'i':
      cout << "provide name(first space last) adress and phone number(both no space):"
       << endl;
      cin >> f;
      cin >> l;
      cin >> a;
      cin >> p;
      r->insert(f,l,a,p);
      break;
    case 'f':
      cout << " provide last name" << endl;
      cin >> l;
      a = r->find(l);
      cout << a << endl;
      break;
    case 'd':
      cout << "provide last name" << endl;
      cin >> l;
      r->d(l);
      break;
    case 'p':
      r->print();
      break;
    case 'l':
      cout << "provide file name" << endl;
      cin >> file;
      r->load(file);
      break;
    case 's':
      cout << "provide file name" << endl;
      cin >> file;
      r->save(file);
      break;
    case 'q':
      r->quit();
      break;
    }
  }while( c != 'q');
    
  return 0;
}
