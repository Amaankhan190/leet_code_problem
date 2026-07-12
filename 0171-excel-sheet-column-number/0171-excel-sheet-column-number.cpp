class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        int res=0;
        for(int i=0;i<n;i++){
            int value=columnTitle[i]-'A'+1;
            res=res*26+value;
        }
        return res;
    }
};