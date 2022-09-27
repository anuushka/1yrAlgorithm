#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n, m;
	fin >> n >> m;
	
	vector<vector<int>> g;
	g.resize(n);
			
	int u, v;
	for(int i = 0; i < m; i++)
	{
		fin >> u >> v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	
	for(int i = 0; i < n; i++)
	{
		fout << g[i].size() << " ";
	}
	
	return 0;
}
