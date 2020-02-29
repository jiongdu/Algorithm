class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queens(n, string(n, '.'));       //初始化所有字符都为"."
        helper(0, queens, res);
        return res;      
    }
    void helper(int curRow, vector<string>& queens, vector<vector<string>>& res) {
        int n = queens.size();
        if (curRow == n) {
            res.push_back(queens);
            return;
        }
        for (int i=0; i < n; i++) {
            if(isValid(queens, curRow, i)) {
                queens[curRow][i] = 'Q';
                helper(curRow+1, queens, res);
                queens[curRow][i] = '.';
            }
        }
    }
    bool isValid(vector<string>& queens, int curRow, int curColumn) {
        for (int i=0; i<curRow; i++) {         //到目前的列上有没有冲突
            if(queens[i][curColumn] == 'Q') return false;
        }
        for (int i = curRow - 1, j = curColumn - 1; i >= 0 && j >= 0; --i, --j) {    //到0的对角线有没有冲突
            if (queens[i][j] == 'Q') return false;
        }
        for (int i = curRow - 1, j = curColumn + 1; i >= 0 && j < queens.size(); --i, ++j) { //到右上角的对角线有没有冲突
            if (queens[i][j] == 'Q') return false;
        }
        return true;
    }
};