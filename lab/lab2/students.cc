#include <iostream>
using namespace std;

class Note
{
  struct student
  {
    char*  fn;
    char* ln;
    char* date;
    char* id;
    student* next;
    
    student( char* f = "" , char* l = "" , char* d = "" , char* i = "")
    : fn(f) , ln(l) , date(d), id(i) {}
    void print() const
    {
      cout << this -> fn << "  " << this -> ln << "  " << this-> date << "  " << this -> id << endl;
    }
    ~student()
    {
      delete fn;
      delete ln;
      delete date;
      delete id;
    }
  };
  
  private:
    student* start;
    int size;
  
  public:
    Note()
    : start(NULL), size(0){}
    
    void add( char* f = "" , char* l = "" , char* d = "" , char* i = "")
    {
      student*  temp = new student(f, l,d,i);
      if ( !start) start = temp;
      else 
      {
        student* pos = start;
        student* pre = NULL;
        if(pos -> next == NULL)
        {
          if(pos-> ln > l)
          {
            temp -> next = pos;
            start = temp;
          }
          else 
          {
            pos -> next = temp;
          }
        }
        else 
        {
          if(start -> ln > l)
          {
            temp -> next = pos;
            start = temp;
          }
          else
          {
            while(pos != NULL && pos -> ln < l)
            {
              pre = pos;
              pos = pos -> next;
            }

              pre -> next = temp;
              temp -> next = pos;

          }
        }
        
      }
        //student* temp1 = start;
        //student* pre = NULL;
       //while(temp1 != NULL &&  temp1 -> ln > temp-> ln)

        //{

            //pre = temp1;
            //temp1 = temp1 -> next;

        //}
        //if(pre -> next == NULL)
        //{
          //if(pre == start)
              //start = temp;
          //temp -> next = pre;
         //// cout << pre -> ln<< endl ;
          //return;
        //}
        ////student* temp2 = pre -> next;
        //pre -> next = temp;
        //temp -> next = temp1;
        
 
      //}
    }
    
    void remove(char* l)
    {
      if ( !start) cout << "not here" << endl;
      else 
      {
        student* temp1 = start;
        student* pre = NULL;
        //possible restructuring 
        while(temp1 != NULL &&  temp1 -> ln != l)
        {
          pre = temp1;
          temp1 = temp1 -> next;
        }
        if(!pre) 
        {
          delete temp1;
          start = pre;
          return;
        }
          
        student* temp2 = temp1 -> next;
        pre -> next = temp2;
        delete temp1;
      }
    }
    
    student* search(char* l) const
    {
      if(!start) cout << "empty list" << endl;
      else 
      {
        student* temp1 = start;
        while( temp1 != NULL)
        {
          if(temp1 -> ln == l)
          {
            temp1->print();
            return temp1;
          }
          temp1  = temp1 -> next;
        }
        cout << "last name not found";
        student* empty = new student();
        return empty;
      }
      
      
      
    }
    void print()
      {
        student* temp = start;
        if( !temp)
        {
          cout << "empty" << endl;
          return;
        }
        while(temp)
        {
          temp->print();
          temp = temp->next;
        }
      }
    
      
  };
  
int main()
{
  Note* a = new Note();
  a->add("akiyo", "yokota","100492","911");
   a->search("yokota" );
   a->add("asdf", "zbfdfdsa","100492","911");
   a->search("zbfdfdsa" );
   cout << endl << endl;
   //a->print();
   
   a-> add ("hhh","ya", "asfdsa","afd");
   a-> add ("hhh","yc", "asfdsa","afd");
   a-> remove ("ya");
   a->print();
   //a->remove
  return 0;
}
    
