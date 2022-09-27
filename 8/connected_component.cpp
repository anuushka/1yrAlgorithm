#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e5 + 1;
vector<int> adj[SIZE];
int cmp[SIZE];
int vis[SIZE];


void dfs(int v)
{
	vis[v] = true;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int next_v = adj[v][i];
		// go to all adjacent vertices and give a component id
		// if all already visit, go to next vertice
		if(!vis[next_v])
		{
			cmp[next_v] = cmp[v];
			dfs(next_v);
		}
	}
}


int main()
{
	ifstream fin("components.in");
	ofstream fout("components.out");
	
	int n, m;
	int a, b;
	
	
	fin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		fin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	//go to vertices that are not visited
	// give them cmp_id;
	//go to adjacent vertice
	//adj vertive not visited --> cmp_id
	//adj vertice visited --> next vertice --> next cmp_id;
	
	int cmp_num = 0;
	for(int i = 0; i < n; i++)
	{
		if(!vis[i])
		{
			cmp_num++;
			cmp[i] = cmp_num;
			dfs(i);
		}
	}
	
	
	fout << cmp_num << endl;
	
	for(int i = 0; i < n; i++)
	{
		fout << cmp[i] << ' ';
	}
	
	return 0;

}
