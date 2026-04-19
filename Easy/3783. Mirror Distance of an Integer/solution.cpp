class Solution {
public:
    int mirrorDistance(int n) {
        int copy1 = n, len = 0;
        while (copy1 >= 1)
        {
            copy1 /= 10;
            len++;
        }

        int copy2 = n, reverse = 0;
        while (len > 0)
        {
            reverse += ( (copy2 % 10) * std::pow(10, len-1) );
            copy2 /= 10;
            len--;
        }

        return (n < reverse) ? reverse - n : n - reverse;
    }
};
