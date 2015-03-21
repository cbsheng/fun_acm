class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if not strs or '' in strs:
            return ''
        res = strs[0]
        for i in strs[1:]:
            res = self.common(res, i)
        return res
            
    def common(self, s1, s2):
        if '' in [s1, s2]:
            return ''
        for i in xrange(min(len(s1), len(s2))):
            if s1[i] != s2[i]:
                return s1[:i]
        return s1[:i+1]