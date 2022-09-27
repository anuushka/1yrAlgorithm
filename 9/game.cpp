#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000

vector<vector<int>> graph;
vector<bool> visited;
vector<int> state;

void dfs(int u) 
{
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) 
	{
		int v = graph[u][i];
        if (!visited[v]) 
		{
            dfs(v);
            if (state[v] == 0) 
                state[u] = 1;
        }
        else if (visited[v]) 
		{
            if (state[v] == 0) 
                state[u] = 1;
        }
    }
}

int main() 
{
    ifstream fin("game.in");
    ofstream fout("game.out");
    graph.resize(SIZE);

    int n, m, start_v;
    fin >> n >> m >> start_v;
    start_v--;
    visited.assign(n, false);
    state.assign(n, 0);
    
    int u, v;
    for (int i = 0; i < m; i++) 
	{
        fin >> u >> v;
        graph[u-1].push_back(v-1);
    }
    
    for (int i = 0; i < n; i++) 
	{
        if (!visited[i]) 
		{
            dfs(i);
        }
    }
    if (state[start_v]) 
        fout << "First player wins" << '\n';
    else fout << "Second player wins" << '\n';

    return 0;
}

