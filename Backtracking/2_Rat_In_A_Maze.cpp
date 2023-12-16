/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;
int solution[19][19];

void findpath(int maze[][19],int n,int x,int y){
	if(x==n-1 && y==n-1){
		solution[x][y]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<solution[i][j]<<" ";
			}
		}
		cout<<endl;
		return;
	}
	if(x>n-1 || y>n-1 || x<0||y<0|| solution[x][y]==1|| maze[x][y]==0) return;
	
	solution[x][y]=1;
	findpath(maze, n, x-1, y);
	findpath(maze, n, x+1, y);
	findpath(maze, n, x, y-1);
	findpath(maze, n, x, y+1);
	solution[x][y]=0;
}
int main() {
	int n, maze[19][19];
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			maze[i][j]=x;
		}
	}
	findpath(maze, n, 0, 0);

	return 0;
}
/*
input 
3
1 1 1 
1 1 0 
0 1 1 

output 
1 0 0 1 1 0 0 1 1 
1 1 0 0 1 0 0 1 1 
*/