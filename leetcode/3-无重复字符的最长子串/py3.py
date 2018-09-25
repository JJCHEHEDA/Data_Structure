class Solution:
    def lengthOfLongestSubstring(self, s):
        l,r,res = 0,1,1
        if not s:
            return 0
        if len(s) == 1:
            return 1
        while l <= r and r < len(s):
            if s[r] not in s[l:r]:
                res = max(res,r-l+1)
                r += 1
            else:
                l = l+s[l:r].index(s[r])+1
                res = max(res,r-l+1)
        return res