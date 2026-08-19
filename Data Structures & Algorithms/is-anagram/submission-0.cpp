class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int> counts(26 , 0);

        if(s.size() != t.size()){
            return false;
        }


        for(int i = 0 ; i < s.size() ; i++){
            counts[s[i] - 'a']++;
        }

        for(int i = 0 ; i < t.size() ; i++){
            counts[t[i] - 'a']--;
        }

        for(int count : counts){
            if(count != 0){
                return false;
            }
        }
        
        return true;

    }
};
