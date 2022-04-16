#include <iostream>
#include <math.h>
#include <vector> //подключение библиотеки вектора
#include <list> //подключение библиотеки списка
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;



vector<int> task1(vector<int>r) {
	nth_element(r.begin(), r.begin() + 5, r.end());
	return r;
}

list<int> task2(list<int>w) {
	rotate(w.begin(), max_element(w.begin(), w.end()), w.end());
	return w;
}

vector<int> task3(vector<int>r) {
	make_heap(r.begin(), r.end());
	return r;
}


int task4(list<int>w1, list<int>w2) {
	return inner_product(w1.begin(), w1.end(), w2.begin(), 0);
}

set<char> task5(string s) {
	set<char> ic;
	for (int i = 0; i < s.length(); i++) {
		ic.insert(s[i]);
	}
	return ic;
}

int main() {
	setlocale(LC_ALL, "rus");
	vector<int>a{ 1,5,7,8,2,6,9,3,13,4 };
	vector<int>a1{ 1,5,7,8,2,6,9,3,13,4 };
	list<int>b{ 12,13,17,4,8,9,3,2,14,1 };
	list<int>b1{ 12,13,17,4,8,9,3,2,14,1 };
	list<int>b2{ 41,11,19,1,2,5,6,17,21,36 };
	set<char>c;
	string str = "Ivanov Ivan Ivanovich";
	//------------------------------------------------------------------------
	cout << "1 задача:" << endl;
	cout << "initial vector: ";
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	a = task1(a);
	cout << "Changed vector: ";
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
	//------------------------------------------------------------------------	
	cout << "2 задача:" << endl;
	cout << "initial vector: ";
	for (list<int>::iterator it = b.begin(); it != b.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	b = task2(b);
	cout << "Changed vector: ";
	for (list <int>::iterator it = b.begin(); it != b.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
	//------------------------------------------------------------------------
	cout << "3 задача:" << endl;
	cout << "initial vector: ";
	for (vector<int>::iterator it = a1.begin(); it != a1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	a1 = task3(a1);
	cout << "Changed vector: ";
	for (vector<int>::iterator it = a1.begin(); it != a1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
	//------------------------------------------------------------------------
	cout << "4 задача:" << endl;
	cout << "initial vector1: ";
	for (list<int>::iterator it = b1.begin(); it != b1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "initial vector2: ";
	for (list<int>::iterator it = b2.begin(); it != b2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "Result: " << task4(b1, b2);;
	cout << endl << endl;
	//------------------------------------------------------------------------
	cout << "5 задача:" << endl;
	cout << "initial set: " << str << endl;
	c = task5(str);
	cout << "Changed set: ";
	for (set<char>::iterator it = c.begin(); it != c.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

