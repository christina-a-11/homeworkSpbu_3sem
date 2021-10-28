#include <iostream>
using namespace std;
struct BNode
{
	int data; // элемент данных
	BNode *left, *right; // указатели на сыновей
	BNode(int d, BNode *l = nullptr, BNode *r = nullptr) :
		data(d), left(l), right(r) {} // конструктор
};
void f_print(BNode *r, int d = 0) // d - смещение
{
	if (r == nullptr) return;
	f_print(r->right, d + 3);
	for (int i = 0; i<d; i++)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, d + 3);
}
struct BTree
{
	BNode * root; // корень дерева
	BTree(BNode *p) : root(p) {}
	// конструктор по указателю на узел
	void print() // метод печати
	{
		f_print(root); // вызывает рекурсивную функцию
	}
};
int main()
{
	BNode *p13 = new BNode(13),
		*p7 = new BNode(7),
		*p4 = new BNode(4),
		*p14 = new BNode(14, p13),
		*p6 = new BNode(6, p4, p7),
		*p1 = new BNode(1),
		*p10 = new BNode(10, p14),
		*p3 = new BNode(3, p1, p6),
		*p8 = new BNode(8, p3, p10);
	BTree t(p8);
	t.print();
	system("pause>nul");
	return EXIT_SUCCESS;
}
