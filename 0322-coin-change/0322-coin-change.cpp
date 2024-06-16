class Solution {
private:
    int solve(vector<int>& coins, int amt,vector<vector<int>> &dp,int ind){
        //base case
        if(ind==0){
           if(amt%coins[0]==0){
               return amt/coins[0];
           }
               return 1e9;
        }
        if(dp[ind][amt]!=-1){
            return dp[ind][amt];
        }
        int notTake=0+solve(coins,amt, dp,ind-1);
        int take=INT_MAX;
        if(amt>=coins[ind]){
            //counting the no. of coins so +1 & since infinite supply so we not doing ind-1
            take=1+solve(coins,amt-coins[ind], dp,ind);
        }
        return dp[ind][amt]=min(notTake,take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ind=coins.size();
        vector<vector<int>>dp(ind,vector<int>(amount+1,-1));
        //in test case 2 if single element we need to print -1 but for the solve function to work we have returned 1e9 if single element% amount !=0. In order to fix tht lets store the function in ans variable and keep a condition for single element
        int ans= solve(coins,amount, dp,ind-1);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};



















