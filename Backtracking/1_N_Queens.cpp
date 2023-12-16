#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> ans;
int board[11][11], s=0;

bool isPossible(int n, int r,int c){
    for(int i=r-1;i>=0;i--)
        if(board[i][c]==1)
            return false;
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;
    return true;
}

void nQueen(int n,int r){
    if (r == n) {
        ans.push_back(vector<int>()); // Add an empty vector to ans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[s].push_back(board[i][j]);
            }
        }
        s++;
    }
    else{
        for(int j=0;j<n;j++){
            if(isPossible(n, r, j)){
                board[r][j]=1;
                nQueen(n, r+1);
                board[r][j]=0;
            }
        }
    }

}


vector<vector<int>> nQueens(int n)
{
    memset(board, 0, 11 * 11 * sizeof(int));
    nQueen(n, 0);
    return ans;
   
}
class Runner
{
    int n;

public:
    
    void takeInput()
    {
        cin>>n;
    }
    void execute()
    {
        auto ans = nQueens(n);
    }
    void executeAndPrintOutput()
    {
        auto ans = nQueens(n);
        if(ans.size())
        {
            sort(ans.begin(),ans.end());
            for(auto v:ans)
            {
                for(auto i:v)cout << i << " ";
                cout << endl;
            }
        }
        else cout << "\'No Configuration\'";
    }
};



int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}