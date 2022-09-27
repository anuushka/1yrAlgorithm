#include<bits/stdc++.h>
using namespace std;
vector<int> color;
vector<vector <int> > graph;
bool bipartite = true;

void isBipartite(int src)
{
	for(int u = 0; u < graph[src].size(); u++)
	{
		if(color[graph[src][u]] == -1)
		{
			color[graph[src][u]] = 1 - color[src];
			isBipartite(graph[src][u]);
		}
		else if(color[graph[src][u]] == color[src])
		bipartite =  false;
	}
}

int main()
{
	ifstream fin("bipartite.in");
	ofstream fout("bipartite.out");
	int n, m;
	fin >> n >> m;
	graph.resize(n);
	color.assign(n, -1);
	int a, b;
	
	for(int i = 0; i < m; i++)
	{
		fin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	
	for(int i = 0; i < n; i++)
	{
		if(color[i] == -1)
		{	
			color[i] = 1;
			isBipartite(i);
		}
	}
	
	fout << (bipartite? "YES" : "NO");
	return 0;
}
