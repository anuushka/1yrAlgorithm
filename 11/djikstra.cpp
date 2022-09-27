#include <bits/stdc++.h>
using namespace std;


void Dijkstra (vector<vector<pair <int, int>>> &graph, vector <bool> &used, vector <long long> &dist, int n,int vertex) {

    dist[vertex] = 0;

    for (int i = 0; i < n; i++) {

        vertex = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (vertex == -1 || dist[j] < dist[vertex]))
                vertex = j;
        }

        used[vertex] = true;

        for (int j = 0; j < graph[vertex].size(); j++) {

            int to = graph[vertex][j].second;
            int weight = graph[vertex][j].first;

            dist[to] = min (dist[to], dist[vertex] + weight);
        }
    }
}


int main () {
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");

    int n;
    int src;
    int last;

    fin >> n >> src >> last;

    vector <vector <pair <int, int>>> graph(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int weight;
            fin >> weight;
            if (weight != -1)
                graph[i].push_back({weight, j});
        }
    }

    vector <bool> used;
    used.assign(n, false);
    vector <long long> dist;
    dist.assign(n, INT64_MAX);

    Dijkstra(graph, used, dist, n, src - 1);

    if (dist[last - 1] >= INT64_MAX)
        fout << -1;
    else
    	fout << dist[last - 1];

    return 0;
}
