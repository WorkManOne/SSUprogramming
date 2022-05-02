#include <iostream>

using namespace std;

struct list {
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) { // ���������� ������
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

void print(list*& h, list*& t) { // �����
	list* p = h;
	while (p) {
		cout << p->inf << ' ';
		p = p->next;
	}
	cout << endl;
}

void delNode(list*& h, list*& t, list* r) {//������� �������
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

list* findMax(list* h, list* t) {//������� ������������ ��������� 
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

int main() {
	int n;
	cout << "n = "; cin >> n; //���-�� ���������
	list* h = NULL;
	list* t = NULL;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, t, x);
	}
	int k = findMax(h, t)->inf; // ������� �������� ������������� ��������
	while (findMax(h, t)->inf == k) { // ���� ����������� ����� ��������
		delNode(h, t, findMax(h, t)); // ������� ��
	}
	print(h, t);
}