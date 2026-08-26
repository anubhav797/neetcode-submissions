class Solution {

private:
    int f(int index , int n , vector<int> &cost , vector<int> &dp){
        //base case
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int firstStep = cost[index] + f(index + 1 , n , cost , dp);
        int secondStep = cost[index] + f(index + 2 , n , cost , dp);

        return dp[index] = min(firstStep , secondStep);

    }    

public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        vector<int> dp(n , -1);

        int result0 = f(0 , n , cost , dp);
        int result1 = f(1 , n , cost , dp);

        return min(result0 , result1);

        
    }
};