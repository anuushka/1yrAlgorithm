#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
stack<int> s;

bool dfs(int n)
{
	visited[n] = 1;
	for(auto i: adj[n])
	{
		if(visited[i] == 0)
			if(!dfs(i))
			return false;
		if(visited[i] == 1)
			return false;
	}
	visited[n] = 2;
	s.push(n);
	return true;
}

int main()
{
	ifstream fin("topsort.in");
	ofstream fout("topsort.out");
	int v, e;
	fin >> v >> e;
	
	adj.resize(v);
	visited.resize(v);
	
	for(int i = 0; i < e; i++)
	{
		int a, b;
		fin >> a >> b;
		adj[--a].push_back(--b);
	}
	
	
    for (int i = 0; i < v; i++)
    {
    	visited[i] = 0;
	}
	
    for (int i = 0; i < v; i++) 
	{
        if (visited[i] == 0)
            if (!dfs(i)) 
			{
                fout << "-1";
                return 0;
            }
    }

    while(!s.empty())
	{
        fout << s.top() + 1 << " ";
        s.pop();
    }
	    
	    return 0;
}
