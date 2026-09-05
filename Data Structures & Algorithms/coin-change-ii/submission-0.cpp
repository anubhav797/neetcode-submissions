class Solution {

    int f(int i , int target , vector<int> &coins , vector<vector<int>> &dp){
        if(target == 0){
            return 1;
        }
        if(i == coins.size()){
            return 0;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        int nonTake = f(i+1 , target , coins , dp);

        int take = 0;
        if(coins[i] <= target){
            take = f(i , target - coins[i] , coins , dp);
        }

        return dp[i][target] = take + nonTake;
    }

public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n , vector<int> (amount +1 , -1));

        return f(0 , amount , coins , dp);
        
    }
};
