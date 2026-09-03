class Solution {

    int f(int i , int end , vector<int>& dp , vector<int> &nums){
        //base case
        if(i > end){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int take = nums[i] + f(i+2 , end , dp , nums);
        int nonTake = f(i+1 , end , dp , nums);

        return dp[i] = max(take , nonTake);

    }
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        //case 1 where last element is excluded
        vector<int> dp(n , -1);
        int case1 = f(0 , n-2 , dp , nums);

        //case 2 where first element is excluded
        vector<int> dp2(n , -1);
        int case2 = f(1 , n-1 , dp2 , nums);

        return max(case1 , case2);
        
    }
};