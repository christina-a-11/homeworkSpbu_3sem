#include <iostream>
using namespace std;
struct BNode
{
	int data; // элемент данных
	BNode *left, *right; // указатели на сыновей
	BNode(int d, BNode *l = nullptr, BNode *r = nullptr) :
	data(d), left(l), right(r) {} // конструктор
};

void f_print (BNode* r, int skip = 0) // skip - отступ
{
	if (r == nullptr) return;
	f_print(r->right, skip + 3); // рекурсивный вызов для левого поддерева с отступом
    for (int i = 0; i < skip; ++i) // печать пробелов
    cout << ' '; // в количестве skip штук
    cout << r->data << endl; // печать данных узла и переход на следующую строчку
    f_print(r->left, skip + 3); // рекурсивный вызов для правого поддерева с отступом
}
int f_count (BNode * p)
{
	if (p == nullptr)
	{
		return 0;
	}
	return 1 + f_count(p->left) + f_count(p->right);
}

struct BTree
{
	BNode * root; // корень дерева
	BTree(BNode *p) : root(p) {}
	// конструктор по указателю на узел
	void print() // метод печати
	{
		f_print(root); // вызывает рекурсивную функцию
		cout << "_____________________" << endl << endl;
	}
	BNode * left_node()
	{
		BNode * t = root;
		while((t->left) != nullptr)
		{
			t = t -> left;
		}
		return t;
	}
	void del_left_node()
	{
		BNode * t = root;
		while((t->left)->left != nullptr)
		{
			t = t -> left;
		}
		t->left = (t->left)->right;
	}
	void put_left_son(int d)
	{
		BNode * t = left_node();
		t -> left = new BNode(d);
	}
	BNode * left_leaf()
	{
		BNode * t = left_node();
		while(t-> left != nullptr || t->right != nullptr)
		{
			if(t->left != nullptr)
			{
				t = t->left;
			}
			else
			{
				t = t->right;
			}
		}
		return t;
	}
	void del_left_leaf()
	{
		BNode * t = root;
		BNode * p = t;
		while(t-> left != nullptr || t->right != nullptr)
		{
			if(t->left != nullptr)
			{
				p = t;
				t = t->left;
			}
			else
			{
				p = t;
				t = t->right;
			}
		}
		if(p->left != nullptr)
		{
			p->left = nullptr;
		}
		else
		{
			p->right = nullptr;
		}
		delete t;
	}
	BNode * second_left_node()
	{
		BNode * t = root;
		BNode * r = root;
		while(t->left != nullptr || t->right != nullptr)
		{
			if(t->left != nullptr && t->right != nullptr)
			{
				r = t;
			}
			if(t->left != nullptr)
			{
				t = t->left;
			}
			else
			{
				t = t->right;
			}
		}
		if(r->right != nullptr)
		{
			r = r->right;
		}
		if(r == nullptr)
		{
			return nullptr;
		}
		BTree r1(r);
		return r1.left_leaf();
	}
	int count()
	{
		return f_count(root);
	}
	void scale(BNode * p)
	{
		if(p == nullptr)
		{
			return;
		}
		p->data = 3 * p->data;
		scale(p->left);
		scale(p->right);
	}
	int sum(BNode * p)
	{
		if(p == nullptr)
		{
			return 0;
		}
		return p->data + sum(p->left) + sum(p->right);
	}
	int count_neg(BNode * p)
	{
		if(p == nullptr)
		{
			return 0;
		}
		if(p->data >= 0)
		{
			return count_neg(p->left) + count_neg(p->right);
		}
		else
		{
			return 1 + count_neg(p->left) + count_neg(p->right);
		}
	}
};
int main()
{
	BNode *p13 = new BNode(13),
	*p7 = new BNode(-7),
	*p4 = new BNode(4),
	*p14 = new BNode(14, p13),
	*p6 = new BNode(-6, p4, p7),
	*p1 = new BNode(-1),
	*p10 = new BNode(-10, p14),
	*p3 = new BNode(3, p1, p6),
	*p8 = new BNode(8, p3, p10);
	BTree t(p8);
	t.print();
	cout << " left node = " << t.left_node()->data << endl;
	BNode *p55 = new BNode(55);
	p1->right = p55;
	t.print();
	t.del_left_node();
	t.print();
	t.put_left_son(90);
	t.print();
	cout << "left leaf = " << t.left_leaf()->data << endl;
	t.del_left_leaf();
	t.print();
	cout << "second left leaf = " << t.second_left_node()->data << endl;
	cout << "count = " << t.count() << endl;
	t.scale(p8);
	t.print();
	cout << "sum = " << t.sum(p8) << endl;
	cout << "count neg node = " << t.count_neg(p8) << endl;
	return EXIT_SUCCESS;
}
