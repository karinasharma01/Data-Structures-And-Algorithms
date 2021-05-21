class Solution {
public:
    int count = 0;
    bool isSafe(vector<string>& board,int row,int col)
    {
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    void solveNQueens(vector<string>& board,int row,int n)
    {
        if(row==n)
        {
            count++;
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(isSafe(board,row,col))
            {
                board[row][col]='Q';
                solveNQueens(board,row+1,n);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        
        if(n<=0)
            return 0;
        vector<string> board(n,string(n,'.'));
        solveNQueens(board,0,n);
        return count;
    }
};
