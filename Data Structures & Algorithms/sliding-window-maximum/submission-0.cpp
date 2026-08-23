class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans;
        deque<int> dq; //dq will be used to store indices only

        for(int i = 0 ; i <= n-1 ; i++){
            //remove elements outside window
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            //push current index
            dq.push_back(i);

            //store answer when first window forms
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
        
    }
};