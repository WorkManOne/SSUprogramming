//Дан ориентированный граф. Подсчитать полустепень исхода каждой вершины.
#include <iostream>
#include <map>
#include <list>
#include <fstream>

using namespace std;

ifstream in("data2.txt");

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
    //так как граф ориентированный
    map<int, list<int>> Graph = MakeGr(1);
    //полустепень исхода - число рёбер исходящих из этой вершины
    for (auto it1 = Graph.begin(); it1 != Graph.end(); it1++, cout << endl)
        cout << "Vertex " << it1->first << " : " << it1->second.size();
    return 0;
}