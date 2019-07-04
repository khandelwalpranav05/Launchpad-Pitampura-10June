#include<iostream>
using namespace std;

bool isSafe(int maze[4][4], int row, int col){

	if(row<4 && col<4 && maze[row][col]!=1){
		return true;
	}
	return false;
}

bool ratInMaze(int maze[4][4], int row, int col, int sol[4][4] ){
	if(row == 3 && col == 3){
		sol[row][col]=1;
		return true;
	}
	if(isSafe(maze,row,col)){
		sol[row][col]=1;
		if(ratInMaze(maze, row, col+1, sol)){
			return true;
		}
		if(ratInMaze(maze, row+1, col, sol)){
			return true;
		}

		sol[row][col]=0;
		return false;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int maze[4][4]={{0,0,0,0},
					{0,0,0,1},
					{0,1,0,0},
					{0,0,0,0}};

	int sol[4][4] = {{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0}};

	if(ratInMaze(maze,0,0,sol)){
		cout<<"path exist"<<endl;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cout<<sol[i][j]<<" ";			
			}
		cout<<endl;
	}
}
	
	else{
		cout<<"path doesn't exist"<<endl;
	}
	return 0;
}



















