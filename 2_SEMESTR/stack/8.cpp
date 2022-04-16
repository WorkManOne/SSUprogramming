#include <iostream>
#include <string>

using namespace std;

struct stack { // ���������� �����
	int inf;
	stack* next;
};

bool primeNum(int x) { //�������� �� ���������
	int c = 2;
	for (int i = 2; i < abs(x / 2) + 1; i++)
		if (x % i == 0)
			c++;
	if (c == 2)
		return true;
	else
		return false;
}

void push(stack*& h, int x) { //������� ���������� �����
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

int pop(stack*& h) { // ������� (� "������������") ������� "������"
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

stack* result(stack*& h) { // ������� ��������� �����
	stack* res = NULL; //��������������� ����
	while (h) {
		int a = pop(h);
		if (primeNum(a) == false)
			push(res, a);
	}
	return res;
}

void output(stack*& h) { //����� �����
	while (h)
		cout << pop(h) << ' ';
}

int main() {
	int n;
	cout << "n= ";  cin >> n; //����� ���������� ����
	stack* h = NULL;
	int x; //���������� ��� ����
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, x);
	}
	stack* k = result(h); //����� ���� � �����������
	output(k);
}