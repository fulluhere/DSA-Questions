class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
       
        for i in range(len(s)):
            st = s[i:]+s[:i]
            if st == goal:
                return True

        return False

        