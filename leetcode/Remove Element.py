class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        if not A:
            return 0
        else:
            for i in A:
                if i == elem:
                    A.remove(i)
                    return self.removeElement(A, elem)
        return len(A)