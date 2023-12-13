#include <iostream>
using namespace std;

class dictionary
{
public:
    int key;
    string value;
    dictionary *next;
    dictionary()
    {
        next = NULL;
    }
};

dictionary *HT[10];

int Hash(dictionary *ptr)
{
    int h = ptr->key % 10;
    if (HT[h] == NULL)
    {
        HT[h] = ptr;
    }
    else
    {
        dictionary *p = HT[h];
        while (p->next != NULL && p->key != ptr->key)
        {
            p = p->next;
        }
        if(p->key == ptr->key) {
        	delete ptr;
        	return 0;
        } else {
        	p->next=ptr;
        }
    }
    return 1;
}

int insert(int key, string value)
{
    dictionary *d = new dictionary();
    d->key = key;
    d->value = value;
    return Hash(d);
}

bool delete_pair(int key) {
    dictionary* match_pair = HT[key%10];
    dictionary* prev_pair = NULL;
    
    if( match_pair!=NULL && match_pair->key!=key) {
        prev_pair = match_pair;
        match_pair=match_pair->next;
    }
    
    if(match_pair==NULL) {
        return 0;
    }
    
    dictionary* next_pair = match_pair->next;
    
    if(prev_pair==NULL) {
        HT[key%10] = next_pair;
    } else {
        prev_pair->next=next_pair;
    }
    delete match_pair;
    return 1;
}

void display()
{
    cout << "\n\n\nThe hash table" << endl;
    cout<<"\tKey\tValue"<<endl<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<i;
        if (HT[i] == NULL)
        {
            cout << "\tEmpty";
        }
        else
        {
            dictionary *p = HT[i];
            while (p != NULL)
            {
                cout <<"\t"<<p->key <<"\t"<< p->value;
                p = p->next;
            }
        }
        cout<<endl;
    }
}

string search(int key)
{
    dictionary *p = HT[key % 10];
    while (p != NULL)
    {
        if (p->key == key)
        {
            return p->value;
        }
        p = p->next;
    }
    return 0;
}

int main()
{
    int choice, key;
    string value;
    
    while (true)
    {
        cout << "\nMenu Options:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                if(insert(key, value)==1) {
                	cout<<"Key value pair inserted\n";
                } else {
                	cout<<"Key already exists\n";
                }
                break;
            
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                cout<< search(key);
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                cout << "Enter key to delete: ";
                cin >> key;
                if(delete_pair(key) == 1) {
                    cout<<"Key value pair deleted\n";
                } else  {
                    cout<<"Key value pair did not find\n";
                }
                break;

            case 5:
                return 0;
            
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    
    return 0;
}