class Solution {

    int f(int i , string& s , vector<int>& dp){
        //base case
        if(i == s.size()){
            return 1;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        if(s[i] == '0'){ //invalid string
            return 0;
        }

        //take one digit
        int ans = f(i+1 , s , dp);

        //take two digits
        if(i+1 < s.size()){
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if(num >= 10 && num <= 26) {
                ans += f(i + 2, s , dp);
            }
        }

        return dp[i] = ans;
        
    }
public:
    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n , -1);

        return f(0 , s , dp);
        
    }
};