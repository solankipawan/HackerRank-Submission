#include<iostream>
using namespace std; 
int mat_chn_bot_up(int p[], int n) 
{ 
	int matrix[n][n]; //cost of computing multiplication from matrix[i] to matrix[j]
	int i, j, k, length, cost; 
	for (i = 1; i < n; i++) 
		matrix[i][i] = 0; //single matrix does not require multiplication
 
	for (length = 2; length < n; length++) //going from chain length 2 to n
	{ 
		for (i = 1; i < n - length + 1; i++) 
		{ 
			j = i + length - 1; 
			matrix[i][j] = 100000; 
			for (k = i; k <= j - 1; k++) 
			{ 
				cost = matrix[i][k] + matrix[k + 1][j] + p[i - 1] * p[k] * p[j]; 
				if (cost < matrix[i][j]) 
                {
					matrix[i][j] = cost; 
                }
			} 
		} 
	} 

	return matrix[1][n - 1]; 
} 

int main() 
{ 
	int arr[] = {5,4,3,2,1}; 
	int size =5;

	cout<< mat_chn_bot_up(arr, size)<<endl; 
	return 0; 
} 

