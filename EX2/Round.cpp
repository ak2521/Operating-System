
#include <iostream>

using namespace std;
int j=65;
class node
{
public:
  char name;
  int tm;
  int rt;
  node *next;
};

class rr
{
public:
  node * Head = NULL;

 //  int j = 65;

  void insert (int n)
  {
    node *nn = new node;
      nn->name = j++;
      nn->tm = n;
      nn->rt = nn->tm;

    if (Head == NULL)
      {
    Head = nn;
    Head->next = Head;
      }

    else
      {
    node *temp = Head;
    while (temp->next != Head)
      temp = temp->next;
    nn->next = temp->next;
    temp->next = nn;
      }
  }

  void quantum (int t,int y)
  {
    node *temp = Head;
    int i=0, c = 0,b=0,l=y,tot=0,tot1=0,pno=1;
    char s[20];
    cout<<"Pname \t TT\tWT\t"<<endl;
    while (Head != NULL)
      {
    {
      s[i]=temp->name;
      i++;
      temp->rt = temp->rt - t;
      c = c + t;
      if (temp->rt <= 0)
        {
         // s[i]=temp->name;
          c = c + temp->rt;
          b=c-temp->tm;
          tot=b+tot;
          tot1=tot1+c;
         // s[i]=temp->name;
          //i++;
          cout << temp->name<<"\t";
          //cout<<pno<<"\t";
          cout << c<<"\t";
          cout<<b<<endl;
          del (temp->name);
          if (temp->next == temp)
        {
          break;
        }

        }

      temp = temp->next;
    }
      }
        cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<endl;
        for(int g=0;g<i;g++)
        {
        cout<<"|"<<s[g]<<"(1)";
        }
        cout<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;

        cout<<endl<<"Average waiting time"<<(float)tot/l<<endl;
        cout<<"Average turn around time "<<(float)tot1/l;
  }

  void del (char x)
  {
    node *p = NULL;
    node *temp = Head;

    if (Head->name == x)
      {
    while (temp->next != Head)
      temp = temp->next;
    p = Head;
    temp->next = Head->next;
    Head = Head->next;
    delete p;
      }
    else
      {
    while (temp->name != x)
      {
        p = temp;
        temp = temp->next;
      }
    p->next = temp->next;
    delete temp;
      }
  }
};

int
main ()
{
  rr robin;
  int i, n, x, y, t;
  cout<<"Enter the no of processor\n";
  cin >> y;
  cout<<"Enter the time silce\n";
  cin >> t;

  for (i = 0; i < y; i++)
    { cout<<"Enter the brust time\n";
      cin >> n;
      robin.insert (n);

    }
  robin.quantum (t,y);

  return 0;
}
