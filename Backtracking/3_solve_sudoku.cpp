#include<bits/stdc++.h>
using namespace std;
int n=9;
bool findempty(int &row,int & col,int grid[10][10]){
    for(int i=0;i<n;i++ ){
        for(int j=0;j<n;j++){
          if (grid[i][j] == 0) {
            row = i;
            col = j;
            return true;
          }
        }
    }
    return false;
}
bool isSafeRow(int grid[10][10],int row, int num){
    for(int i=0;i<n;i++){
        if(grid[row][i]==num)return false;
    }
    return true;
}
bool isSafeCol(int grid[10][10],int col,int num){
    for(int i=0;i<n;i++){
        if(grid[i][col]==num)return false;
    }
    return true;
}
bool isSafeGrid(int grid[10][10],int row,int col, int num){
    int row_fact = row -row%3;
    int col_fact = col - col%3;
    for(int i=row_fact;i<row_fact+3;i++){
        for(int j=col_fact;j<col_fact+3;j++){
            if(grid[i][j]==num)return false;
        }
    }
    return true;
}
bool isSafe(int grid[10][10],int row,int col, int num){
    return (isSafeRow(grid, row, num) && isSafeCol(grid, col, num)&& isSafeGrid(grid, row, col, num));
}

bool canSolve(int grid[10][10]){
    int row=0,col=0;
    if(!findempty(row,col,grid)){
        return true;
    }
    for(int i=1;i<=n;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col]=i;
            if(canSolve(grid))return true;
            grid[row][col]=0;
        }
    }
    return false;
}
int main(){
    int grid[10][10]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
   if(canSolve(grid)){
        cout<<"true";
    }
    else cout<<"false";;
    
    // write your code here
    return 0;
}