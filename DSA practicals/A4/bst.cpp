#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left, *right;
    node() {
        left = right = NULL;
    }
};

node* insert_node(node* current_node, node* root) {
    if (root == NULL) {
        root = current_node;
    }
    else {
        node* ptr = root;
        while (1) {
            if (current_node->data < ptr->data) {
                if (ptr->left != NULL) {
                    ptr = ptr->left;
                }
                else {
                    ptr->left = current_node;
                    break;
                }
            }
            else {
                if (ptr->right != NULL) {
                    ptr = ptr->right;
                }
                else {
                    ptr->right = current_node;
                    break;
                }
            }
        }
    }

    return root;
}

node* construct(int* arr, int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        node* new_node = new node();
        new_node->data = arr[i];
        root = insert_node(new_node, root);
    }
    return root;
}

void ascending_order(node* ptr) {
    if (ptr == NULL)
        return;

    ascending_order(ptr->left);
    cout << ptr->data << endl;
    ascending_order(ptr->right);
}

void lefttoright(node* ptr) {
    if (ptr == NULL) {
        return;
    }
    node* temp;

    temp = ptr->left;
    ptr->left = ptr->right;
    ptr->right = temp;

    lefttoright(ptr->left);
    lefttoright(ptr->right);
}

int min_data(node* root) {
    if (root->left == NULL)
        return root->data;
    return min_data(root->left);
}

int height(node* ptr) {
    if (ptr == NULL) {
        return 0;
    }
    int lh = 1 + height(ptr->left);
    int rh = 1 + height(ptr->right);
    return lh > rh ? lh : rh;
}

bool search_node(int data, node* ptr) {
    if (ptr == NULL) {
        return false;
    }
    if (data == ptr->data) {
        return true;
    }

    if (data < ptr->data) {
        return search_node(data, ptr->left);
    }
    else {
        return search_node(data, ptr->right);
    }
}

int main() {
    node* root = NULL;
    int choice;

    do {
        cout << "\n\n\n------ Menu ------" << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Find number of nodes in longest path from root" << endl;
        cout << "3. Minimum data value found in the tree" << endl;
        cout << "4. Change a tree so that the roles of the left and right pointers are swapped at every node" << endl;
        cout << "5. Search a value" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            {int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            node* new_node = new node();
            new_node->data = value;
            root = insert_node(new_node, root);}
            break;
        case 2:
            {int longestPath = height(root);
            cout << "Number of nodes in the longest path from root: " << longestPath << endl;}
            break;
        case 3:
            {int minValue = min_data(root);
            cout << "Minimum data value found in the tree: " << minValue << endl;}
            break;
        case 4:
            lefttoright(root);
            cout << "Tree modified: Left and right pointers swapped at every node." << endl;
            break;
        case 5:
            {int searchData;
            cout << "Enter the value to search: ";
            cin >> searchData;
            bool isFound = search_node(searchData, root);
            if (isFound)
                cout << "Value " << searchData << " found in the tree." << endl;
            else
                cout << "Value " << searchData << " not found in the tree." << endl;
            break;}
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

