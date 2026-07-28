class Solution {
public:
    int N;
    int dp[101][101][101];
    long long MOD=1e9+7;
    int solve(int i,int people,int prft,int minProfit, vector<int>& group, vector<int>& profit){

        if(people>N)
            return 0;
        if(i==group.size()){
            if(prft>=minProfit)
                return 1;
            return 0;
        }
        if(dp[i][people][prft]!=-1)
            return dp[i][people][prft];
        long long non_take=(solve(i+1,people,prft,minProfit,group,profit))%MOD;
        long long take= (solve(i+1,people+group[i],min(prft+profit[i],minProfit),minProfit,group,profit))%MOD;

        return dp[i][people][prft]=(non_take+take)%MOD;

    }


    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N=n;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,minProfit,group,profit);
    }
};