class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(int x:nums)
            mp[x]++;

        int ans=0;

        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int ele=pq.top(); pq.pop();
        ans+=ele;
        while(pq.size()){
            if(ele!=pq.top())
                break;
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};