class Solution {
public:

    int minCost(int n) 
    {
        if (n == 0 || n == 1) return 0;

        return n * (n-1) / 2;
    }
};

// cost = a * b, where a + b = x
// for all x, the min cost is a = 1, b = x-1 