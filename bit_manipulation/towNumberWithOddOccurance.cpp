class Solution {
  public:
    bool isPowerofTwo(int n) {
        // A power of two has only one bit set. So, n & (n - 1) will be 0.
        // Also, n must be greater than 0.
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};
