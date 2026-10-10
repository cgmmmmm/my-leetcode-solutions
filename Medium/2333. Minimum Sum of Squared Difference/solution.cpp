class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        int n = nums1.size();
        long long k = k1 + k2;
        std::priority_queue<long long> max_heap;
        long long sum = 0;
        for (int i=0; i<n; ++i)
        {
            int a = nums1[i], b = nums2[i];
            int x = (a>b) ? a-b : b-a;
            sum += x;
            max_heap.push(x);
        }

        if (k >= sum) return 0;

        max_heap.push(0);
        
        long long res = 0;
        int candidate_num = 0;
        while (max_heap.size() > 1 && k > 0)
        {
            long long x = max_heap.top();
            max_heap.pop();
            candidate_num++;

            long long diff = x - max_heap.top();
            long long distribution = (candidate_num * diff);

            if (distribution > k)
            {
                long long subtract_by = k / candidate_num; // number to subtract for even distribution
                long long extra = k % candidate_num; // how many extra subtraction, minus 1 to perform
                
                long long cand_val = x - subtract_by;

                res += extra * ((cand_val - 1) * (cand_val - 1));
                res += (candidate_num - extra) * (cand_val * cand_val);

                candidate_num = 0;
                k = 0;
                break;
            }
            else
            {
                k -= distribution;
            }
        }

        if (candidate_num > 0)
        {
            long long num = max_heap.top();
            res += candidate_num * (num * num);
        }
        
        while (!max_heap.empty())
        {
            long long x = max_heap.top();
            res += (x * x);
            max_heap.pop();
        }
        
        return res;
    }
};