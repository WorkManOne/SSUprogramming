#include<iostream>
using namespace std;

//Папа Карло посадил дерево, из дерева вырастил сына, а из сына построил дом. Вот это мужик!

struct tree //дерево
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

tree* node(int x) { //функция ввода нового узла со значением x
	tree * n = new tree;
	n-> inf = x;
	n-> parent = NULL;
	n-> right = NULL;
	n-> left = NULL;
	return n;
}

void preorder(tree* tr) { // прямой обход (К-Л-П) (вывод)
	if (tr) {
		cout << tr-> inf << " "; //выводим корень
		preorder(tr-> left); //уходим на вывод левого
		preorder(tr-> right); //также с правым
	}
}

void insert(tree*& tr, int x) {//вставка
	tree * n = node(x);
	if (!tr) tr = n; //если дерево пустое - корень
	else {
		tree * y = tr;
		while (y) { //ищем куда вставлять
			if (n-> inf > y-> inf) //правая ветка
			if (y-> right) y = y-> right;
			else {
				n-> parent = y; //узел становится правым ребенком
				y-> right = n;
				break;
			}
			else if (n-> inf < y->inf)//левая ветка
			if (y-> left) y = y-> left;
			else {
				n-> parent = y;//узел становится левым ребенком
				y-> left = n;
				break;
			}
		}
	}
}

tree* Min(tree* tr) {//поиск min (нагло скопированный с теории код)
	if (!tr-> left) return tr;//нет левого ребенка
	else return Min(tr-> left);//идем по левой ветке до конца
}


tree* find(tree* tr, int x) {//поиск (нагло скопированный с теории код)
	if (!tr || x == tr-> inf)//нашли или дошли до конца ветки
		return tr;
	if (x < tr->inf)
		return find(tr-> left, x);//ищем по левой ветке
	else
		return find(tr-> right, x);//ищем по правой ветке
}


tree* Next(tree* tr, int x) {//поиск следующего (нагло скопированный с теории код)
	tree * n = find(tr, x);
		if (n-> right)//если есть правый ребенок
		return Min(n-> right);//min по правой ветке
	tree * y = n-> parent; //родитель
	while (y && n == y-> right) {//пока не дошли до корня или узел - правый ребенок
		n = y;//идем вверх по дереву
		y = y-> parent;
	}
	return y;//возвращаем родителя
}


void Delete(tree*& tr, tree* v) {//удаление узла (нагло скопированный с теории код)
	tree * p = v-> parent;
	if (!p) tr = NULL; //дерево содержит один узел
	else if (!v-> left && !v-> right) {//если нет детей
		if (p-> left == v) //указатель у родителя меняем на NULL
			p-> left = NULL;
		if (p-> right == v)
			p-> right = NULL;
		delete v;
	}
	else if (!v-> left || !v-> right) {//если только один ребенок
		if (!p) { //если удаляем корень, у которого 1 ребенок
			if (!v-> left) { //если есть правый ребенок
				tr = v-> right; //он становится корнем
				v-> parent = NULL;
			}
			else { //аналогично для левого
				tr = v-> left;
				v-> parent = NULL;
			}
		}
		else {
			if (!v-> left) {//если есть правый ребенок
				if (p-> left == v) //если удаляемый узел явл. левым ребенком
					p-> left = v-> right; //ребенок удаляемого узла становится левым ребенком своего "деда"
					else
					p-> right = v-> right; ////ребенок удаляемого узла становится правым ребенком своего "деда"
					v-> right-> parent = p; //родителем ребенка становится его "дед"
			}
			else {//аналогично для левого ребенка
				if (p-> left == v)
					p-> left = v-> left;
				else
					p-> right = v-> left;
				v-> left-> parent = p;
			}
			delete v;
		}
	}
	else {//есть оба ребенка
		tree * succ = Next(tr, v-> inf);//следующий за удаляемым узлом
		v-> inf = succ-> inf; //присваиваем значение
		if (succ-> parent-> left == succ) {//если succ левый ребенок
			succ-> parent-> left = succ-> right; //его правый ребенок становится левым ребенком своего "деда"
				if (succ-> right) //если этот ребенок существует
				succ-> right-> parent = succ-> parent; //его родителем становится "дед"
		}
		else {//аналогично если succ - правsq ребенок
			succ-> parent-> right = succ-> right;
			if (succ-> right)
				succ-> right-> parent = succ-> parent;
		}
		delete succ;
	}
}

int orderh(tree* tr, int c) { //нахождение высоты на вход идет счетчик и узел
	if (tr) { //если узел есть то ок
		c++; //прибавляем 1 счетчику
		c = max(orderh(tr->left, c),orderh(tr->right, c)); //пробуем рекурсивно ходить влево и вправо, беря только наибольшее количество узлов (проще рассмотреть микропример работы кода)
		return c; //возвращем максимальное количество узлов
	}
	else { //если узла нет то счетчик не увеличивается
		return c;
	}
}
//5 2 3 6 7 4 12 18 21 9 8 13 10 (11) 0
int main() {
	int x = 0; //счетчик высоты
	int t;
	cout << "Input numbers (end input with 0): ";
	cin >> t;
	tree* n = node(t);
	while (true) { //ввод пока не встретится 0 (для удобства)
		cout << "Input numbers (end input with 0): ";
		cin >> t;
		if (t == 0) break;
		else insert(n, t);
	}
	preorder(n); //выводим дерево
	cout << endl;
	x=orderh(n, x)-1; //обрабатываем и считаем высоту
	cout << x;
	return 0;
}