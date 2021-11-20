#include <iostream>
using namespace std;

struct SNode
{
    int key;
	int data;
	SNode *left, *right; 
	SNode(int k, int d, SNode *l = nullptr, SNode *r = nullptr) :
	key(k), data(d), left(l), right(r) {} 
};

void f_print(SNode* r, int d = 0)
{
    if (r == nullptr) return;
    f_print(r->right, d + 3);
    for (int i = 0; i < d; i++)
    cout << ' ';
    cout << r->key << "(" << r->data << ")" << endl;
    f_print(r->left, d + 3);
}

struct STree
{
    SNode* root;
    STree (SNode* p) : root(p) {}
    void print()
    {
        cout << "______________\n\n";
        f_print(root);
        cout << "______________\n\n";
    }
    SNode * findrec(SNode * p, int key)
    {
        if(p == nullptr)
        {
            return p;
        }
        else if(p->key == key)
        {
            return p;
        }
        else if(p->key > key)
        {
            return findrec(p->left, key);
        }
        else if (p->key < key)
        {
            return findrec(p->right, key);
        }
    }
    SNode * findwhile(SNode * p, int key)
    {
        while(p != nullptr)
        {
            if(p->key == key)
            {
                return p;
            }
            else if(p->key > key)
            {
                p = p->left;
            }
            else if(p->key < key)
            {
                p = p->right;
            }
        }
        return nullptr;
    }
    void pushrec(SNode *& p, int key, int data)
    {
        if(p->key > key)
        {
            if(p->left == nullptr)
            {
                p->left = new SNode(key, data);
                return;
            }
            else
            {
                return pushrec(p->left, key, data);
            }
        }
        if(p->key < key)
        {
            if(p->right == nullptr)
            {
                p->right = new SNode(key, data);
                return;
            }
            else
            {
                return pushrec(p->right, key, data);
            }
            
        }
        if(p->key == key)
        {
            cout << "error\n";
            return;
        }
    }
    void pushwhile(SNode *& p, int key, int data)
    {
        while(p!= nullptr)
        {
            if(p->key < key)
            {
                if(p->right == nullptr)
                {
                    p->right = new SNode(key, data);
                    return;
                }
                else
                {
                    p = p->right;
                    continue;
                }
            }
            if(p->key > key)
            {
                if(p->left == nullptr)
                {
                    p->left = new SNode(key, data);
                    return;
                }
                else
                {
                    p = p->left;
                    continue;
                }
            }
            if(p->key == key)
            {
                cout <<"error\n";
                return;
            }
        }
    }
};

int main()
{
    SNode* p9 = new SNode(13, 130),
    * p8 = new SNode(7, 70),
    * p7 = new SNode(4, 40),
    * p6 = new SNode(14, 140, p9),
    * p5 = new SNode(6, 60, p7, p8),
    * p4 = new SNode(1, 10), 
    * p3 = new SNode(10, 100, nullptr, p6),
    * p2 = new SNode(3, 30, p4, p5),
    * p1 = new SNode(8, 80, p2, p3);
    STree t(p1);
    t.print();
    cout << t.findrec(p1, 6)->key << "(" << t.findrec(p1, 6)->data << ")" << endl;
    cout << t.findwhile(p1, 7)->key << "(" << t.findwhile(p1, 7)->data << ")" << endl;
    t.pushwhile(p1, 11, 110);
    t.pushrec(p1, 5, 50);
    t.print();
    return EXIT_SUCCESS;
}
