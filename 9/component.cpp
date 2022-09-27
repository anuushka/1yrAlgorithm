#include<bits/stdc++.h>
using namespace std;
vector<vector <int> > graph;
vector<vector <int> > trans_graph;
stack<int> s;
vector<int> component;
vector<bool> visited;
int comp = 1;

void dfs_G(int u)
{
	visited[u] = true;
		for(int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];
			if(!visited[v])
				dfs_G(v);
		}
	s.push(u);
}
void dfs_T(int u)
{
	visited[u] = true;
	component[u] = comp;
	for(int i = 0; i < trans_graph[u].size(); i++)
	{
		int v = trans_graph[u][i];
		if(!visited[v])
			dfs_T(v);
	}
}

int main()
{
	ifstream fin("cond.in");
	ofstream fout("cond.out");
	int n, m;
	fin >> n >> m;
	graph.resize(n);
	trans_graph.resize(n);
	visited.resize(n, false);
	component.resize(n);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		fin >> u >> v;
		graph[u-1].push_back(v-1);
		trans_graph[v-1].push_back(u-1);
	}
	
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
			dfs_G(i);
	}
	
	visited.assign(n, false);
	while(!s.empty())
	{ 
        int v = s.top(); 
        s.pop(); 
        if (!visited[v]) 
        { 
            dfs_T(v); 
        	comp++;
        } 
    }
	
	fout << comp - 1 << '\n';
	
	for(int i = 0; i < n; i++)
		fout << component[i] << " ";
	fin.close();
	fout.close();
	return 0;
	
}
