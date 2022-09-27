#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n;
	fin >> n;
	vector<vector<int>> arr;
	arr.resize(n);
	
	for(int i = 0; i < n; i++)
	{
		arr[i].resize(n);
	}
	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			fin >> arr[i][j];
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((arr[i][j] != arr[j][i]) || (arr[j][j] == 1))
			{
				fout << "NO" << "\n";
				fin.close();
				fout.close();
			}
		
		}
	}
	
	fout << "YES" << "\n";
	fin.close();
	fout.close();
}
