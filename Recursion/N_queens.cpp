#include <iostream>
#include <vector>
using namespace std;

// 4 Queens problem, 4x4 matrix
// place 2 queens such that they are not under attack.

// Queen is under attack when it is in same row, column, diagonal of another queen.

// optimal solution can be obtained if we use dynamic programming.

// 16C4 ways all possible ways.

// back tracking.
// refer to state space tree.

// Leetcode - 51 
// N Queens.


// O(n!) n, n-1, n-2
class Solution {
public:

    bool if_Safe(vector<string> &board, int row, int col, int n)
    {  // O(n)
        //Horizontal check
        for(int j=0; j<n; j++)
        {
            if(board[row][j]=='Q') return false;
        }

        //Vertical check
        for(int i=0; i<n; i++)
        {
            if(board[i][col]=='Q') return false;
        }

        // Left Diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        {
            if(board[i][j] == 'Q') return false;
        }

        // Right Diagonal
        for(int i=row, j=col; i>=0 && j<n; i--, j++)
        {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void N_Queens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
    {
            if(row==n) 
            {
                ans.push_back({board});
                return;
            }    

            for (int j=0; j<n; j++)
            {
                if(if_Safe(board, row, j, n))
                {
                    board[row][j] = 'Q';  
                    N_Queens(board, row+1, n, ans);   
                    board[row][j] = '.';  
                }
            }
            
        }

        vector<vector<string>> solveNQueens(int n){
            vector<string> board(n, string(n, '.'));
            vector<vector<string>> ans;

            N_Queens(board, 0, n, ans);
            return ans;
        }
};


int main() {
    int n;
    cout<<"Enter No. of Queens: ";
    cin>>n;

    Solution s;
    vector<vector<string>> solutions = s.solveNQueens(n);

    for (int i=0; i<solutions.size(); i++)
    {
        for (int j=0; j<solutions[i].size(); j++)
        {
            cout<<solutions[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}