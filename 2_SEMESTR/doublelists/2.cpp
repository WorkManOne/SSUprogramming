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
	cout<<  endl;
}

void chnech(list*& h, list*& t) { //функция распределения сначала чет потом нечет
	list* h1 = NULL; //создали двузвязные списки для четных и нечетных чисел
	list* t1 = NULL;
	list* h2 = NULL;
	list* t2 = NULL;
	while (h) { //в зависимости от случая записываем в тот или иной двузвязные список
		if (h->inf % 2 == 0) {
			push(h2, t2, h->inf);
		}
		else {
			push(h1, t1, h->inf);
		}
		h = h->next;
	}
	h = h2; //мерджим списки
	t2->next = h1;
	h1->prev = t2;
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
	chnech(h, t);
	print(h, t);
	return 0;
}
