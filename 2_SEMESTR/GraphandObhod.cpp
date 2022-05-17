#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>


using namespace std;

struct stack { //стек
    int inf;
    stack* next;
};

struct queue { //очередь
    int inf;
    queue* next;
};


void push(queue*& h, queue*& t, int x) { //вставка элемента в очередь
    queue* r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        h = t = r;
    }
    else {
        t->next = r;
        t = r;
    }
}

int pop(queue*& h, queue*& t) { //удаление элемента из очереди
    queue* r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

void push(stack*& h, int x) {   //вставка в стек
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack*& h) {   //удаление с доставанием из стека
    int i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}


void reverse(stack*& h) { //обратный стек
    stack* b = NULL;
    while (h) push(b, pop(h));
    h = b;
}


int finding(vector<int> a, int f) { //ищем в векторе номер элемента равного значению
    int x = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == f) x = i; break;
    }
    return x;
}


void in_depth(vector<int> &a, int n, vector<pair<int, vector<int>>> gr, int x = 0) {
    stack* h = NULL;
    a[x] = 1;
    push(h, x);
    cout << x << " ";
    bool fl = false;
    while (h) {
        x = h->inf;
        int y;
        for (int i = 0; i < gr[x].second.size(); ++i) {
            if (a[gr[x].second[i]] == 0) {
                y = gr[x].second[i];
                fl = true;
                break;
            }
        }
        if (fl == true) {
            a[y] = 1;
            push(h, y);
            cout << y << " ";
            fl = false;
        }
        else {
            pop(h);
        }
    }
    if (find(a.begin(), a.end(), 0) != a.end()) in_depth(a, n, gr, finding(a, 0));
}


void in_width(vector<int> &a, int n, vector<pair<int, vector<int>>> gr, int x = 0) {
    queue* h = NULL, * t = NULL;
    a[x] = 1;
    push(h, t, x);
    cout << x << " ";
    while (h && t) {
        x = pop(h, t);
        for (int i = 0; i < gr[x].second.size(); ++i) {
            if (a[gr[x].second[i]] == 0) {
                int y = gr[x].second[i];
                a[y] = 1;
                push(h, t, y);
                cout << y << " ";
            }
        }
    }
    if (find(a.begin(), a.end(), 0) != a.end()) in_width(a, n, gr, finding(a, 0));
}


int main() {
    int n = 7;
    pair<int, vector<int>> p;
    vector<pair<int, vector<int>>> v = {
            {0, {1, 2, 4, 5}},
            {1, {0, 3}},
            {2, {0, 5}},
            {3, {1}},
            {4, {0, 6}},
            {5, {0, 2, 6}},
            {6, {4, 5}}
    };
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(0);
    }
    cout << "Width: ";
    in_width(a, n, v);
    cout << endl;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        b.push_back(0);
    }
    cout << "Depth: ";
    in_depth(b, n, v);

    return 0;
}