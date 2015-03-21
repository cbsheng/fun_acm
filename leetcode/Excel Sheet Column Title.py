class Solution:
    # @return a string
    def convertToTitle(self, num):
        l=[]
        while num:
            l.append((num-1)%26)
            num=(num-1)/26
        s=''.join([chr(ord('A')+i) for i in l])
        return s[::-1]