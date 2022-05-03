#include <iostream>
using namespace std;

struct tree { //идеально сбалансированное дерево
    int inf;
    tree *right;
    tree * left ;
};

tree *node(int x){ //добавление нового дерева
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    return n;
}

void create(tree *&tr, int n){ //создание идеально сбалансированного дерева 
    int x;
    if (n > 0){
        cout << "Input numbers: ";
        cin >> x;
        tr = node(x);
        int nl = n/2;
        int nr = n - nl - 1;
        create ( tr->left, nl);
        create ( tr->right,nr);
    }
}

void preorder(tree *tr){ //вывод
    if (tr) {
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

int orderleaf(tree *tr){//обработка 
    if (tr) {
        int s = 0; //с возвратом суммы узла 
        s+=orderleaf(tr->left); //и следующих за ним узлов
        s+=orderleaf(tr->right);
        if (!tr->left && !tr->right) s+=tr->inf; //если у этих узлов нет детей
        return s;
    }
    else return 0;
}

int main() {
    tree *n = NULL; //создали
    create(n,10); //ввели
    preorder(n); //вывели значения
    cout << endl;
    cout << orderleaf(n); //вывели сумму листьев
    return 0;
}