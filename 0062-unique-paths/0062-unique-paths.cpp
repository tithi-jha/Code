// class Solution {
// private:
//     int solve(int i, int j,vector<vector<int>> &dp){
//         if(i==0 && j==0){
//             return 1;
//         }
//         if(i<0 ||j<0){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int up=solve(i-1,j,dp);
//         int left=solve(i,j-1,dp);//since we r going frm last cell to first cell

//         dp[i][j]=up+left;
//         return dp[i][j];
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(m-1,n-1,dp);
//     }
// };


















class Solution {
public:
    int solve(int i, int j,vector<vector<int>>&dp,int m,int n){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 ||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=0;
        if(i>=0 && j>=0 && i<m-1){
           down=solve(i+1,j,dp,m,n);
        }
        int right=0;
        if(i>=0 && j>=0 && j<n-1){
           right=solve(i,j+1,dp,m,n);
        }
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,dp,m,n);
    }
};
