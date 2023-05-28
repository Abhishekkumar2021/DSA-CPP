#include<bits/stdc++.h>
using namespace std;

bool canPlace(int board[][9], int i, int j, int n, int number){
	// Check for row and column
	for(int x=0; x<n; x++){
		if(board[x][j]==number || board[i][x]==number){
			return false;
		}
	}
	// Check for subgrid
	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;
	for(int x=sx; x<sx+rn; x++){
		for(int y=sy; y<sy+rn; y++){
			if(board[x][y]==number){
				return false;
			}
		}
	}
	return true;
}



bool sudokuSolver(int board[][9], int i, int j, int n){
	// Base Case
	if(i==n){
		// Print the board
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	// Case Row End
	if(j==n){
		return sudokuSolver(board, i+1, 0, n);
	}
	// Skip the pre-filled cells
	if(board[i][j]!=0){
		return sudokuSolver(board, i, j+1, n);
	}
	// Recursive Case
	// Fill the current cell with possible options
	for(int number=1; number<=n; number++){
		if(canPlace(board, i, j, n, number)){
			// Assume
			board[i][j] = number;
			bool couldWeSolve = sudokuSolver(board, i, j+1, n);
			if(couldWeSolve){
				return true;
			}
		}
	}
	// Backtrack here
	board[i][j] = 0;
	return false;
}

int main(){
	int board[9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
	sudokuSolver(board, 0, 0, 9);
	return 0;
}