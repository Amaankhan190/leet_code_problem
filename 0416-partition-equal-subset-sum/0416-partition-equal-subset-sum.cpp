class Solution {
public:

    bool solve(int i,int target,vector<int>& nums,vector<vector<int>>&dp){

        if(target==0)
            return true;
        if(i>=nums.size() || target<0)
            return false;

        if(dp[i][target]!=-1)
            return dp[i][target];
        
        bool take=solve(i+1,target,nums,dp);
        bool take1=false;
        if(target>=nums[i]){
            take1=solve(i+1,target-nums[i],nums,dp);
        }
        return dp[i][target]=take||take1;
    }



    bool canPartition(vector<int>& nums) {
      int n=nums.size();
      int sum=0;
      for(int x:nums)
        sum+=x;
        if(sum%2==1)
            return false;
        sum/=2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(0,sum,nums,dp);  
    }
};