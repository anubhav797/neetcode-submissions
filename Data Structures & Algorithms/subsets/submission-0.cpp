class Solution {

private:
    void getSubsets(vector<int>& nums , vector<int> &ans , int i ,vector<vector<int>> &allSubsets){
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        //include the element
        ans.push_back(nums[i]);
        getSubsets(nums , ans , i+1 , allSubsets);

        //pop the last element
        ans.pop_back();

        //excluded the element
        getSubsets(nums , ans , i+1 , allSubsets);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getSubsets(nums , ans , 0 , allSubsets);

        return allSubsets;
        
    }
};