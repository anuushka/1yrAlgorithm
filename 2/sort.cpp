#include <bits/stdc++.h> 
#include <iostream>
#include <fstream>


using namespace std;
int main() 
{
	
	ifstream file;
	file.open("sort.in");
	int n;
	file >> n;
	int array[300000], t;
	for(int x = 0; x < n; x++) {
		file >> array[x];
	}
	file.close();
	
	sort(array, array + n);
	
	ofstream file1("sort.out");
	for(int x = 0; x < n; x ++) {
		file1 << array[x] << ' ';
	}
	
	file1 << "\n";
	file1.close();
	return 0;
}
