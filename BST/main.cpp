#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void add_node (Node *&ptr, int value)
{
    if(ptr == NULL)
    {
        ptr = new Node;
        ptr->data = value;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if(value < ptr->data)
        add_node (ptr->left, value);
    else if(value > ptr->data)
        add_node (ptr->right, value);
}

void print_tree (Node *ptr)
{
    if (ptr!= NULL)
    {
        print_tree(ptr->left);
        cout<<ptr->data<<" ";
        print_tree(ptr->right);
    }
}

void delete_tree (Node *&ptr)
{
    Node *temp = ptr;
    if (ptr != NULL)
    {
        delete_tree(ptr->left);
        delete_tree(ptr->right);
        temp = ptr;
        ptr = NULL;
        delete temp;
    }
}

Node*& find_node (Node *&ptr, int value)
{
    if(ptr == NULL || ptr->data == value)
        return ptr;
    else if(value < ptr->data)
        find_node(ptr->left, value);
    else if (value > ptr->data)
        find_node(ptr->right, value);
}

Node* find_and_detach (Node *&ptr)
{
    if(ptr->right != NULL)
        return find_and_detach(ptr->right);
    else
        {
            Node *temp = ptr;
            ptr = NULL;
            return temp;
        }
}

void remove_node (Node *&ptr, int value)
{
    Node *&node_to_remove = find_node(ptr, value);
    if (node_to_remove == NULL)
    {
        return;
    }
    else if ( (node_to_remove->left == NULL) && (node_to_remove->right == NULL) )
    {
        delete node_to_remove;
        node_to_remove = NULL;
    }
    else if ( (node_to_remove->left != NULL) && (node_to_remove->right == NULL) )
    {
        Node *temp = node_to_remove;
        node_to_remove = node_to_remove->left;
        delete temp;
    }
    else if ( (node_to_remove->left == NULL) && (node_to_remove->right != NULL) )
    {
        Node *temp = node_to_remove;
        node_to_remove = node_to_remove->right;
        delete temp;
    }
    else if ( (node_to_remove->left != NULL) && (node_to_remove->right != NULL) )
    {
        Node *node = find_and_detach (node_to_remove->left);
        Node *temp = node_to_remove;
        node_to_remove = node;
        node_to_remove->left = temp->left;
        node_to_remove->right = temp->right;
        delete temp;
    }
}

void print_menu ()
{
    cout<<"a - add_node"<<endl;
    cout<<"f - find_node"<<endl;
    cout<<"r - remove_node"<<endl;
    cout<<"p - print_tree"<<endl;
    cout<<"d - delete_tree"<<endl;
    cout<<"e - exit"<<endl;
}

int main()
{
    char mode;
    int value;
    Node *root = NULL;
    Node *temp = NULL;
    print_menu();
    do
    {
        cout<<"enter mode"<<endl;
        cin>>mode;
        if(mode == 'a' || mode == 'f' || mode == 'r')
        {
            cout<<"enter value"<<endl;
            cin>>value;
        }

        switch(mode)
        {
        case 'a':
            add_node(root,value);
            break;

        case 'f':
            temp = find_node(root, value);
            if(temp != NULL)
                cout<<"element exist"<<endl;
            else
                cout<<"element do not exist"<<endl;
            break;

        case 'r':
            remove_node(root, value);
            break;

        case 'p':
            print_tree(root);
            cout<<endl;
            break;

        case 'd':
            delete_tree(root);
            break;

        case 'e':
            delete_tree(root);
            break;

        default:
            print_menu();
        }
    }
    while (mode != 'e');

    return 0;
}
