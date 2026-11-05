class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;

        for (int num1 : arr1)
        {
            bool valid = true;
            for (int num2 : arr2) if (std::abs(num1 - num2) <= d) { valid = false; break; }
            if (valid) res++;
        }

        return res;
    }
};