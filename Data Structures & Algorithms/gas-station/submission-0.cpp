class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int m = cost.size();
        int totalGas = 0;
        int totalCost = 0;

        for(int val : gas){
            totalGas += val;
        }
        for(int val : cost){
            totalCost += val;
        }
        if(totalGas < totalCost){
            return -1; //there is not enough gas to compensate the cost
        }

        //unique solution exists
        int start = 0;
        int currentGas = 0;

        for(int i = 0 ; i < n ; i++){
            currentGas += (gas[i] - cost[i]);

            if(currentGas < 0){
                currentGas = 0;
                start = i + 1;
            }
        }

        return start;
        
    }
};