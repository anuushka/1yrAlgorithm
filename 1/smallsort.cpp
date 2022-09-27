#include <iostream>
#include <fstream>

using namespace std;
int main() 
{
	ifstream file;
	file.open("smallsort.in");
	int n;
	file >> n;
	int array[10000], t;
	for(int x = 0; x < n; x++) {
		file >> array[x];
	}
	file.close();
	
	
	for(int x = 0; x < n; x++)
	{
		for(int y = x + 1; y < n; y++)
		{
			if(array[x] > array[y])
			{
				t = array[x];
				array[x] = array[y];
				array[y] = t;
			}
		}
	}
	
	ofstream file1("smallsort.out");
	for(int x = 0; x < n; x ++) {
		file1 << array[x] << ' ';
	}
	
	file1 << endl;
	file1.close();
	return 0;
}
