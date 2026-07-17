class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<long long>gcd_count(mx+1,0);

        for(int x:nums){
            for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    if(i==x/i)
                        gcd_count[i]++;
                    else{
                        gcd_count[i]++;
                        gcd_count[x/i]++;
                    }
                }       
            }
        }

        for(int i=mx;i>=1;i--){
            long long count=gcd_count[i];
            gcd_count[i]=count*(count-1)/2;


            for(int ele=2*i;ele<=mx;ele+=i){
                gcd_count[i]-=gcd_count[ele];
            }
        }

        for(int i=1;i<=mx;i++){
            gcd_count[i]+=gcd_count[i-1];
        }
        vector<int>ans;
        for(long long x:queries){
            x++;
            long long a=lower_bound(gcd_count.begin(),gcd_count.end(),x)-gcd_count.begin();
            ans.push_back(a);
        }
        return ans;
    }
};