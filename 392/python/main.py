class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        idx = 0
        for c in t:
            if idx == len(s):
                return True
            if c == s[idx]:
                idx += 1
        
        if idx == len(s):
            return True
        else:
            return False

if __name__ == "__main__":
    s = "abc"
    # s = "axc"
    t = "ahbgdc"
    sol = Solution()
    print(sol.isSubsequence(s,t))