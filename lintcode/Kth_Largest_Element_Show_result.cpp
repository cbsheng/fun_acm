class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        if (k > nums.size() || nums.size() == 0)
            return 0;
            
        multiset<int> topk;
        multiset<int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            if (topk.size() < k) {
                topk.insert(nums[i]);
            }
            else {
                iter = topk.begin();
                if (*iter < nums[i]) {
                    topk.erase(iter);
                    topk.insert(nums[i]);
                }
            }
        }
        return *topk.begin();
    }
};
