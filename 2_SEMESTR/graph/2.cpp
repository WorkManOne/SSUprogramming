//Дан неориентированный граф. Удалить ребро, соединяющее вершины А и B.
#include <iostream>
#include <map>
#include <list>
#include <fstream>

using namespace std;

ifstream in("data.txt");

map<int, list<int>> MakeGr(bool orient)
{ //создание списка смежности графа
    map<int, list<int>> l_Adj;
    int x, y; // x<->y or x->y
    while (in.peek() != EOF)
    {
        in >> x >> y;
        auto it_x = l_Adj.find(x);
        bool fl = true;
        if (it_x != l_Adj.end())
        {
            list<int> a = it_x->second;
            for (auto iter = a.begin(); iter != a.end(); iter++)
                if (*iter == y)
                {
                    fl = false;
                    break;
                }
        }
        if (orient)
        {
            if (fl)
            {
                l_Adj[x].push_back(y);
                if (l_Adj.find(y) == l_Adj.end())
                {
                    l_Adj[y].push_back(0);
                    auto it = l_Adj.find(y);
                    it->second.erase(it->second.begin());
                }
            }
        }
        else if (fl)
        {
            l_Adj[x].push_back(y);
            l_Adj[y].push_back(x);
        }
    }
    return l_Adj;
}

void output(map<int, list<int>> gr)
{ //вывод графа
    for (auto it = gr.begin(); it != gr.end(); it++)
    {
        cout << "Vertex " << it->first << " : ";
        list<int> a = it->second;
        for (auto iter = a.begin(); iter != a.end(); iter++)
            cout << *iter << " ";
        cout << endl;
    }
}

int main()
{
    //так как граф неориентированный
    map<int, list<int>> Graph = MakeGr(0);
    cout << "Vertexs A and B: ";
    int a, b;
    cin >> a >> b;
    Graph[a].remove(b);
    Graph[b].remove(a);
    cout << "After delete: ";
    output(Graph);
    return 0;
}