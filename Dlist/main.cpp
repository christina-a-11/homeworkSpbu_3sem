#include <iostream>

using namespace std;

bool check(int n);

struct dnode
{
    int data;
    dnode * next;
    dnode * prev; //предыдущий
    dnode(int d = 0, dnode * n = nullptr, dnode * p = nullptr) :
    data(d), next(n), prev(p) {}

};

dnode * copy(dnode * x)
{
    if(x == nullptr)
    {
        return nullptr;
    }
    dnode * y;
    y = new dnode(x->data, copy(x->next), nullptr);
    if(y->next != nullptr)
    {
    (y->next)->prev = y;
    }
    return y;
}

struct dlist
{
    dnode *head, *tail;
    dlist() { head = nullptr; tail = nullptr; }
    dlist(const dlist & l)
    {
        head = copy(l.head);
        
    }
    dlist & operator= (const dlist & l)
    {
        if(this == &l)
        {
            return *this;
        }
       del();
       head = copy(l.head);
       dnode * t = head;
       while((t->next)->next != nullptr)
       {
           t = t->next;
       }
       tail = t->next;
       return *this;
    }
    ~dlist() { del();};
    void add_first(int d)
    {
        dnode * t = new dnode(d, head, nullptr);
        if(head == nullptr)
        {
            head = t;
            tail = t;
        }
        else
        {
            head->prev = t;
            head = t;
        }
    }
    void print()
    {
        dnode * p = head;
        while(p != nullptr)
        {
            cout << p->data << " " << p << "\t";
            p = p->next;
        }
        cout << "\n";
    }
    void print_reverse()
    {
        dnode * p = tail;
        while(p != nullptr)
        {
            cout << p->data << " " << p->prev << "\t";
            p = p->prev;
        }
        cout << endl;
    }
    void Print()
    {
        if(head == nullptr)
        {
            cout << "empty\n";
        }
        print();
        print_reverse();
        cout << "\n";
    }
    void add_last(int d)
    {
        if(head == nullptr)
        {
            dnode* added = (d, nullptr, nullptr);
            head = added;
            tail = added;
            return;
        }
        if(head->next == nullptr)
        {
            dnode * added = new dnode(d, nullptr, head);
            head->next = added;
            tail = added; 
            return;
        }
        dnode * added = new dnode(d, nullptr, tail);
        tail->next = added;
        tail = added;
    }
    void add_after_first (int d)
    {
        if(head == nullptr)
        {
            return;
        }
        if(head->next == nullptr)
        {
            dnode * added = new dnode(d, nullptr, head);
            head->next = added;
            tail = added; 
            return;
        }
        dnode * added = new dnode(d, head->next, head);
        (head->next)->prev = added;
        head->next = added;
    }
    void del_last()
    {
        if(tail == nullptr)
        {
            return;
        }
        dnode* t = tail;
        (tail->prev)->next = nullptr;
        tail = tail->prev;
        delete t;
    }
    void del_second()
    {
        if(head == nullptr || head-> next == nullptr)
        {
            return;
        }
        dnode * t = head->next;
        head->next = (head->next)->next;
        (head->next)->prev = head;
        delete t;
    }
    void del_first()
    {
        if (head == nullptr)
        {
         cout << "List is empty";
         return;
        }
        if (head->next == nullptr)
        {
         delete head;
         head = nullptr;
         tail = nullptr;
         return;
        }
        dnode *t;
        t = head;
        head = head->next;
        head->prev = nullptr;
        delete t;
    }
    void insert(int n, int d)
    {
        int l = num();
        if(n == 0)
        {
            add_first(d);
        }
        else if(n == 1)
        {
            add_after_first(d);
        }
        else if(n == l)
        {
            add_last(d);
        }
        else
        {
            if(n > l)
            {
                cout << "error" << '\n';
                return;
            }
            dnode * tmp = head;
            int i = 1;
            while(head != nullptr && tmp->next != nullptr && i < n)
            {
                i++;
                tmp = tmp->next;
            }
            dnode * t = new dnode(d, tmp->next, tmp);
            (tmp->next)->prev = t;
            tmp->next = t;
        }
    }
    void delp(int n)
    {
        int l = num();
        if(n == 0)
        {
            del_first();
        }
        else if(n == 1)
        {
            del_second();
        }
        else if(n == l)
        {
            del_last();
        }
        else
        {
            if(n > l)
            {
                cout << "error" << '\n';
                return;
            }
            dnode* tmp = head;
            int i = 1;
            while(head != nullptr && tmp->next != nullptr && i < n)
            {
                i++;
                tmp = tmp->next;
            }
            (tmp->next)->prev = tmp->prev;
            (tmp->prev)->next = tmp->next;
            delete tmp;
        }
    };
    void reverse()
    {
        if(head == nullptr)
        {
            return;
        }
        if(head == tail)
        {
            return;
        }
        dnode * current = head; //текущий
        dnode * tmp = head; //для переприсваивания
        dnode * subsequent = tmp->next; //ссылка на след dnode
        int l = num();
        for(int i = 0; i < l; i++)
        {
            tmp = tmp->next;
            (current->next) = (current->prev);
            (current->prev) = tmp;
            current = subsequent;
            tmp = subsequent;
            if(i != l - 1)
            {
            subsequent = subsequent->next;
            }
        }
        tmp = head;
        head = tail;
        tail = tmp;
    }
    bool (*ptF)(int ) = &check;
    void remove_if(bool (*ptF)(int ))
    {
        int i = 0;
        int k = 0;
        dnode* temp = head;
        while(temp != nullptr)
        {
            dnode* ppp = temp;
            bool flag = false;
            if((*ptF)(i))
            {
                temp = temp->next;
                flag = true;
                delp(i - k);
                k++;
            }
            if(!flag)
            {
            temp = ppp->next;
            }
            i++;
        }    
    }
    void del()
    {
        int l = num();
        for(int i = 0; i < l; i++)
        {
            delp(0);
        }
    }
    int num()
    {
        int l = 1;
        dnode * tmp = head;
        while(head != nullptr && tmp->next != nullptr)
        {
            l++;
            tmp = tmp->next;
        }
        return l;
    }
};

bool check(int n)
{
    if(n % 2 == 0)
    {
    return true;
    }
    else
    {
     return !true;
    }
}

int main()
{
    dlist l;
    l.add_first(3);
    l.add_first(2);
    l.add_first(1);
    l.Print();
    //тестирование insert
    /*cout << "Добавить после 0 " << '\n';
    l.insert(0, -1);
    l.Print();
    cout << "Добавить после 1 " << '\n';
    l.insert(1, 2);
    l.Print();
    cout << "Добавить после 2 " << '\n';
    l.insert(2, 3);
    l.Print();
    cout << "Добавить в позицию l(длина списка) " << '\n';
    l.insert(6, 6);
    l.Print();
    cout << "Добавить после 3 " << '\n';
    l.insert(3, -33);
    l.Print();*/
    //тестировние delp
    /* 
    l.delp(0);
    l.Print();
    l.delp(2);
    l.Print();
    l.add_first(1);
    l.add_first(3);
    l.Print();
    l.delp(1);
    l.Print();
    */
   /*l.reverse();
   l.Print();
   bool (*ptF)(int ) = &check;
   l.remove_if(ptF);
   l.Print();*/
    l.del();
    l.Print();
    l.add_first(3);
    l.add_first(2);
    l.add_first(1);
    l.Print();
    dlist s;
    s.add_first(5);
    s.add_first(6);
    cout << "s = \n";
    s.Print();
    s = l;
    cout << " l = \n";
    l.Print();
    cout << " s = \n";
    s.Print();
   return EXIT_SUCCESS;
}
