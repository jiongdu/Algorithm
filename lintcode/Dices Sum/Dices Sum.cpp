class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<map<int, double>> dp(n+1);
        dp[1] = {{1,1/6.0},{2,1/6.0},{3,1/6.0},{4,1/6.0},{5,1/6.0},{6,1/6.0}};
        for (int i = 2; i <= n; i++) {
            for (auto a1 : dp[i-1]) {
                for (auto a2 : dp[1]) {
                    dp[i][a1.first + a2.first] += a1.second * a2.second;
                }
            }
        }
        vector<pair<int, double>> res;
        for (auto a : dp[n]) {
            res.push_back({a.first, a.second});
        }
        return res;
    }
};

// class Solution {
// public:
//     /**
//      * @param n an integer
//      * @return a list of pair<sum, probability>
//      */
//     vector<pair<int, double>> dicesSum(int n) {
//         // Write your code here
//         vector<vector<double> > f(n+1, vector<double>(6 * n + 1));
//         for (int i = 0; i <= 6; i++) {
//             f[1][i] = 1.0/6;
//         }
//         for (int i = 2; i <= n; i++) {
//             for (int j = i; j <= 6 * n; j++) {
//                 for (int k = 1; k <= 6; ++k) {
//                     if (j > k) {
//                         f[i][j] += f[i-1][j-k];
//                     }
//                 }
//                 f[i][j] /= 6.0;
//             }
//         }
//         vector<pair<int, double>> res;
//         for (int i = n; i <= 6*n; i++) {
//             res.push_back(make_pair(i, f[n][i]));
//         }
//         return res;
//     }
// };