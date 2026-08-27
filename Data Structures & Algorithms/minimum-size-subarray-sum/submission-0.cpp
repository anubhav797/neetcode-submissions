class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int right = 0;
        int n = nums.size();

        int minLen = INT_MAX;
        int sum = 0;

        while(right < n) {

            sum += nums[right];

            while(sum >= target) {

                minLen = min(minLen, right - left + 1);

                sum -= nums[left];
                left++;
            }

            right++;
        }

        if(minLen == INT_MAX) {
            return 0;
        }

        return minLen;
    }
};