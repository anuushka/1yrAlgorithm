#include<bits/stdc++.h>
#define INF 10000

using namespace std;
 
class Edge 
{
    public:
    int src;
    int dest;
    int weight;
    Edge(int src_, int dest_, int weight_) : src(src_), dest(dest_), weight(weight_){}
};
 
void bellmanFord (vector <int> &dist, vector <Edge> &edges, int n, int m, int vertex) 
{
     
    dist[vertex] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
 
            int src = edges[j].src;
            int dest = edges[j].dest;
            int weight = edges[j].weight;
 
            dist[dest] = min(dist[dest], dist[src] + weight);
        }
    }
}
 
int main() {
    ifstream fin("pathsg.in");
    ofstream fout("pathsg.out");
 
    int n, m;
    fin >> n >> m;
 
    vector<Edge> edges;
 
    int src, dest, weight;
    for (int i = 0; i < m; i++) 
    {
        fin >> src >> dest >> weight;
        Edge e(src - 1, dest - 1, weight);
        edges.push_back(e);
    }
     
    vector <int> dist;
    dist.assign(n, INF);
    vector <vector <int>> result;
    result.assign(n, vector <int> (n));
 
    for (int i = 0; i < n; i++) 
    {
 
        bellmanFord(dist, edges, n, m, i);
 
        for (int j = 0; j < n; j++) 
        {
            result[i][j] = dist[j];
        }
 
        dist.assign(n, INF);
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fout << result[i][j] << " ";
        }
        fout << '\n';
    }
     
    return 0;
}
