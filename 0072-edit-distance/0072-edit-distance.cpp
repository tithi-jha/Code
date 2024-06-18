// class Solution {
// public:
//     int solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
//         if (i<0) return j+1;
//         if (j<0) return i+1;
//         if (dp[i][j] != -1) return dp[i][j];
//         if (s[i] == t[j]) {
//             return dp[i][j] = 0 + solve(i-1, j-1, s, t, dp);
//         }
//         return dp[i][j] = 1 + min(solve(i, j-1, s, t, dp), min(solve(i-1, j, s, t, dp), solve(i-1, j-1, s, t, dp)));//min(insert,delete,replace)
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//         return solve(n-1, m-1, word1, word2, dp);
//     }
// };
























class Solution {
public:
    int solve(string word1, string word2,int i,int j,vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int notTake=0;
        int take=0;
        if(word1[i]==word2[j]){
            notTake=0+solve(word1,word2,i-1,j-1,dp);
        }else{
            take=1+min(min(solve(word1,word2,i-1,j,dp),solve(word1,word2,i,j-1,dp)),solve(word1,word2,i-1,j-1,dp));
        }
        return dp[i][j]=take+notTake;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};