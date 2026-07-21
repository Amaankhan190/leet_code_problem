class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        vector<int> zeroGroups;

        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;

            int len = j - i;

            if (s[i] == '1')
                ones += len;
            else
                zeroGroups.push_back(len);

            i = j;
        }

        int best = 0;
        for (int i = 0; i + 1 < zeroGroups.size(); i++)
            best = max(best, zeroGroups[i] + zeroGroups[i + 1]);

        return ones + best;
    }
};