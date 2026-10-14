class Solution {
public:
    string maxSumOfSquares(int num, int sum) 
    {
        if (sum > 9 * num) return std::string();

        std::string res;
        res.reserve(num);
        
        int nines = sum / 9;
        int rem = sum % 9;
        res.append(nines, '9');
        num -= nines;
        if (rem) 
        {
            res.push_back(rem + '0');
            num--;
        }
        res.append(num, '0');
        
        return res;
    }
};

// num = 1, max_sum = 9
// num = 2, max_sum = 18
// num = 3, max_sum = 27
// num = 4, max_sum = 36