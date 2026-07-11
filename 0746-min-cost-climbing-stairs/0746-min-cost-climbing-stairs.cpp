class Solution {
public:

    int solve(int i,vector<int>& cost,vector<int>&dp){
        if(i==cost.size()-1 || i==cost.size()-2)
            return cost[i];
        if(dp[i]!=-1)
            return dp[i];
        int take=cost[i]+solve(i+1,cost,dp);
        int non_take=cost[i]+solve(i+2,cost,dp);
        return dp[i]=min(take,non_take);
    }




    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};