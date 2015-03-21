class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        s = str(x)
        length = len(s)
        if length == 1:
            return True
        else:
            mid = length / 2
            if length % 2 == 0:
                return True if s[:mid] == s[mid:][::-1] else False
            else:
                return True if s[:mid] == s[mid+1:][::-1] else False