class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k==1) return nums;
        
        std::vector<int> res;
        // FIFO data structure
        std::deque<int> dq; // store the indices
        for (int i=0; i<nums.size(); ++i)
        {
            // i = 3, dq = {0,1,2,3}, k = 3, i-k=0 
            if (!dq.empty() && dq.front() == i - k) 
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);
            
            if (i >= k-1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
