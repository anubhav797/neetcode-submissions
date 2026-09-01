class Solution {

    void getAllSubsets(vector<int> &nums , vector<int> &ans , vector<vector<int>> &subsets , int i){
        if(i == nums.size()){
            subsets.push_back(ans);
            return;
        }

        //include the element
        ans.push_back(nums[i]);
        getAllSubsets(nums , ans , subsets , i+1);

        ans.pop_back();

        int index = i+1;
        while(index < nums.size() && nums[index] == nums[index - 1]){
            index++; //skipping the duplicates
        }

        //excluding element
        getAllSubsets(nums , ans , subsets , index);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> ans;
        vector<vector<int>> subsets;
        sort(nums.begin() , nums.end());

        getAllSubsets(nums , ans , subsets , 0);

        return subsets;
        
    }
};