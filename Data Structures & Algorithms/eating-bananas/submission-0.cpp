class Solution {
private:
    long long calculateTotalHours(vector<int>& piles, int hourly) {
        long long totalHours = 0;

        for (int pile : piles) {
            totalHours += (pile + hourly - 1) / hourly;
        }

        return totalHours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalHrs = calculateTotalHours(piles, mid);

            if (totalHrs <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};