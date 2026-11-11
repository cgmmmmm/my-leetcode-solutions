using ll = long long;

class Solution {
public:
    ll minimumCost(ll c1, ll c2, ll c3, ll n1, ll n2) 
    {
        if (n1 == 0 && n2 == 0) return 0;

        // case 1
        if (c3 >= c1 + c2) return n1 * c1 + n2 * c2;
        
        // case 2
        if (c3 <= c1 && c3 <= c2) return std::max(n1, n2) * c3;

        // case 3
        ll z = std::min(n1, n2);
        return (n1 - z) * std::min(c1, c3) + (n2 - z) * std::min(c2, c3) + z * c3;
    }
};