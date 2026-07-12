class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& nums, int target){

        if(target==0)
            return 1;
        if(target<0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        int ans=0;
        for(int x:nums)
            ans+=solve(nums,target-x);

        return dp[target]=ans;

    }



    int combinationSum4(vector<int>& nums, int target) {

        dp.assign(target+1,-1);
        return solve(nums,target);
    }
};