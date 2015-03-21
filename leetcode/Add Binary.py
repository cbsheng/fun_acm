class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        d = {0:0, 1:1, 2:0, 3:1}
        d_carry = {0:0, 1:0, 2:1, 3:1}
        if len(a) > len(b):
            Max, Min = a[::-1], b
        else:
            Max, Min = b[::-1], a
        Max = [int(i) for i in Max]
        Min = [int(i) for i in Min]
        res = []
        carry = 0
        for i in Max:
            sum = i + carry + Min.pop() if Min else i + carry
            res.append(d[sum])
            carry = d_carry[sum]
        if carry != 0:
            res.append(carry)
        res.reverse()
        return ''.join([str(i) for i in res])