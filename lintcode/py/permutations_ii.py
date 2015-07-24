class Solution:
    """
    @param nums: A list of integers.
    @return: A list of unique permutations.
    """
    def permuteUnique(self, nums):
        if not nums:
            return []
        nums = sorted(nums)
        return self.mypermute([], [], nums)
        
    def mypermute(self, res, l, nums):
        if nums == []:
    		res.append(l)
    		return
    	for i in range(len(nums)):
	    	if (i > 0 and nums[i] == nums[i-1]): continue
    		l.append(nums[i])
    		tmp = nums[:]
    		tmp.remove(nums[i])
    		self.mypermute(res, l, tmp)
    		l = l[:-len(nums)]
    	return res

