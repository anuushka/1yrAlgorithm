#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n, m;
	fin >> n >> m;
	int arr[n][n];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		int v1, v2;
		fin >> v1 >> v2;
		arr[v1-1][v2-1] = 1;
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			fout << arr[i][j] << " ";
		}
		fout << "\n";
	}
	
	fin.close();
	fout.close();
	}
