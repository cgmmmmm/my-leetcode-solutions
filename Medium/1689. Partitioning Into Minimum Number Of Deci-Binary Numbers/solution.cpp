class Solution {
public:
    int minPartitions(string n) 
    {
        int res = 1;
        for (char digit : n)
        {
            int x = digit - '0';
            res = (res < x) ? x : res; 
        }
        return res;
    }
};