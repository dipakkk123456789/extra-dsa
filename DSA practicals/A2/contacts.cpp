// Online C++ compiler to run C++ program online
#include <iostream>
#include <iomanip>
using namespace std;

class contact {
  long num;
  string name;
  friend class Hash;
  public:
  void input() {
      cout<<"Enter name: ";
      cin>>name;
      cout<<"Enter number: ";
      cin>>num;
  }
};

class Hash {
    contact Hashtable[10]{};
    public:
    int Hashfun(contact obj) {
        return (obj.num)%10;
    }
    
    void hashing_with_replacement(contact obj) {
        if (Hashtable[Hashfun(obj)].num != 0)
    {
        contact temp = Hashtable[Hashfun(obj)];
        int i = Hashfun(obj);

        do
        {
            i = (i+1)%10;
        } while (Hashtable[i].num != 0 && i != Hashfun(obj));
        if (i == Hashfun(obj))
        {
            cout << "\nHash Table overflowed!!\n";
            exit(0);
        }

        Hashtable[i] = temp;
    }

    Hashtable[Hashfun(obj)] = obj;
    }
    
    void hashing_without_replacement(contact obj)
    {
    int i = Hashfun(obj);

    do
    {
        i = (i+1)%10;
    } while (Hashtable[i].num != 0 && i != Hashfun(obj));
    if (i == Hashfun(obj))
    {
        cout << "\nHash Table overflowed!!\n";
        exit(0);
    }

    Hashtable[i] = obj;
}
    
    void display()
{
	cout<<endl<<endl;
    cout <<setw(15)<<"Name"<<setw(15)<<"Number"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout << setw(15) << Hashtable[i].name<<setw(15)<<Hashtable[i].num;
        cout << "\n";
    }
}

};

int main() {
    int n,ch;
    cout<<"Enter no. of students: ";
    cin>>n;
    contact student[n];
    
    for(int i=0; i<n;i++) {
        student[i].input();
    }
    
    
    cout<<"1. With replacement\n2. Without replacement\n\nEnter your choice: ";
    cin>>ch;
    
    Hash H;
    for(int i=0; i<n; i++) {
    if (ch==1) 
    H.hashing_with_replacement(student[i]);
    else if (ch==2)
    H.hashing_without_replacement(student[i]);
    }
    
    H.display();

    
    return 0;
}
