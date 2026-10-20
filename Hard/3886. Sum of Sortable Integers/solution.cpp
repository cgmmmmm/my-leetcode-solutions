class Solution {
public:
    int sortableIntegers(vector<int>& nums) 
    {
        int n = nums.size();

        int sumFactors = 0;
        std::vector<int> factors;
        for (int k=1; k*k<=n; ++k)
        {
            if (n % k == 0)
            {
                factors.push_back(k);
                sumFactors += k;

                int pf = n / k;
                if (k != pf)
                {
                    factors.push_back(pf);
                    sumFactors += pf;
                }
            }
        }

        if (std::is_sorted(nums.begin(), nums.end())) return sumFactors;

        int res = 0;
        for (int k : factors)
        {
            if (k == 1) continue;

            std::vector<int> temp = nums;

            bool cyclicallySortable = true;
            int i = 0;
            while (i < n)
            {
                std::span<int> sub_view(&temp[i], k);

                int smallestElementIndex = isCyclicallySortable(sub_view);
                if (smallestElementIndex == -2)
                {
                    i += k;
                }
                else if (smallestElementIndex == -1)
                {
                    cyclicallySortable = false;
                    break;
                }
                else
                {
                    std::rotate(temp.begin() + i, temp.begin() + i + smallestElementIndex, temp.begin() + i + k); 
                    i += k;
                }
            }

            if (!cyclicallySortable) continue;

            if (std::is_sorted(temp.begin(), temp.end())) res += k;
        }

        return res;
    }

    int isCyclicallySortable(std::span<const int> vec)
    {
        // -2 : input already sorted
        // -1 : not cyclically sortable
        // x > 0 : smallestElementIndex

        size_t n = vec.size();

        if (n <= 2) return (vec[0] > vec[1]) ? 1 : 0;

        int idx = -1; // smallest element index
        int drops = 0;
        for (size_t i=0; i<n; ++i)
        {
            if (vec[i] > vec[(i + 1) % n])
            {
                drops++;
                if (drops > 1) return -1;
                idx = (i + 1) % n;
            }
        }

        if (drops == 0) return -2;

        return idx;
    }
};

// i <= x < i+k