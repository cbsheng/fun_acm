class Solution:
    # @return a string
    def convert(self, s, nRows):
        if len(s) == 0 or nRows == 0:
            return ''
        if nRows == 1:
            return s
        row = nRows
        i = 1
        ss = s[:]
        ll = []
        while len(ss):
            if i % 2 == 0:
                #偶数
                if len(ss) >= (row - 2):
                    l = '0'+ss[:row-2] + '0'
                    ss = ss[row-2:]
                else:
                    l = '0' + ss[:] + '0'*(row-1-len(ss))
                    ss = []
            else:
                #奇数
                if len(ss) >= row:
                    l = ss[:row]
                    ss = ss[row:]
                else:
                    l = ss[:] + '0'*(row-len(ss))
                    ss = []
            i = i + 1
            ll.append(l)
    
        for i, l in enumerate(ll):
            if i % 2 != 0:
                ll[i] = l[::-1]
        ll = zip(*ll)
        result = ""
        for t in ll:
            for i in t:
                if i != '0':
                    result = result + i
        return result