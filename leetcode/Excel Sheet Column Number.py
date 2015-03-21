class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        return 0 if not s else self.titleToNumber(s[1:]) + (ord(s[0]) + 1 - ord('A')) * (26 ** (len(s)-1))