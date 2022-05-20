// Дан неориентированный граф. Вывести количество вершин, смежных с данной.
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

int main()
{
    map<int, list<int>> Graph = MakeGr(0);
    int vertex, amount = 0;
    cout << "Vertex: ";
    cin >> vertex;
    cout << "Amount of adjacent vertices: ";
    cout << Graph[vertex].size();
    return 0;
}