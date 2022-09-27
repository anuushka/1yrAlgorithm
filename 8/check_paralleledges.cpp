#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m, x, y;
	int arr[n][n];
	fin >> n >> m;
		
	for(int i = 0; i < m; i++)
	{
		fin >> x >> y;
		arr[x--][y--]++;
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(arr[i][j] + arr[j][i] > 1)
			{
				fout << "YES" << "\n";
				fin.close();
				fout.close();
			}
		}
	}
	
	fout << "NO" << "\n";
	return 0;	
}
