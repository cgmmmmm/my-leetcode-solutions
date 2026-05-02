// valid if digit rotated 180deg is still a digit
// valid = {0, 1, 2, 5, 6, 8, 9}
// invalid = {3, 4, 7}
// good integer is when rotated 180deg is a different VALID integer
// good = {2, 5, 6, 9}

// problem stated EVERY digit in the integer must be rotated 
// that means encountering one of the invalid digit, means that the integer is not good
// the integer is only good when it has BOTH valid and good digits

class Solution {
public:
    int rotatedDigits(int n) 
    {
        std::unordered_set<char> valid{'0', '1', '2', '5', '6', '8', '9'};
        std::unordered_set<char> good{'2', '5', '6', '9'};

        int res = 0;
        for (int i=1; i<=n; i++)
        {
            std::string numberString = std::to_string(i);
            bool potentiallyGood = false;
            for (char c : numberString)
            {
                if (!valid.count(c)) 
                {
                    potentiallyGood = false;
                    break;
                }
                if (good.count(c)) potentiallyGood = true;
            }

            if (potentiallyGood) res++;
        }

        return res;
    }
};
