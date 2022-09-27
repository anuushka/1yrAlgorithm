#include<bits/stdc++.h>
using namespace std;

int cycle_start = -1;
int cycle_end;

bool dfs(int v, int visit[], vector<vector<int>> &graph, vector<int> &parent, vector<int> &result)
{
	visit[v] = 1;
	for(int i = 0; i < graph[v].size(); i++)
	{
		int adj = graph[v][i];
		if(visit[adj] == 0)
		{
			parent[adj]  = v;
			dfs(adj, visit, graph, parent, result);
		}
		else if(visit[adj] == 1)
		{
			cycle_end = v;
			cycle_start = adj; 
		}
	}
	
	visit[v] = 2;
	result.push_back(v);
}

int main()
{
	ifstream fin("cycle.in");
	ofstream fout("cycle.out");
	int n, m;
	fin >> n >> m;
	vector<vector<int>> graph;
	graph.resize(n+1);
	int a, b;
	for(int i = 0; i < m; i++)
	{
		fin >> a >> b;
		graph[a].push_back(b);
	}
	
	vector<int> result;
	int* visit = new int[n+1];
	
	for(int i= 0; i <= n; i++)
		visit[i] = 0;
		
	vector<int> parent;
	parent.resize(n+1);
	int j = 1;
	while(j!= graph.size())
	{
		if(visit[j] == 0)
		{
			dfs(j, visit, graph, parent, result);
			j++;
		}
		else
			j++;
	}
	
	if(cycle_start == -1)
	{
		fout << "NO";
	}
	else
	{
		fout << "YES" << '\n';
		vector<int> cycle;
		cycle.push_back(cycle_start);
		for(int v = cycle_end; v!= cycle_start; v = parent[v])
			cycle.push_back(v);
		
		for(int i = cycle.size() - 1; i >= 0; i--)
		{
			fout << cycle[i] << " ";
		}
	}
	
	
}
