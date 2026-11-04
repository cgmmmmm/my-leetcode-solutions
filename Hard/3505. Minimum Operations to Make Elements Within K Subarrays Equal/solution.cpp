using ll = long long;

class Solution {
private:
    std::priority_queue<int> left;
    int left_size = 0;
    ll small_sum = 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> right;
    int right_size = 0;
    ll large_sum = 0;

    std::unordered_map<int, int> delayed_left;
    std::unordered_map<int, int> delayed_right;

public:
    const ll INF = LLONG_MAX / 4;

    template <typename Heap>
    void prune(Heap& heap, std::unordered_map<int, int>& delayed)
    {
        while (!heap.empty())
        {
            int num = heap.top();

            auto it = delayed.find(num);
            if (it == delayed.end()) break;
            heap.pop();

            it->second--;
            if (it->second == 0) delayed.erase(it);
        }
    }

    void addNum(int num)
    {
        prune(left, delayed_left);
        prune(right, delayed_right);

        if (left_size == 0 && right_size > 0)
        {
            int val = right.top();
            right.pop();

            right_size--;
            large_sum -= val;

            left.push(val);
            left_size++;
            small_sum += val;
        }

        if (left_size == 0 || num <= left.top())
        {
            left.push(num);
            left_size++;
            small_sum += num;
        }
        else
        {
            right.push(num);
            right_size++;
            large_sum += num;
        }

        if (left_size > right_size + 1)
        {
            prune(left, delayed_left);

            int val = left.top();
            left.pop();
            left_size--;
            small_sum -= val;

            right.push(val);
            right_size++;
            large_sum += val;
        }
        else if (right_size > left_size)
        {
            prune(right, delayed_right);

            int val = right.top();
            right.pop();
            right_size--;
            large_sum -= val;

            left.push(val);
            left_size++;
            small_sum += val;
        }
    }

    void removeNum(int num)
    {
        prune(left, delayed_left);
        prune(right, delayed_right);

        if (num <= left.top())
        {
            delayed_left[num]++;
            
            left_size--;
            small_sum -= num;

            if (num == left.top()) prune(left, delayed_left);
        }
        else
        {
            delayed_right[num]++;

            right_size--;
            large_sum -= num;

            if (num == right.top()) prune(right, delayed_right);
        }
    }

    int getMedian()
    {
        prune(left, delayed_left);
        return left.top();
    }

    ll getCost()
    {
        int median = getMedian();

        ll small_cost = left_size * 1LL * median - small_sum;
        ll large_cost = large_sum - right_size * 1LL * median;

        return small_cost + large_cost;
    }

    ll minOperations(vector<int>& nums, int x, int k) 
    {
        int n = nums.size();
        
        std::vector<ll> ops(n);
        int l = 0, r = 0;
        while (r < n)
        {
            addNum(nums[r]);
            if (r-l+1 == x)
            {
                ops[r] = getCost();
                
                removeNum(nums[l]);
                l++;
            }
            r++;
        }

        std::vector<std::vector<ll>> dp(n+1, std::vector<ll>(k+1, INF));
        for (int i=0; i<=n; ++i) dp[i][0] = 0;
        for (int i=1; i<=n; ++i)
        {
            for (int j=1; j<=k; ++j)
            {
                dp[i][j] = dp[i-1][j];

                if (i >= x && dp[i-x][j-1] != INF)
                {
                    ll cost = dp[i-x][j-1] + ops[i-1];

                    dp[i][j] = std::min(dp[i][j], cost);
                }
            }
        }

        return dp[n][k];
    }
};

// ll small_cost = left_size * median - small_sum;
// ll large_cost = large_sum - right_size * median;
// ll cost = small_cost + large_cost;