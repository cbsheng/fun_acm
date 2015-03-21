class Solution:
    # @return an integer
    def reverse(self, x):
        if x == 0:
            return x
        else:
            res = int(str(x).rstrip('0')[::-1]) if x > 0 else int(str(x)[1:].rstrip('0')[::-1]) * -1
            return 0 if res > 2147483647 or res < -2147483647 else res