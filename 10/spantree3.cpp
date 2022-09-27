#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int x, y, len;
    bool operator < (Edge &e) 
	{
        return this->len < e.len;
    }
};

int n;
vector<int> p (n);

int dsu_get (int v) 
{
	if(v != p[v])
		p[v] = dsu_get(p[v]);
	return p[v];
}

void dsu_unite (int a, int b) 
{
	a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1)
		swap (a, b);
	if (a != b)
		p[a] = b;
}

int main() {
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");
    int x, y, len, k = 0, m;
    long long cost = 0;
    fin >> n >> m;
    vector<Edge> graph(m);
    for (int i = 0; i < m; i++) 
	{
        fin >> x >> y >> len;
        x--, y--;
        graph[i] = {x, y, len};
    }

    sort(graph.begin(), graph.end());
    p.resize (n);
    for (int i=0; i<n; ++i)
        p[i] = i;
    for (int i=0; i<m; ++i) 
	{
        int a = graph[i].x,  b = graph[i].y,  l = graph[i].len;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            dsu_unite(a, b);
        }
    }
    fout << cost;
    return 0;
}
