class Solution:
    def init(self):
        self.d = {}
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        self.init()
        return self.myclimbStairs(n)
    
    def myclimbStairs(self, n):
        if self.d.get(n):
            return self.d[n]
        if n == 0:
            return 1
        elif n < 0:
            return 0
        self.d[n] = self.myclimbStairs(n-1) + self.myclimbStairs(n-2)
        return self.d[n]