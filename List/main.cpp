#include <iostream>

using namespace std;

struct node 
{
    int data;
    node * next;
    node(int d = 0, node * n = nullptr) : data(d), next(n) {}
};

node * copy(node * x);

struct list
{
    node * head;
    list() {head = nullptr;}
    list(const list & l)
     {
        head = copy(l.head);
     };
    list & operator= (const list & l)
    {
        if(this == &l)
        {
            return *this;
        }
       del();
       head = copy(l.head);
       return *this;
    };
    ~list()
    {
        del();
    }
    void add_first (int d)
    {
        node * t;
        t = new node(d, head);
        head = t;
    }
    void print()
    {
        node * tmp = head;
        while(tmp != nullptr)
        {
            cout << tmp -> data << " ";
            tmp = tmp -> next;
        }
    }
    node * last()
    {
        node * tmp = head;
        while(tmp -> next != nullptr)
        {
            tmp = tmp -> next;
        }
        return tmp;
    }
    node * prelast()
    {
        node * tmp = head;
        while(((tmp -> next) -> next) != nullptr)
        {
            tmp = tmp -> next;
        }
        return tmp;
    }
    node * get_prt(int n)
    {
        node * tmp = head;
        if(n <= 0)
        {
            return nullptr;
        }
        for(int i = 1; i < n; i++)
        {
            if(tmp == nullptr)
            {
                return tmp;
            }
            tmp = tmp->next;
        }
        return tmp;
    }
    void add_after_first (int d)
    {
        node *t = new node(d, head->next);
        head->next = t;
    }
    void add_last (int d)
    {
        node *t = new node(d,nullptr);
        node * tmp = head;
        while(tmp -> next != nullptr)
        {
            tmp = tmp -> next;
        }
        tmp -> next = t;
    }
    void del_last ()
    {
        node * tmp = head;
        while((tmp -> next)-> next != nullptr)
        {
            tmp = tmp -> next;
        }
        delete tmp -> next;
        tmp -> next = nullptr;
    }
   /* void insertp(int index, int d)
    {
        if(index == 1)
        {
            node * t = new node(d, head);
            head = t;
            return;
        }
        if(index == 2)
        {
            add_after_first(d);
            return;
        }
        node * tmp = head;
        int n = 1;
        while(tmp -> next != nullptr && n != index)
        {
            n++;
            tmp = tmp -> next;
        }
        if(index > n)
        {
            add_last(d);
            return;
        }
        else
        {
            node * t = new node(d, tmp -> next);
            tmp -> next = t;
        }
    }
   void del1(int index)
    {
        if(index == 1)
        {
            delete head;
            head = head -> next;
        }
        node * tmp = head;
        int n = 1;
        while(tmp -> next != nullptr && n != index)
        {
            n++;
            tmp = tmp -> next;
        }
        if(index > n)
        {
            del_last();
            return;
        }
        node *t = tmp;
        tmp = (tmp -> next) -> next;
        delete t -> next;
    }*/
    void del()
    {
        node * tmp = head;
        node * d = tmp;
        while((tmp) != nullptr)
        {
            d = tmp -> next;
            delete tmp;
            tmp = d;
        }
       head = nullptr;
    }
};
node * copy (node *x)
{
    if(x == nullptr)
    {
        return nullptr;
    }
    node * y = new node (x->data, copy(x->next));
    return y;
}
int main()
{
    list arr;
    arr.add_first(5);
    arr.add_first(4);
    arr.add_first(3);
    arr.add_first(2);
    arr.add_first(1);
    arr.print();
    cout << endl;
   // cout << arr.last()->data << endl;
    //cout << arr.prelast()->data << endl;
    cout << arr.get_prt(1)->data << endl;
    cout << arr.get_prt(2)->data << endl;
    cout << arr.get_prt(3)->data << endl;
    cout << arr.get_prt(5)->data << endl;
    arr.add_after_first(10);
    arr.print();
    cout << endl;
    arr.add_last(6);
    arr.print();
    cout << endl;
    arr.del_last();
    arr.print();
    cout << endl << "delete" << endl;
    arr.del();
    arr.print();
    arr.add_first(5);
    arr.add_first(4);
    arr.add_first(3);
    arr.add_first(2);
    arr.add_first(1);
    arr.print();
    cout << endl;
   // cout << copy(arr.head)->data;
    list arr2;
    arr2.add_first(8);
    arr2.add_first(7);
    arr2.add_first(6);
    arr2.print();
    arr2 = arr;
    cout<< endl << "print" << endl;
    arr.print();
    cout << endl;
    arr2.print();
    return EXIT_SUCCESS;
}
