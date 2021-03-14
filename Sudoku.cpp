#include <iostream>
#include <cmath>
using namespace std;


bool isSafe(int a[][9], int n, int i, int j, int k)
{
	for(int x=0; x<n; x++)
		if(a[i][x]==k || a[x][j]==k)
			return false;

	int sq=sqrt(n), r = (i/sq)*sq, c = (j/sq)*sq;

	for(int I=r; I<r+sq; I++)
		for(int J=c; J<c+sq; J++)
			if(a[I][J]==k)
				return false;

	return true;
}


bool SUDOKU(int a[][9], int n, int i=0, int j=0)
{
	if(i==n)
	{
		for(int r=0; r<n; r++)
		{
			for(int c=0; c<n; c++)
			{
				cout<<a[r][c]<<" ";
			}

			cout<<endl;
		}

		return true;
	}

	if(j==n)
		return SUDOKU(a, n, i+1);

	if(a[i][j]!=0)
		return SUDOKU(a, n, i, j+1);


	for(int k=1; k<=n; k++)
	{
		if(isSafe(a, n, i, j, k))
		{
			a[i][j]=k;

			if(SUDOKU(a, n, i, j+1))
				return true;
		}
	}

	a[i][j]=0;
	return false;
}


int main()
{
	int N=9;
	cin>>N;

	int A[9][9];

	for(int r=0; r<N; r++)
		for(int c=0; c<N; c++)
			cin>>A[r][c];

	if(!SUDOKU(A,N))
		cout<<"-1"<<endl;

	return 0;
}