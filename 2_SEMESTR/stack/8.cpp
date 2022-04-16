#include <iostream>
#include <string>

using namespace std;

struct stack { // объявление стека
	int inf;
	stack* next;
};

bool primeNum(int x) { //проверка на простотуу
	int c = 2;
	for (int i = 2; i < abs(x / 2) + 1; i++)
		if (x % i == 0)
			c++;
	if (c == 2)
		return true;
	else
		return false;
}

void push(stack*& h, int x) { //функция заполнения стека
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

int pop(stack*& h) { // удаляем (с "показыванием") элемент "сверху"
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

stack* result(stack*& h) { // функция обработки стека
	stack* res = NULL; //вспомогательный стек
	while (h) {
		int a = pop(h);
		if (primeNum(a) == false)
			push(res, a);
	}
	return res;
}

void output(stack*& h) { //вывод стека
	while (h)
		cout << pop(h) << ' ';
}

int main() {
	int n;
	cout << "n= ";  cin >> n; //ввели количество цифр
	stack* h = NULL;
	int x; //переменная для цифр
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, x);
	}
	stack* k = result(h); //новый стек с результатом
	output(k);
}