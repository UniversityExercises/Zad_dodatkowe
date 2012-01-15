#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* create_list(int x)  // tworzy pierwszy element listy (glowe) i zwraca jej adres
{
    Node *head = new Node;
    head->data = x;
    head->next = NULL;
    return head;
}

void go_to_next (Node *&ptr) // przesuwa wskaznik na nastepny el. listy
{
    if(ptr->next!=NULL)
    ptr=ptr->next;
}

void add_element (Node *cur, int x) // dodaje element na koncu listy
{
    while (cur->next!=NULL)
    {
        go_to_next(cur);
    }

    Node *ptr = new Node;
    ptr->data = x;
    ptr->next = NULL;

    cur->next = ptr;
}

void print_list (Node *ptr) // drukuje liste
{
    while (ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

void delete_list (Node *&ptr) // niszczy liste
{
    Node *tmp;
    while (ptr!=NULL)
    {
    tmp=ptr;
    ptr=ptr->next;
    delete tmp;
    }
}

void go_to_beginning (Node *head, Node *&ptr) // przesuwa wskaznik na poczatek listy
{
    ptr=head;
}

void delete_next_element (Node *&ptr, int position) // niszczy el. nastepny po wskazanym
{
    for (int i=0; i<position; i++)
    {
        if(ptr!=NULL)
        ptr=ptr->next;
        else
        return;
    }
    Node *tmp=ptr->next;
    ptr->next=tmp->next;
    delete tmp;
}

void add_next_element (Node *&ptr, int position, int x) // dodaje el. po wskazanym
{
     for (int i=0; i<position; i++)
    {
        if(ptr!=NULL)
        ptr=ptr->next;
        else
        return;
    }
     Node *tmp=ptr->next;
     Node *new_el = new Node;
     ptr->next = new_el;
     new_el->data = x;
     new_el->next = tmp;
}

int main()
{
    Node* glowa = create_list(5);
    Node* cur = glowa;

    add_element(glowa, 11);


    return 0;
}
