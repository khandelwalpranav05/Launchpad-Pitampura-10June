#include<iostream>
using namespace std;

bool isSafe(int maze[4][4], int row, int col, int n){
	
	//for col
	for (int i = 0; i < row; i++)
	{
		if(maze[i][col]==1){
			return false;
		}
	}
	//right diag
	int i = row-1;
	int j=col-1;
	while(i>=0 && j>=0){
		if(maze[i][j]==1){
			return false;
		}
		i--;
		j--;
	}

	//left diag 
	i = row-1;
	j=col+1;
	while(i>=0 && j<n){
		if(maze[i][j]==1){
			return false;
		}
		i--;
		j++;
	}
	return true;
}

bool nqueen(int maze[4][4], int row, int n){
	if(row==n){
		return true;
	}

	for (int col = 0; col < n; col++)
	{
		if(isSafe(maze, row, col, n)){
			maze[row][col]=1;
			bool result = nqueen(maze, row+1, n);
			if(result){
				return true;
			}
			maze[row][col]=0;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int maze[4][4] = {{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0}};

	nqueen(maze,0,4);
	for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cout<<maze[i][j]<<" ";			
			}
		cout<<endl;
	}
	return 0;
}













