class Solution {

private:
    void combination(int start , int n , int k , vector<vector<int>> &ans , vector<int> &temp){
        //base case
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        //start picking element
        for(int i = start ; i <= n ; i++){
            temp.push_back(i);
            combination(i+1 , n , k , ans , temp);
            temp.pop_back(); 
        }
    }    

public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> temp;

        combination(1 , n , k , ans , temp);

        return ans;
        
    }
};