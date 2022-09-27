#include <bits/stdc++.h>

using namespace std;

int binsearch_right(vector<int> & a, int x)
{
	int left = 0;
	int right = a.size();
	
	while(left < right)
	{
		int mid = (left + right)/2;
		if(x < a[mid]){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	
	}
	return a[left - 1] == x? left : -1;
}

int binsearch_left(vector<int> &a, int x)
{
	int left = 0;
	int right = a.size();
	
	while(left < right)
	{
		int mid = (left + right)/2;
		if(a[mid] < x)
		{
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return a[left] == x? left + 1: -1;
}

int main()
{
	ifstream input("binsearch.in");
	int n, m;
	input >> n;
	vector <int> a(n);
	
	for(int i = 0; i < n; i++) 
	{
		input >> a[i];
	}
	
	input >> m;
	
	ofstream output("binsearch.out");
	for(int i = 0; i < m; i++)
	{
		int x;
		input >> x;
		int leftmost = binsearch_left(a, x);
		int rightmost = binsearch_right(a, x);
		
		output << leftmost << " " << rightmost << "\n";		
	}
	
}
