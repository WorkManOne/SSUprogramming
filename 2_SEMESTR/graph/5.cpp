//Дан ориентированный граф. Вывести все истоки графа.
#include <iostream>
#include <map>
#include <list>
#include <queue>
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

vector<int> BFS(map<int, list<int>> gr, int v, bool *&visited)
{ //обход в глубину
    visited[v] = true;
    queue<int> q;
    q.push(v);
    vector<int> path;
    path.push_back(v);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto it = gr.begin(); it != gr.end(); it++)
        {
            if (it->first == u)
            {
                list<int> a = it->second;
                for (auto iter = a.begin(); iter != a.end(); iter++)
                    if (!visited[*iter])
                    {
                        visited[*iter] = true;
                        path.push_back(*iter);
                        q.push(*iter);
                    }
                break;
            }
        }
    }
    return path;
}

int main()
{
    //так как граф ориентированный
    map<int, list<int>> Graph = MakeGr(1);
    //вершина, из которой существует путь во все остальные называется истоком
    bool *visited = new bool[Graph.size()];
    for (int i = 0; i < Graph.size(); i++)
        visited[i] = false;

    for (auto it = Graph.begin(); it != Graph.end(); it++)
    {
        vector<int> path = BFS(Graph, it->first, visited);
        bool fl = true;
        for (int i = 0; i < Graph.size(); i++)
            if (visited[i] == false)
                fl = false;
        if (fl)
        {
            cout << "Vertex " << it->first << " is source: ";
            for (vector<int>::iterator it1 = path.begin(); it1 != path.end(); it1++)
                cout << *it1 << " ";
            cout << endl;
        }
        for (int i = 0; i < Graph.size(); i++)
            visited[i] = false;
    }
    return 0;
}