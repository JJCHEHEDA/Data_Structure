#url: https://leetcode-cn.com/problems/longest-palindromic-substring/description/

class Solution:
    def longestPalindrome(self, s):
        if not s or len(s) == 1 or s == s[::-1]:
            return s
        res,cas = 1,0
        length = len(s)
        dp = [[False for i in range(length)] for j in range(length)]
        dp[0][0]=True
        for j in range(1,length):
            dp[j][j]=True
            for i in range(j):
                if j == i+1 and s[i] == s[j]:
                    dp[i][j]=True
                if j > i+1:
                    if dp[i+1][j-1] == True and s[i] == s[j]:
                        dp[i][j]=True
                if dp[i][j] and res < j-i+1:
                    res = j-i+1
                    cas = i
        return s[cas:cas+res]