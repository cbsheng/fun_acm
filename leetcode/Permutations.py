class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def permute(self, nums):
        return self.mypermute([], [], nums)
        
    def mypermute(self, res, l, nums):
        if nums == []:
    		res.append(l)
    		return
    	for i in range(len(nums)):
    		l.append(nums[i])
    		tmp = nums[:]
    		tmp.remove(nums[i])
    		self.mypermute(res, l, tmp)
    		l = l[:-len(nums)]
    	return res