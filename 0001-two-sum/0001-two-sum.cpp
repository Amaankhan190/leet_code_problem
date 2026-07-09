class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int i=0;
        for(int x:nums){

            int num2=target-x;
            if(mpp.find(num2)!=mpp.end()){
                return {mpp[num2],i};
            }

            mpp[x]=i;
            i++;

        }
        return {-1,-1};
    }
};