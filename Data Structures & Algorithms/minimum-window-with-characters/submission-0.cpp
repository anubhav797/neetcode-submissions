class Solution {
public:

    bool contains(vector<int>& maps, vector<int>& mapT) {
        for(int i = 0; i < 256; i++) {
            if(mapT[i] > maps[i])
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {

        vector<int> mapS(256, 0);
        vector<int> mapT(256, 0);

        int left = 0;
        int right = 0;

        int minLength = INT_MAX;
        int startIndex = 0;

        // Store character occurrences of t
        for(int i = 0; i < t.size(); i++) {
            mapT[t[i]]++;
        }

        // Work on string s
        while(right < s.size()) {

            // Add right character to the window
            mapS[s[right]]++;

            // Shrink the window
            while(contains(mapS, mapT)) {

                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }

                // Remove left character
                mapS[s[left]]--;
                left++;
            }

            right++;
        }

        if(minLength == INT_MAX) {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};