#include<bits/stdc++.h>
using namespace std;

void Dijkstra (vector <vector<pair <int, int>>> &graph,
               vector <long long> &dist,
               set <pair <long long, int>> &MinPQ,
               int src) 
{
    dist[src] = 0;
    MinPQ.insert(make_pair(0, src)); 
    
    while (!MinPQ.empty()) 
	{
		
		pair<int, int> newMinPQ = *(MinPQ.begin()); 
        MinPQ.erase(MinPQ.begin()); 
        src = newMinPQ.second; 

        for (int j = 0; j < graph[src].size(); j++) 
		{

            int neighbor = graph[src][j].second;
            int weight = graph[src][j].first;

            if (dist[neighbor] > dist[src] + weight) {
                MinPQ.erase({dist[neighbor], neighbor});
                dist[neighbor] = dist[src] + weight;
                MinPQ.insert({dist[neighbor], neighbor});
            }
        }
    }
}


int main () 
{
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");

    int n, m;
    fin >> n >> m;

    vector <vector<pair <int, int>>> graph(n);

    int u, v, weight;
    for (int i = 0; i < m; i++) 
	{
        fin >> u >> v >> weight;

        graph[u - 1].push_back({weight, v - 1});
        graph[v - 1].push_back({weight, u - 1});
    }

    vector <bool> visited;
    visited.assign(n, false);
    vector <long long> dist;
    dist.assign(n, INT64_MAX);
    set <pair<long long, int>> MinPQ;

    Dijkstra(graph, dist, MinPQ, 0);

    for (int i = 0; i < n; i++) 
	{
        fout << dist[i] << " ";
    }
    fout.close();
    return 0;
}
