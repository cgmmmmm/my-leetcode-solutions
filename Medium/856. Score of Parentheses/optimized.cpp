/**
 * This optimized version calculate score everytime the most nested parentheses closes, by
 * exponentiating 2 to the power of depth, then add the result to the score of previous
 * balanced parentheses. 
 * 
 * This approach effectively saves memory by not using a stack, and is faster due to
 * the CPU executing simple calculations only.
 */

class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int score = 0;
        int depth = 0;
        for (int i=0; i<s.size(); ++i)
        {
            if (s[i] == '(')
                depth++;
            else
            {
                depth--;
                if (s[i-1] == '(')
                    score += (1 << depth);
            }
        }

        return score;
    }
};