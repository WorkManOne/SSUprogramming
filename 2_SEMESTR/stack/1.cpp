#include <iostream>
#include <string>

using namespace std;

struct stack { // объ€вление строкового стека
	string inf;
	stack* next;
};

void push(stack*& h, string x) { // заполнение стека
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

string pop(stack*& h) { // удаление(с "показыванием") элемента с начала стека
	string i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

stack* result(stack*& h, char c) { // функция обработки стека(задание)
	stack* res = NULL; //вспомогательный стек
	while (h) {
		string a = pop(h);
		if (a[a.length() - 1] != c)
			push(res, a);
	}
	return res;
}

void output(stack* h) { // вывод стека
	while (h)
		cout << pop(h) << ' ';
}

int main() {
	int n;
	cout << "n= ";  cin >> n; //ввели количество слов
	stack* h = NULL;
	char c; //символ на который не должны заканчиватьс€ слова
	cout << "char = ";  cin >> c;
	string x; //слово
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, x);
	}
	stack* k = result(h, c); //новый стек с результатом
	output(k);
}