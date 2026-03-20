class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1, high = n;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if ((long long)mid * (mid + 1) / 2 <= n) {
                low = mid + 1;   
            } else {
                high = mid - 1;  
            }
        }

        return high; 
    }
};