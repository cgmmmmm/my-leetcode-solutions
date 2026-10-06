class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int rOpen = 0; // require open number
        int rClose = 0; // require close number
        for (char ch : s)
        {
            if (ch == '(') 
                rClose++;
            else
            {
                if (rClose == 0)
                {
                    rOpen++;
                }
                else
                {
                    rClose--;
                }
            }
        }

        return rOpen + rClose;
    }
};