#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    double data;
    Node* next;
};

struct List
{
    Node* head;
    int length;
};

//wykaz dostepnych operacji na liscie
List* create_list ();
void append_to_list (List* l, double data);
void prepend_to_list (List* l, double data);
void print_list (List* l);
double get_element (List* l, int position, bool* err);
void insert_element (List* l, double data, int position);
void delete_element (List* l, int position);
void delete_last_element (List* l);
void clear_list (List* l);
void append_from_file (List* l, string path);
bool is_in_list (List* l, double data);


List* create_list ()
{
    List* ptr = new List;
    ptr->head = NULL;
    ptr->length = 0;

    return ptr;
}

void append_to_list (List* l, double data)
{
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;

    if (l->head == NULL)
    {
        l->head = ptr;
    }
    else
    {
        Node* temp = l->head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = ptr;
    }
    l->length += 1;
}

void prepend_to_list (List* l, double data)
{
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;

    if (l->head == NULL)
    {
        l->head = ptr;
    }
    else
    {
        ptr->next = l->head;
        l->head = ptr;
    }
    l->length += 1;
}

void print_list (List* l)
{
    if (l->head == NULL)
    {
        return;
    }

    Node* ptr = l->head;

    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

double get_element (List* l, int position, bool* err)
{
    if (l->head == NULL)
    {
        *err = true;
        return 0;
    }

    if (l->length < position)
    {
        *err = true;
        return 0;
    }

    Node* ptr = l->head;

    for (int i=1; i<position; i++)
    {
        ptr = ptr->next;
    }

    *err = false;
    return ptr->data;
}

bool is_in_list (List* l, double data)
{
    if (l->head == NULL)
    {
        return false;
    }
    else
    {
        Node* ptr = l->head;
        while (ptr != NULL)
        {
            if (ptr->data == data)
            {
                return true;
            }
            ptr=ptr->next;
        }
    }
    return false;
}

void clear_list (List* l)
{
    if (l->head == NULL)
    {
        return;
    }

    Node* ptr = l->head;
    Node* temp = l->head;

    do
    {
        temp=temp->next;
        delete ptr;
        ptr = temp;
    }
    while (temp != NULL);

    l->head = NULL;
    l->length = 0;
}

void delete_last_element (List* l)
{
    if (l->head == NULL)
    {
        return;
    }

    Node* ptr = l->head;

    while ( (ptr->next)->next != NULL)
    {
        ptr=ptr->next;
    }

    Node* temp = ptr->next;
    delete temp;
    ptr->next = NULL;

    l->length -= 1;
}

void delete_element (List* l, int position)
{
    if (position > l->length)
    {
        return;
    }

    if(position == 1)
    {
        Node* ptr = l->head;
        l->head = ptr->next;
        delete ptr;
        l->length -= 1;
    }
    else
    {
        Node* ptr = l->head;
        Node* temp = l->head;

        for (int i=0; i<position-2; i++)
        {
            ptr=ptr->next;
        }
        temp = ptr->next;
        ptr->next = (ptr->next)->next;
        delete temp;

        l->length -= 1;
    }
}

void append_from_file (List* l, string path)
{
    ifstream file (path.c_str());
    double number = 0;
    Node* ptr;

    if (!file.is_open())
    {
        cout<<"error";
        return;
    }
    else
    {
        if (l->head == NULL)
        {
            l->head = new Node;
            l->head->next = NULL;
            file>>number;
            l->head->data = number;
            ptr = l->head;
            l->length += 1;
        }
        else
        {
            ptr = l->head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
        }

        while(!file.eof())
        {
            ptr->next = new Node;
            ptr=ptr->next;
            ptr->next = NULL;

            file>>number;
            ptr->data = number;

            l->length += 1;
        }
        file.close();
    }
}

void insert_element (List* l, double data, int position)
{
    Node* ptr = NULL;

    if(position == 1)
    {
        ptr = new Node;
        ptr->data = data;
        ptr->next = l->head;
        l->head = ptr;
        l->length += 1;
        return;
    }

    if(l->head == NULL)
    {
        l->head = new Node;
        l->head->data = data;
        l->head->next = NULL;
        l->length += 1;
    }
    else
    {
        ptr = l->head;

        if(position > l->length)
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new Node;
            ptr = ptr->next;
            ptr->next = NULL;
            ptr->data = data;
            l->length += 1;
        }
        else
        {

            for (int i=1; i<position-1; i++)
            {
                ptr = ptr->next;
            }
            Node* temp = new Node;
            temp->data = data;
            temp->next = ptr->next;
            ptr->next = temp;

            l->length += 1;
        }
    }
}

int main()
{
    //tworze liste
    List* my_list = create_list();

    ofstream plik;
    plik.open ("dane.txt");
    plik<<56.4<<" "<<3444;
    plik.close();

    append_from_file(my_list,"dane.txt");
    print_list(my_list);

    //dodaje elementy na koniec
    append_to_list(my_list, 5.4);
    append_to_list(my_list, 2.4);
    append_to_list(my_list, 3.4);
    print_list(my_list);

    //dodaje element na wybranej pozycji
    insert_element(my_list, 99.9, 2);
    print_list(my_list);

    //dodaje elementy na poczatek
    prepend_to_list(my_list, 60.9);
    prepend_to_list(my_list, 45.9);
    print_list(my_list);

    //usuwa ostatni element
    delete_last_element(my_list);
    print_list(my_list);

    //usuwa element na pozycji 3
    delete_element(my_list, 3);
    print_list(my_list);

    //usuwa pierwszy element
    delete_element(my_list, 1);
    print_list(my_list);

    //sprawdza czy podany element istnieje, jesli tak to go wyswietla
    bool* error = new bool;
    double wynik;
    wynik=get_element(my_list, 2, error);
    if (*error == true)
    {
        cout<<"element 2 does not exist"<<endl;
    }
    else
    {
        cout<<"element nr 2="<<wynik<<endl;
    }

    //sprawdza czy podany element istnieje, jesli tak to go wyswietla
    wynik=get_element(my_list, 69, error);
    if (*error == true)
    {
        cout<<"element 69 does not exist"<<endl;
    }
    else
    {
        cout<<"element nr 69 = "<<wynik<<endl;
    }

    //sprawdza czy istnieje element zawierajacy liczbe 60.9
    bool istnieje;
    istnieje = is_in_list(my_list, 60.9);
    cout<<istnieje<<endl;

    //sprawdza czy istnieje element zawierajacy liczbe 645
    istnieje = is_in_list(my_list, 645);
    cout<<istnieje<<endl;

    // usuwa wszystkie elementy w liscie
    clear_list(my_list);
    print_list(my_list);

    //usuwa sama liste (zwalnia pamiec)
    delete my_list;
    my_list = NULL;

    return 0;
}

