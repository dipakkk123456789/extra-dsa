#include <iostream>
#include<string.h>
using namespace std;

class node {
  public:
  string keyword, meaning;
  node* left, *right;
  
  node() {
      left = right = NULL;
  }
};

node* insert_node(string keyword, string meaning, node* root) {
    node* current_node = new node;
    current_node->keyword = keyword;
    current_node->meaning = meaning;
    
    if(root==NULL) {
        root = current_node;
    } else {
        node* ptr = root;
        while(1) {
            if(current_node->keyword<ptr->keyword) {
                if(ptr->left !=NULL) {
                    ptr = ptr->left;
                } else {
                    ptr->left = current_node;
                    break;
                }
            } else {
                if(ptr->right !=NULL) {
                    ptr = ptr->right;
                } else {
                    ptr->right = current_node;
                    break;
                }
            }
        }
    }
    
    return root;
}

void ascending_order(node* ptr) {
    if(ptr==NULL) return;
    
    ascending_order(ptr->left);
    cout<<ptr->keyword<<" : "<<ptr->meaning<<endl;
    ascending_order(ptr->right);
}

node* find_node(string keyword, node* ptr) {
    if (ptr==NULL) {
        return NULL;
    }
    if(keyword==ptr->keyword) {
        return ptr;
    }
    
    if(keyword<ptr->keyword) {
        return find_node(keyword,ptr->left);
    } else {
        return find_node(keyword,ptr->right);
    }
}

node* delete_node(string keyword, node* root) {
    node* ptr = root;
    node* parent = NULL;
    node* successor = NULL;
    while(ptr!=NULL && keyword != ptr->keyword) {
        parent = ptr;
        if(keyword<ptr->keyword) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }

    if(ptr!=NULL) {
        if(ptr->left==NULL && ptr->right==NULL) {
            if(parent!=NULL) {
                if(parent->left == ptr) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                delete ptr;
            } else {
                delete ptr;
                root = NULL;
            }
        } else if(ptr->right == NULL) {
            if(ptr==root) {
                root = ptr->left;
                delete ptr;
            }
            else if(parent->left == ptr)
                parent->left = ptr->left;
            else
                parent->right = ptr->left;

            delete ptr;
        } else if(ptr->left == NULL ) {
            if(ptr==root) {
                root = ptr->right;
                delete ptr;
            }
            else if(parent->left == ptr) 
                parent->left = ptr->right;
            else
                parent->right = ptr->right;

            delete ptr;
        } else {
            successor = ptr->right;
            while(successor->left!=NULL) {
                successor = successor ->left;
            }
            string successor_keyword = successor->keyword;
            string successor_meaning = successor->meaning;
            ptr->right = delete_node(successor->keyword,ptr->right);
            ptr->keyword = successor_keyword;
            ptr->meaning = successor_meaning;
            
        }
    }
    return root;
}

void descending_order(node* ptr) {
    if(ptr==NULL) return;
    
    descending_order(ptr->right);    
    cout<<ptr->keyword<<" : "<<ptr->meaning<<endl;
    descending_order(ptr->left);
}

int main() {
    int ch;
    string keyword, meaning;
    node* root = NULL;
    node* ptr;

    // root = insert_node("Aditya", "surya", root);
    // root = insert_node("Himanshu", "channd", root);
    // root = insert_node("Hardik", "from heart", root);
    // root = insert_node("Anurag","small anger", root);
    // root = insert_node("Suyash","the success",root);

    // cout<<"\n\nDeleting a node\n";
    // root = delete_node("Aditya",root);
    // root = delete_node("Himanshu",root);
    // cout<<"\n\nAscending order:\n";
    // ascending_order(root);

    while(1) {
        cout<<"\t* * * Menu * * *\n";
        cout<<"1. Insert a node\n2. Delete a node\n3. Update a node\n4. Find meaning\n5. Ascending Order\n6. Descending Order\n7. Exit\n\nEnter your choice: ";
        cin>>ch;

        switch (ch) {
            case 1:
            cout<<"\nEnter the keyword: ";
            cin.ignore();
            getline(cin,keyword);
            cout<<"Enter the meaning: ";
            getline(cin,meaning);
            root = insert_node(keyword, meaning, root);
            cout<<"\nNode inserted successfully!!\n\n";
            break;
            
            case 2:
            cout<<"\nEnter the keyword: ";
            cin.ignore();
            getline(cin,keyword);
            root = delete_node(keyword,root);
            cout<<"\nNode deleted successfully!!\n\n";
            break;

            case 3:
            cout<<"\nEnter the keyword: ";
            cin.ignore();
            getline(cin,keyword);
            ptr = find_node(keyword,root);
            if(ptr==NULL) {
                cout<<"\nNode not found\n\n";
            } else {
                cout<<"Enter the new meaning: ";
                getline(cin,meaning);
                ptr->meaning = meaning;
                cout<<"\nNode updated successfully!!\n\n";
            }
            break;

            case 4:
            cout<<"\nEnter the keyword: ";
            cin.ignore();
            getline(cin,keyword);
            ptr = find_node(keyword,root);
            if(ptr==NULL) {
                cout<<"\nNode not found\n\n";
            } else {
                cout<<"\nThe meaning of "<<keyword<<" is "<<ptr->meaning<<"\n\n";
            }
            break;

            case 5:
            cout<<"\nAscending order:\n";
            ascending_order(root);
            break;

            case 6:
            cout<<"\nDescending order:\n";
            descending_order(root);
            break;

            case 7:
            exit(0);
            default:
            cout<<"\nInvalid choice\n\n";
        }
    }
}