/**************************************
* @author dujiong
* @date 2016.12.22
* @version V0.1
**************************************/

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size()==0) return false;
        if(word.length()==0) return false;
        int i,j; 
        N=board.size(); 
        M=board[0].size();
        vector<vector<int> > book(N,vector<int>(M,0));
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                if(dfs(board,i,j,word,0,book)==true) return true;
        return false;
    }
private:
    int N,M;
    bool dfs(vector<vector<char> > &board,int x,int y,string word,int p,vector<vector<int> > &book){
        if(p==word.length()) return true;
        if(x<0||x>=N||y<0||y>=M) return false;
        if(book[x][y]==1) return false;
        if(board[x][y]!=word[p]) return false;
        book[x][y]=1;
        bool k=dfs(board,x+1,y,word,p+1,book)||dfs(board,x-1,y,word,p+1,book)||dfs(board,x,y+1,word,p+1,book)||dfs(board,x,y-1,word,p+1,book);
        book[x][y]=0;
        return k;
    }
};