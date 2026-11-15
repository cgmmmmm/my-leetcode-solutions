class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        constexpr int MOD = 1'000'000'007;

        int n = arr.size();

        int ps = 0;
        int odd_sums = 0;
        int even_sums = 1;
        int res = 0;

        for (int num : arr)
        {
            ps += num;

            if (ps & 1)
            {
                res = (res + even_sums) % MOD;
                odd_sums += 1;
            }
            else
            {
                res = (res + odd_sums) % MOD;
                even_sums += 1;
            }
        }

        return res;
    }
};

/**

When there is one odd, the result is odd.
1. odd + even = odd
    odd - even = odd
    even - odd = odd

When both are either even or odd, the result is always even.
2. odd + odd = even
    odd - odd = even

3. even + even = even
    even - even = even

*/