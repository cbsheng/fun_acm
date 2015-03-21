class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        def fun(a, b):
            return b[1] - a[1]
            
        d = {}
        for i in num:
            if d.get(i):
                d[i] += 1
            else:
                d.setdefault(i, 1)
        l = list(d.items())
        l.sort(cmp=fun)
        return l[0][0]
        