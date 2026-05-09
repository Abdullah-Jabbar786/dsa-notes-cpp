#include <iostream> 
#include <vector> 
using namespace std; 

class Solution {
public: 
    bool Is_Safe(vector<vector<char>>& board, int row, int col, char digit) { 
        // Horizontal 
        for(int j=0; j<9; j++) { 
            if(board[row][j]==digit) return false; 
        } 
        // Vertical 
        for(int i=0; i<9; i++) { 
            if(board[i][col]==digit) return false; 
        } 
        // Grid 
        int srow = (row/3)*3; 
        int scol = (col/3)*3; 
        for(int i=srow; i<=srow+2; i++) { 
            for(int j=scol; j<=scol+2; j++) { 
                if(board[i][j] == digit) return false; 
            } 
        } 
        return true; 
    } 
    bool helper(vector<vector<char>>& board, int row, int col) { 
        if(row==9) // Base Case 
        { 
            return true; 
        } 
        int next_row = row, next_col = col+1; 
        if(next_col==9) { 
            next_row = row + 1; 
            next_col = 0; 
        } 
        if(board[row][col] != '.') { 
            return helper(board, next_row, next_col); 
        } 
        // Placing a digit 
        for(char digit='1'; digit<='9'; digit++) { 
            if(Is_Safe(board, row, col, digit)) { 
                board[row][col] = digit; 
                if(helper(board, next_row, next_col)) { 
                    return true; 
                } 
                board[row][col] = '.'; 
            } 
        } 
        return false; 
    } 
    void solveSudoku(vector<vector<char>>& board){ 
        helper(board, 0, 0); 
    } 
};
