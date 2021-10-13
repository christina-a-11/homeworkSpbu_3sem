#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Subscriber
{
    int num;
    string name;
    string sity;
    string street;
    string numhouse;
    Subscriber(int n = 0, string nm = "Petr", string s = "Moscow", string st = "First", string nh = "1") :
    num(n), name(nm), sity(s), street(st), numhouse(nh) {}
    Subscriber(const Subscriber & a)
    {
        num = a.num;
        name = a.name;
        sity = a.sity;
        street = a.street;
        numhouse = a.numhouse;
    }
    string address()
    {
        string ar;
        ar += sity;
        ar += " ";
        ar += street;
        ar += " ";
        ar += numhouse;
        return ar;
    }
};
ostream &operator << (ostream &st, Subscriber a)
{
    return st << a.name << " " << a.address() << '\n';
}
istream &operator >> (istream &st, Subscriber & a)
{
    st >> a.num >> a.name >> a.sity >> a.street >> a.numhouse;
    return st;
}
ostream &operator << (ostream &st, list<Subscriber> l)
{
    for (auto x : l)
    {
        st << x << '\n';
    }
    return st;
}
istream &operator >> (istream &st, list<Subscriber> &l)
{
    Subscriber x;
    while(st >> x)
    {
        l.push_back(x);
    }
    return st;
}

void printmenu()
{
    cout << "1 - добавить абонента\n";
    cout << "2 - удалить абонента по номеру\n";
    cout << "3 - распечатать имя и адрес абонента по номеру\n";
    cout << "0 - выйти из программы\n";
}

int main()
{
    list <Subscriber> l;

    int p = 0;
    printmenu();
    cin >> p;
    while(p != 0)
    {
        if(p == 1)
        {
            Subscriber a;
            cin >> a;
            l.push_back(a);
        }
        else if(p == 2)
        {
            int tmp = 0;
            cin >> tmp;
            list <Subscriber> ::iterator i = l.begin();
            int n = 0;
            for(auto x : l)
            {
                n++;
                if(x.num == tmp)
                {
                    break;
                }
            }
            advance(i, n - 1);
            l.erase(i);
        }
        else if(p == 3)
        {
            int tmp = -1;
            cin >> tmp;
            for(auto x: l)
            {
                if(x.num == tmp)
                {
                    cout << x;
                }
            }
        }
        printmenu();
        cin >> p;
    }
    cout << l;
    return EXIT_SUCCESS;
}
