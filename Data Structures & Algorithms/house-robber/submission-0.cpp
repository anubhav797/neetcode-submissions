class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1 ; i < n ; i++){
            int take = nums[i]; //taking the value
            if(i > 1){
                take += prev2; //adding the non adjacent value if index > 1
            }

            int nonTake = 0 + prev; //0 means we are not taking the guy and are taking previous adjacent value

            int current = max(take , nonTake); //selecting which gives max output

            prev2 = prev;
            prev = current;
        }

        return prev;
        
    }
};