#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

void swap_num(vector<int> & arr)
{
	for(int i = 0; i < arr.size(); i++)
	{
		swap(arr[i], arr[i/2]);
	}
}

int main() 
{
	ifstream input("antiqs.in");
	int n;
	input >> n;
	vector <int> arr(n);
	
	for(int i = 0; i < n; i++)
	{
		 arr[i] = i + 1;
	}
	
	swap_num(arr);
	
	ofstream output("antiqs.out");
	 for (auto a : arr)
    {
        output << a << " ";
    }
	
	return 0;
}
