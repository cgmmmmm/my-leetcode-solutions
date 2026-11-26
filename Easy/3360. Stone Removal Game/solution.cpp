class Solution {
public:
    bool canAliceWin(int n) 
    {
        if (n<10) return false;
        if (n>=10 && n<=18) return true;
        if (n>=27 && n<=33) return true;
        if (n>=40 && n<=44) return true;
        if (n>=49 && n<=50) return true;
        return false;
    }
};


// 1-9: alice loses
// 10-18: alice wins
// 19-26: alice loses
// 27-33: alice wins
// 34-39: alice loses
// 40-44: alice wins
// 45-48: alice loses
// 49-50: alice wins
