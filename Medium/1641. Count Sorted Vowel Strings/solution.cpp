class Solution {
public:
    int countVowelStrings(int n) 
    {
        int res = 5;

        for (int i=2; i<=n; ++i)
        {
            res = res * (i+4)/i;
        }

        return res;
        
        // std::vector<int> dp(n+1, 0);
        // dp[1] = 5;

        // for (int i=2; i<=n; ++i)
        // {
        //     dp[i] = dp[i-1] * (i+4)/i;
        // }

        // return dp[n];
    }
};

/**

n = 1: res = 5

n = 2: res = 15

n = 3: 


a
e 
i 
o 
u
res = (1x1) + (1x1) + (1x1) + (1x1) + (1x1)

(aa) [ae] ai ao au
(ee) ei eo eu
ii io iu
oo ou
uu
res = (1x5) + (1x4) + (1x3) + (1x2) + (1x1)

(aaa aae aai aao aau) [aee aei aeo aeu] aii aio aiu aoo aou auu
(eee eei eeo eeu) eii eio eiu eoo eou euu
iii iio iiu ioo iou iuu
ooo oou ouu
uuu
res = 

1
1
1
1
1

1 1 1 1 1
1 1 1 1
1 1 1
1 1 
1

5 4 3 2 1
4 3 2 1
3 2 1
2 1
1

n = 1, n = 2, n = 3
  1      5      15
  1      4      10
  1      3      6
  1      2      3
  1      1      1


*/