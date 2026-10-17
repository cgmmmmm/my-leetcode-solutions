// {digitSum, originalNumber, originalIndex}
struct Node
{
    int ds;
    int ori;
    int oriIdx;

    bool operator<(const Node& other) const
    {
        if (ds != other.ds)
        {
            return ds < other.ds;
        }
        return ori < other.ori;
    }
};

class Solution {
public:
    int calcDigitSum(int num)
    {
        int ds = 0;
        while (num)
        {
            ds += (num % 10);
            num /= 10;
        }
        return ds;
    }

    int minSwaps(vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<Node> nodes(n);
        for (int i=0; i<n; ++i)
        {
            nodes[i] = {calcDigitSum(nums[i]), nums[i], i};
        }

        std::sort(nodes.begin(), nodes.end());

        std::vector<bool> visited(n, false);
        int swaps = 0;
        for (int i=0; i<n; ++i)
        {
            if (visited[i] || nodes[i].oriIdx == i) continue;

            int swap = 0;
            int cycleIdx = nodes[i].oriIdx;
            while (cycleIdx != i)
            {
                visited[cycleIdx] = true;
                cycleIdx = nodes[cycleIdx].oriIdx;
                swap++;
            }
            swaps += swap;
        }

        return swaps;
    }
};