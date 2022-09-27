#include <bits/stdc++.h>

using namespace std;

void countSort(vector<string> &a, int digit)
{
	vector<int> count((unsigned int) 'z' + 1);
	
	for(auto & s : a)
	{
		count[s[digit]]++;
	}
	
	int pos = 0;
	for(char i = 'a'; i <= 'z'; i++)
	{
		int add_pos = count[i];
		count[i] = pos;
		pos += add_pos;
	}
	
	vector<string>str(a.size());
	
	for(auto & s : a)
	{
		char c = s[digit];
		str[count[c]++] = s;
	}
	a = str;
}

void radixSort(vector<string> & a, int m, int k)
{
	for(int i = 1; i <= k; i++)
	{
		countSort(a, m-i);
	}
}


int main()
{
	ifstream input("radixsort.in");
	int n, k, m;
	input >> n>> m>> k;
	
	vector<string>a(n);
	
	for(int i = 0; i < n; i++)
	{
		input >> a[i];
	}
	
	ofstream output("radixsort.out");
	radixSort(a, m, k);
	
	for(auto & s: a)
	{
		output << s << '\n';
	}
}
