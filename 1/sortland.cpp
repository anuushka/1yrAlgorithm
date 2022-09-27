#include <stdio.h>
#include <stdlib.h> 

int main() {
	int n = 0;
	FILE *fin, *fout;
	fin = fopen("sortland.in", "r");
	fscanf(fin, "%d", &n);
	float a[n];
	float b[n];
	
		for (int i =0; i < n; i++) 
		{
			fscanf(fin, "%f", &a[i]);
		}
		
		fclose(fin);
		
		for(int i = 0; i < n; i++)
		{
			b[i] = a[i];
		}
	
	float key;
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1]) 
			{
			key = a[j];
			a[j] = a[j + 1];
			a[j + 1] = key ;
			}
		}
	}

	
	int poor, mid, rich;
		for(int i = 0; i < n; i++)
		{
			if(b[i] == a[0]) {
				poor = i;
			}
			if(b[i] == a[(n-1)/2]){
				mid = i;
			}
			if(b[i] == a[n-1])
			{
				rich = i;
			}
		}
		
	fout = fopen("sortland.out", "w");
	fprintf(fout,"%d %d %d", poor+1, mid+1, rich+1);
	
	return 0;
	
}



