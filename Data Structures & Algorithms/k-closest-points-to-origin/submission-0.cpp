class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // min heap: {distance, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for(auto point : points) {
            int x = point[0];
            int y = point[1];

            int dist = x*x + y*y;

            minHeap.push({dist, x, y});
        }

        vector<vector<int>> res;

        while(k > 0) {
            auto curr = minHeap.top();
            minHeap.pop();

            res.push_back({curr[1], curr[2]});
            k--;
        }

        return res;
    }
};