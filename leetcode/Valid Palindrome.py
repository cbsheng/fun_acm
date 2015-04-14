class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        def myfilter(i):
            if i.isalpha() or i.isdigit():
                return True
        if not s:
            return True
        s = [i.upper() for i in filter(myfilter, s)]
        if s == s[::-1]:
            return True
        else:
            return False