class Solution {

    int f(int index , int target , vector<int> &coins , vector<vector<int>> &dp){
        int n = coins.size();
        
        if(index == n-1){
            if(target % coins[index] == 0){
                return target/coins[index] ;
            }
            else{
                return 1e9;
            }
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        int nonTake = 0 + f(index + 1 , target , coins , dp);
        int take = INT_MAX;

        if(coins[index] <= target){
            take = 1 + f(index , target - coins[index] , coins , dp);
        } //condition to pick up the coin

        return dp[index][target] = min(take , nonTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));

        int ans = f(0 , amount , coins , dp);

        if(ans >= 1e9){
            return -1;
        }
        else{
            return ans;
        }
        
    }
};