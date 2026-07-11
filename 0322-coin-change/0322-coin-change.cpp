class Solution {
public:

    int solve(int i,int amount,vector<vector<int>>&dp,vector<int>& coins){

        if(i==0){
            if(amount%coins[i]==0)
                return amount/coins[i];
            return 1e9;
        }

        if(dp[i][amount]!=-1)
            return dp[i][amount];
        
        

        int take=1e9;
        if(amount>=coins[i])
            take=1+solve(i,amount-coins[i],dp,coins);
        
        int non_take=solve(i-1,amount,dp,coins)+0;
        return dp[i][amount]=min(take,non_take);
    }





    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans= solve(n-1,amount,dp,coins);

        return (ans>=1e9)?-1:ans;


    }
};