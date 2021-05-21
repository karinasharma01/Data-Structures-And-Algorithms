class Solution {
public:
    bool isSafe(vector<string>& board,int row,int col)
    {
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        for (int i=row-1,j=col+1;i>=0&&j<board.size();i--,j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    void solveNQueensHelper(vector<vector<string>>& res,vector<string>& board,int n,int row)
    {
        //if all the queens are placed return
        if(row==n)
        {
            res.push_back(board);
            return;
        }
        //consider this row & try placing the queen in all the columns one by one
        for(int col=0;col<n;col++)
        {
            //check if the queen can be placed in this board[row][col]
            if(isSafe(board,row,col))
            {
                //if the queen can be placed safely,then place it in board[row][col]
                board[row][col]='Q';
                //recur to place the rest of the queens
                solveNQueensHelper(res,board,n,row+1);
                //if placing queen in board[row][col] doesn't lead to a solution then
                //remove queen from board[row][col]
                //backtrack
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n<=0)
            return {{}};
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        solveNQueensHelper(res,board,n,0);
        return res;
    }
};
