#include<iostream>
#include<string>
using namespace std;

struct stack { //стек
	char inf;
	stack* next;
};

void push(stack*& h, char x) { // добавление элемента
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

char pop(stack*& h) { // удаление элемента
	char i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

int prior(char ch) {
	if (ch == '(') {
		return 1;
	}
	if (ch == '+' || ch == '-') {
		return 2;
	}
	if (ch == '*' || ch == '/') {
		return 3;
	}
}
void postf(string str) { //функция вывода постфиксной записи
	stack* znak = NULL; //инициализация
	string rez = ""; //инициализация
	for (int i = 0; i < str.length(); i++) {//проход по строке с мат. выражением
		if (isdigit(str[i])) {//запись цифр
			rez += str[i];
		}
		else if (str[i] == '(') {//запись открывающей скобки
				push(znak, str[i]);
		}
		else {
			if (str[i] == ')') {//проверка на закрывающуюся
				char k = pop(znak);
				while (k != '(') {
					rez += k;
					k = pop(znak);
				}
			}
			else {
				if (znak == NULL && (prior(str[i]) == 2 || prior(str[i]) == 3)) { //сравнение приорететов знаков
					push(znak, str[i]); //если стек пустой, добавляем знак
				}
				else {
					if (prior(str[i]) == 2 || prior(str[i]) == 3) {// иначе сравниваем приоритеты занков
						char kPr = pop(znak);
						if (prior(str[i]) > prior(kPr)) {// если текущий знак имеет больший приоритет, чем тот что в стеке, то просто добавляем его в стек
							push(znak, kPr);
							push(znak, str[i]);
						}
						else {
							while (prior(str[i]) <= prior(kPr) && znak != NULL) {// иначе выносим все знаки приоритетнее его 
								rez += kPr;
								kPr = pop(znak);
							}
							if (znak == NULL) {// дописывем последний знак
								rez += kPr;
								push(znak, str[i]);
							}
							else { //дописывем знак перед считанным
								push(znak, kPr);
								push(znak, str[i]);
							}
						}
					}
				}
			}
		}
	}
	if (znak != NULL) {//проверка стека на пустоту
		char o = pop(znak);// если остался один знак
		if (znak == NULL) {
			rez += o; //переписали в конец
		}
		else {// дописываем последние знаки, если не один знак
			while (znak != NULL) {
				rez += o;
				char o = pop(znak);
				if (znak == NULL) {
					rez += o;
				}
			}
		}
	}
	for (int i = 0; i < rez.length(); i++) {//вывод
		cout << rez[i];
	}
	cout << endl;
}
int main() {
	string str;
	cin >> str;
    postf(str); //функция вывода в постфиксном виде
	return 0;
}
//5+(3+(2+4*(3-1)+2)/4+1)*4 тестик