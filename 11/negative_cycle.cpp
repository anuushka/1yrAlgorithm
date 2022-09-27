#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

struct Edge 
{
    int src, dest, weight;
};

int n;
int vertex = -1;
vector<Edge> graph;
vector<int> dist;
vector<int> parent;
vector<int> way;

bool ford() {
    dist[0] = 0;
    for (int i = 0; i < n; i++) 
	{
        vertex = -1;
        for (Edge edge : graph)
		 {
            if (dist[edge.dest] > dist[edge.src] + edge.weight) 
			{
                dist[edge.dest] = dist[edge.src] + edge.weight;
                parent[edge.dest] = edge.src;
                vertex = edge.dest;
            }
        }
    }
    
    if (vertex != -1) 
	{
        int negCycleEnd = vertex;
        for (int i = 0; i < n; i++)
            negCycleEnd = parent[negCycleEnd];
        for (int negCycleNow = negCycleEnd; negCycleNow != negCycleEnd || way.empty(); negCycleNow = parent[negCycleNow])
            way.push_back(negCycleNow);
        way.push_back(negCycleEnd);
        reverse(way.begin(), way.end());
        return true;
    }
    else if(vertex == -1)
    {
    	return false;
	}
}

int main() {
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");
    fin >> n;
    dist.resize(n, INF);
    graph.resize(n);
    parent.resize(n);
    for (int src = 0; src < n; src++) {
        for (int dest = 0; dest < n; dest++) 
		{
            int weight;
        	fin >> weight;
            graph.push_back({ src, dest, weight });
        }
    }
    if(ford())
    {
        fout << "YES\n";
        fout << way.size() << endl;
        for (int vertex : way)
            fout << vertex + 1 << ' ';
	}
    else
		fout << "NO";
	return 0;
}
