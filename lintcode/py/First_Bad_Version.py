#class VersionControl:
#    @classmethod
#    def isBadVersion(cls, id)
#        # Run unit tests to check whether verison `id` is a bad version
#        # return true if unit tests passed else false.
# You can use VersionControl.isBadVersion(10) to check whether version 10 is a 
# bad version.
class Solution:
    """
    @param n: An integers.
    @return: An integer which is the first bad version.
    """
    def findFirstBadVersion(self, n):
        beg = 1
        end = n
        mid, res = 0, n
        while beg < end:
            mid = (beg + end) >> 1
            isBad = VersionControl.isBadVersion(mid)
            if (isBad and res > mid):
                res = mid
            if (isBad):
                end = mid
            else:
                beg = mid + 1
        return res
