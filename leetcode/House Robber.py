class Solution:
    # @param num, a list of integer
    # @return an integer
    def rob(self, num):
        e,i = 0,0
        for n in num:
            e,i = max(e, i+n), e
        return e