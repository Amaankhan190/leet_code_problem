class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;

        while(columnNumber){
            if(columnNumber<=26) {
                if(columnNumber==0)
                    s+='Z';
                else
                    s+=(char)('A'+(columnNumber-1));
                break;
            }
            else{
                int num=columnNumber%26;
                if(num==0)
                    s+='Z';
                else
                    s+=(char)('A'+(num-1));
            }
            columnNumber/=26;
            if(s[s.length()-1]=='Z')
                columnNumber--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};