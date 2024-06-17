// class Solution {
// private:
//     //int buy so we can keep track of whether we need to buy or sell
//     //buy=1 means buy, buy=0 means sell
//     int solve(vector<int>& prices,int ind,int buy,vector<vector<int>> &dp){
//         int n=prices.size();
//         //base case
//         if(ind>=n){//when the array is exhausted we cant buy or sell
//             return 0;
//         }
//         if(dp[ind][buy]!=-1){
//             return dp[ind][buy];
//         }

//         int ans=0;
//         if(buy){
//             ans=max(-prices[ind]+solve(prices,ind+1,0,dp),0+solve(prices,ind+1,1,dp));
//             //ans=max(buy,not buy)
//             //-prices[ind] cuz when buy we lost tht amt of money
//         }
//         else{
//             ans=max(prices[ind]+solve(prices,ind+2,1,dp),0+solve(prices,ind+1,0,dp));
//             //ans=max(sell,not sell)
//         }
//         return dp[ind][buy]=ans;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
//         //here size 2 cuz buy and sell
//         return solve(prices,0,1,dp);
//     }
// };



















class Solution {
public:
    int solve(vector<int>& prices,vector<vector<int>> &dp,int ind,int flag){
        int n=prices.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind][flag]!=-1){
            return dp[ind][flag];
        }
        int ans=0;
        if(flag==1){
            ans=max(-prices[ind]+solve(prices,dp,ind+1,0),0+solve(prices,dp,ind+1,1));
        }else{
            ans=max(prices[ind]+solve(prices,dp,ind+2,1),0+solve(prices,dp,ind+1,0));
        }
        return dp[ind][flag]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,dp,0,1);
    }
};








