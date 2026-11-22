class Solution:
    def checkString(self, s: str) -> bool:
        b_appeared = 0
        for ch in s:
            if ch == 'b':
                b_appeared = 1
            elif b_appeared:
                return False
        return True
