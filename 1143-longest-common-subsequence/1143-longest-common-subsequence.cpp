//memoiation code gets a tle. 
// class Solution {
// private:
//     int solve(string text1, string text2,int ind1, int ind2,vector<vector<int>> &dp){
//          //base case
//         if(ind1<0 || ind2<0){
//             return 0;
//         }
//          if(dp[ind1][ind2]!=-1){
//              return dp[ind1][ind2];
//          }
//          int match=0;
//          int notMatch=0;
//         if(text1[ind1]==text2[ind2]){
//         match=1+solve(text1,text2,ind1-1,ind2-1,dp);
//         }
//         else{
//         notMatch=0+max(solve(text1,text2,ind1,ind2-1,dp),solve(text1,text2,ind1-1,ind2,dp));
//         }
//         return dp[ind1][ind2]=match+notMatch;
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int ind1=text1.size();
//         int ind2=text2.size();

//         vector<vector<int>> dp(ind1,vector<int>(ind2,-1));

//         return solve(text1,text2,ind1-1,ind2-1,dp);
//     }
// };

class Solution{
   public:
     int solve(int i,int j, string &s,string &t,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
        }else{
            return dp[i][j]=max(solve(i,j-1,s,t,dp),solve(i-1,j,s,t,dp));
        }
     }
     
     int longestCommonSubsequence(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp);
     }
};