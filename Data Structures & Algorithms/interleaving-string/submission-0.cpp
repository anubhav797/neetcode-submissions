class Solution {

    bool f(int i , int j , string &s1 , string &s2 , string &s3 , vector<vector<int>> &dp){
        if(i == s1.size() && j ==s2.size()){ //both string are completely used
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool ans = false;

        //take character from first string
        if(i < s1.size() && s1[i] == s3[i+j]){
            ans = f(i+1 , j , s1 , s2 , s3 , dp);
        }

        //take character from second string
        if(!ans && j < s2.size() && s2[j] == s3[i+j]){
            ans = f(i , j+1 , s1 , s2 , s3 , dp);
        }

        return dp[i][j] = ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

        if(n + m != s3.size()){
            return false;
        }

        return f(0 , 0 , s1 , s2 , s3 , dp);
        
    }
};