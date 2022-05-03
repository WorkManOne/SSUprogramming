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

void preorder(tree *tr){  //вывод
    if (tr) {
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

void orderlvl(tree *tr, int c, int lvl){ //обработка (вывод уровня)
    if (tr) {
        if (c==lvl) { //если счетчик уровня равен уровню на котором находимся
            cout << tr->inf << " "; //то выводим значение
            return; //выходим не переходя к след уровням
        }
        orderlvl(tr->left, c+1, lvl); //иначе переходим к след узлу прибавляя счетчик
        orderlvl(tr->right,c+1,lvl); //иначе переходим к след узлу прибавляя счетчик
    }
}

int main() {
    cout << "What LVL u need?: ";
    int lvl;
    cin >> lvl; //ввели нужный уровень
    tree *n = NULL; //создали
    create(n,10); //ввели дерево с элементами
    preorder(n); //вывели
    cout << endl;
    orderlvl(n, 0, lvl); //вывели элементы уровня
    return 0;
}