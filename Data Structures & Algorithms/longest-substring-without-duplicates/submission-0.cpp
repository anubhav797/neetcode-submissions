class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> hash(256, -1);   // Stores last index of each character

        int l = 0;
        int r = 0;
        int n = s.size();
        int maxLen = 0;

        while (r < n) {

            // Character has been seen before
            if (hash[s[r]] != -1) {

                // Previous occurrence lies inside the current window
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            // Update last seen index
            hash[s[r]] = r;

            // Update answer
            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};