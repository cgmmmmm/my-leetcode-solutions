class Solution {
public:
    void adder(int idx, int mult, auto& store) {
        auto carry = [&](int pos) -> void {
            while (pos > 0 && store[pos] > 9) {
                store[pos - 1] += store[pos] / 10;
                store[pos] %= 10;
                pos--;
            }
        };

        store[idx] += (mult % 10);
        carry(idx);
        store[idx - 1] += (mult / 10);
        carry(idx - 1); 
    }

    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
            return "0";
            
        int m = num2.size(), n = num1.size();
        int len = m+n;
        std::vector<int> store(len, 0);

        for (int i=m-1; i>=0; --i)
        {
            int x = num2[i]-'0';
            for (int j=n-1; j>=0; --j)
            {
                int y = num1[j]-'0';
                adder(i+j+1, x*y, store);
            }
        }

        std::string res;
        for (int i=0; i<m+n; ++i)
        {
            if (i==0 && !store[0]) continue;
            res.push_back(store[i]+'0');
        }

        return res;
    }
};