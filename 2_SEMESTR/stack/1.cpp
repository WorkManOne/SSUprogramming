#include <iostream>
#include <string>

using namespace std;

struct stack { // ���������� ���������� �����
	string inf;
	stack* next;
};

void push(stack*& h, string x) { // ���������� �����
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

string pop(stack*& h) { // ��������(� "������������") �������� � ������ �����
	string i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

stack* result(stack*& h, char c) { // ������� ��������� �����(�������)
	stack* res = NULL; //��������������� ����
	while (h) {
		string a = pop(h);
		if (a[a.length() - 1] != c)
			push(res, a);
	}
	return res;
}

void output(stack* h) { // ����� �����
	while (h)
		cout << pop(h) << ' ';
}

int main() {
	int n;
	cout << "n= ";  cin >> n; //����� ���������� ����
	stack* h = NULL;
	char c; //������ �� ������� �� ������ ������������� �����
	cout << "char = ";  cin >> c;
	string x; //�����
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, x);
	}
	stack* k = result(h, c); //����� ���� � �����������
	output(k);
}