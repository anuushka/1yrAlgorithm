#include<bits/stdc++.h>
using namespace std;
#define SIZE 100000 

vector<vector<int> > graph;
vector<bool> visited;
stack<int> s;
bool hamiltonian = false;
int prev_v = 0;
int cur_v = 0;

void dfs(int u)
{
	visited[u] = true;
	for(int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if(!visited[v])
			dfs(v);	
	}
	s.push(u);
}

int main()
{
	ifstream fin("hamiltonian.in");
	ofstream fout("hamiltonian.out");
	int n, m;
	fin >> n >> m;
	graph.resize(SIZE);
	visited.assign(n, false);
	
	int u, v;
	for(int i = 0; i < m; i++)
	{
		fin >> u >> v;
		graph[u-1].push_back(v-1);
	}
	
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	
	if(!s.empty())
	{
		prev_v = s.top();
		s.pop();
		hamiltonian = true;
	}
	
	while(!s.empty())
	{
		cur_v = s.top();
		s.pop();
		int path = 0;
		
		for(int prev: graph[prev_v])
		{
			if(prev == cur_v)
				path++;
		}
		
		if(path == 0)
		{
			hamiltonian = false;
			break;
		}
		
		prev_v = cur_v;	
	}
	
		if (hamiltonian) 
			fout << "YES";
		else fout << "NO";	
}
