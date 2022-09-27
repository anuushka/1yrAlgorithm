#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 8e18;
 
struct Edge {
    int src;
    int dest;
    long long weight = INF;
};
 
vector <Edge> edges;
vector <vector<int>> graph;
vector <long long> dist;
vector <int> parent;
int relaxDest = -1;
vector <bool> visited;
 
 
void DFS (int src)
{
    visited[src] = true;
 
    for (int dest : graph[src])
    {
        if (!visited[dest])
        {
            DFS(dest);
        }
    }
}
 
ofstream fout ("path.out");
 
void Bellman(int n, int m, int s)
{
 
    dist[s] = 0;    
    for (int i = 0; i < n; i++)
    {
        relaxDest = -1;
        for (int j = 0; j < m; j++)
        {
            int src = edges[j].src;
            int dest = edges[j].dest;
            long long weight = edges[j].weight;
 
            if (dist[src] < INF)
            {
                if (dist[dest] > dist[src] + weight)
                {
                    dist[dest] = std::max (-INF, dist[src] + weight);
                    parent[dest] = src;
                    relaxDest = dest;
                }
            }
        }
    }
     
  if (relaxDest != -1)
    {
        for (int i = 0; i < n; i++)
            relaxDest = parent[relaxDest];
  
        DFS(relaxDest);
  
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                dist[i] = -INF;
        }
    }
     
    for (auto d: dist)
    {
        if (d == -INF)
            fout << "-\n";      
        else if ( d == INF)
            fout << "*\n";
        else
            fout << d << '\n';  
    }
}
 
 
int main() {
    ifstream fin ("path.in");
    int n, m, s;
    fin >> n >> m >> s;
 
    dist.assign(n, INF);
    parent.assign(n, -1);
    graph.resize(n);
    visited.resize(n);
 
    int src, dest;
    long long weight;
 
    for (int i = 0; i < m; i++)
    {
        fin >> src >> dest >> weight;
        edges.push_back({src - 1, dest - 1, weight});
        graph[src - 1].push_back(dest - 1);
    }
 
    Bellman(n, m, s - 1);
    return 0;
}
