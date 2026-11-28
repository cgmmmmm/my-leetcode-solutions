using ull = unsigned long long;

class Solution {
public:
    int maximumSaleItems(std::vector<std::vector<int>>& items, int budget) 
    {
        int n = items.size();

        int min_price = INT_MAX;
        for (const auto& item : items)
        {
            min_price = std::min(min_price, item[1]);
        }

        std::vector<int> freq(n+1, 0);
        for (auto& item : items)
        {
            freq[item[0]]++;
        }

        std::vector<int> divisible(n+1, 0); // number of factor_j in the list divisible by factor_i;
        for (int i=1; i<=n; ++i)
        {
            if (freq[i] == 0) continue;

            int count = freq[i] - 1;

            for (int mult=2*i; mult<=n; mult+=i)
            {
                count += freq[mult];
            }

            divisible[i] = count;
        }

        std::sort(items.begin(), items.end(), [](const auto& item1, const auto& item2)
        {
            return item1[1] < item2[1];
        });

        int res = 0;
        ull remaining = budget;
        for (auto& item : items)
        {
            ull eligible_copies = divisible[item[0]], price = item[1];

            if (price > 2ULL * min_price) break;
            
            if (eligible_copies == 0) continue;

            ull purchase_amt = std::min(eligible_copies, remaining / price);

            remaining -= purchase_amt * price;
            
            res += 2 * purchase_amt;
        }

        res += remaining / min_price;

        return res;
    }
};

/**

1. for each item i, if there is an item j with factor_j such that (factor_j % factor_i == 0), meaning that purchasing x copy of item i yields 2x total copies. 

2. using a frequency array and multiple-based sieve, a Z+ x that can divide a Z+ y in the same list can be found efficiently in O(N+MlogM), N being the list length and M being the largest Z+.

3. sort the list by then price in ascending order

4. if normal purchases are more worth it than remaining boosted purchases, then spend all remaining budget on normal purchases

*/