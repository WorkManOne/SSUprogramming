#include <iostream>
#include <string>

using namespace std;

struct queue { //объявление строковой очереди
	string inf;
	queue* next;
};

void push(queue*& h, queue *&t, string x) { //функция заполнения очереди
	queue* r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		h = t = r;
	}
	else {
		t-> next = r;
		t = r;
	}
}

string pop(queue*& h, queue*& t) { // удаление(с "показыванием") элемента с начала очереди
	queue* r = h;
	string i = h->inf;
	h = h->next;
	if (!h) t = NULL;
	delete r;
	return i;
}

void result(queue*& h, queue*& t, string c) { // функциЯ обработки очереди(задание)
	queue* q = NULL;
	queue* e = NULL;
	while (h) {
		string a = pop(h,t);
		if (a != c)
			push(q, e, a);
	}
	h = q;
	t = e;
}

void output(queue* h, queue* t) { //вывод
	while (h)
		cout << pop(h,t) << ' ';
}

int main() {
	int n;
	cout << "n = ";  cin >> n;  //ввели количество слов
	queue* h = NULL;
	queue* t = NULL;
	string last; //последнее слово
	string x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, t, x); //ввели слова
	}
	if (t != NULL) last = t->inf; //"зафиксировали" последнее
	result(h, t, last); //обработали
	output(h,t);
	return 0;
}