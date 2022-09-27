#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	ifstream input("turtle.in");
	int  a,b;  
	input >> a >> b;
	int mas[a][b];
	int mas2[a+1][b+1];
	int mas3[a][b];
	int sum = 0;
	for(int i = 0; i< a;i++){
		for(int j = 0; j < b;j++){
			input >> mas[i][j];
		}
	} 
	int k = 0;
	for(int i = a-1;i>=0;i--){
		for(int j = 0;j<= b-1;j++){
			mas3[k][j] = mas[i][j];
		}
		k++;
	}
	for(int i = 0; i<a+1;i++){
		for(int j  = 0; j<b+1;j++){
			mas2[i][j] = 0;
		}
	}	
	for (int i = 1; i < a+1; ++i)
	{
		for (int j = 1; j < b+1; ++j)
		{
			mas2[i][j] = max(mas2[i-1][j],mas2[i][j-1]) + mas3[i-1][j-1];
		}
	}
	sum += mas2[a][b];
	for (int i = 0; i < a+1; ++i)
	{
		for (int j = 0; j < b+1; ++j)
		{
			cout << mas2[i][j] << " ";
		}
		cout << endl;
	}

	ofstream output("turtle.out");
	output << sum;

}
