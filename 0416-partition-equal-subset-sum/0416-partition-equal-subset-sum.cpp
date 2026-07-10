class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        for(int x:nums)
            sum+=x;
        
        if(sum%2==1)
            return false;

        int target=sum/2;
        
        vector<vector<bool>>dp(n,vector<bool>(target+1,0));

        for(int i=0;i<n;i++)
            dp[i][0]=1;
        
        if(target>=nums[0])
            dp[0][nums[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                int non_take=dp[i-1][j];
                int take=0;
                if(j>=nums[i])
                    take=dp[i-1][j-nums[i]];
                dp[i][j]=non_take || take;
            }
        }
        return dp[n-1][target];
    }
};