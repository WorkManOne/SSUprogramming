#include <iostream>

using namespace std;

struct list {
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) { // заполнение списка
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		r->prev = NULL;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void print(list*& h, list*& t) { // вывод
	list* p = h;
	while (p) {
		cout << p->inf << ' ';
		p = p->next;
	}
	cout << endl;
}

void delNode(list*& h, list*& t, list* r) {//удаляем элемент
	if (r == h && r == t) {
		h = t = NULL;
	}
	else if (r == h) {
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) {
		t = t->prev;
		t->next = NULL;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}

list* findMin(list* h, list* t) {//находим минимальный первый
	list* p = h;
	int mn = p->inf;
	while (p) {
		if (p->inf < mn) {
			mn = p->inf;
		}
		p = p->next;
	}
	p = h;
	while (p) {
		if (p->inf == mn) break;
		p = p->next;
	}
	return p;
}

void sort(list*& h, list*& t) { // сортировка выбором (поиск минимального)
	list* h1 = NULL; list* t1 = NULL;
	while (h) {
		push(h1, t1, findMin(h,t)->inf);
		delNode(h, t, findMin(h, t));
	}
	h = h1;
	t = t1;
}

int main() {
	int n;
	cout << "n = "; cin >> n; //кол-во элементов
	list* h = NULL;
	list* t = NULL;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, t, x);
	}
	sort(h, t);
	print(h, t);
}