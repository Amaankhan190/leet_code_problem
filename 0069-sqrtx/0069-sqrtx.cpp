class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        long long l=0,h=x;
        while(l<=h){
            long long mid=l+(h-l)/2;

            if(mid*mid==x)
                return mid;
            else if(mid*mid<x)
                l=mid+1;
            else
                h=mid-1;
        }
        return h;
    }   
};