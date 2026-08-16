class Solution {

    void findCombination(int index , vector<int>& candidates, int target , vector<vector<int>> &ans , vector<int> &ds){

        if(index == candidates.size()){
            if(target == 0){
                ans.push_back({ds}); //pushing the subset into final list
            }
            return;
        }

        if(candidates[index] <= target){
            //pick the number
            ds.push_back(candidates[index]);
            findCombination(index , candidates , target - candidates[index] , ans , ds);
            ds.pop_back();
        }

        //not pick the number
        findCombination(index+1 , candidates , target , ans , ds);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans; //final result
        vector<int> ds; //data structure that will carry out subsets

        findCombination(0 , candidates , target , ans , ds);

        return ans;
        
    }
};