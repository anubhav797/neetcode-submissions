class Solution {

private:
    void getString(int open , int close , int n , string &s , vector<string> &ans){
        //base case
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        //push '('
        if(open < n){
            s.push_back('(');
            getString(open+1 , close , n , s , ans);
            s.pop_back(); //allows backtracking to explore another combinations 
        }

        if(close < open){
            s.push_back(')');
            getString(open , close+1 , n , s , ans);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string s;

        getString(0 , 0 , n , s , ans);

        return ans;
        
    }
};