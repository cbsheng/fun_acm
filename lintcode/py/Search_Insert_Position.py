class Solution:
    """
    @param A : a list of integers
    @param target : an integer to be inserted
    @return : an integer
    """
    def searchInsert(self, A, target):
        beg = 0
    	end = len(A) - 1
    	while (beg < end):
    		mid = (beg + end) / 2
    		if A[mid] == target:
    			return mid
    		elif A[mid] < target:
    			beg = mid + 1
    		else:
    			end = mid
    	if (beg == end):
    		if (A[beg] < target):
    			return beg + 1
    		else:
    			return beg
    	return 0