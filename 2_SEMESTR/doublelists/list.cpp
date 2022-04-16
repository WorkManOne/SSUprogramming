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

void printRev(list*& h, list*& t) { // обратный вывод
	list* p = t;
	while (p) {
		cout << p->inf << ' ';
		p = p->prev;
	}
	cout << endl;
}

void findChet(list* h, list* t) { // поиск последнего четного
	list* p = t;
	while (p) {
		if (p->inf % 2 == 0) {
			cout << "Last chet = " << p->inf;
			break;
		}
		else
			p = p->prev;
	}
	cout << endl;
}

list* findmin(list* h, list* t) {//находим минимальный первый
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

void del(list*& h, list*& t, list* r) {//удаляем элемент
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

list* findmax(list* h, list* t) {//находим максимальный последний 
	list* p = t;
	int mx = p->inf;
	while (p) {
		if (p->inf > mx) {
			mx = p->inf;
		}
		p = p->prev;
	}
	p = t;
	while (p) {
		if (p->inf == mx) break;
		p = p->prev;
	}
	return p;
}

void insert(list*& h, list*& t, list* r) {//вставляем элемент
	list* p = new list;
	p->inf = 0;
	if (r == t) {
		p->prev = r;
		p->next = NULL;
		r->next = p;
		t = p;
	}
	else {
		r->next->prev = p;
		p->next = r->next;
		p->prev = r;
		r->next = p;
	}
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
	cout << "1 task: ";
	printRev(h, t);
	cout << "2 task: ";
	findChet(h, t);
	cout << "3 task: ";
	del(h, t, findmin(h, t)); //удаляем первый минимальный
	print(h, t);
	cout << "4 task: ";
	insert(h, t, findmax(h, t)); //вставляем после последнего максимального
	print(h, t);
}