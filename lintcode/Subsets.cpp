class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > res;
        vector<int> list;
    	res = subsetsHelper(res, list, nums, 0);
    	return res;
    }

    vector<vector<int> > subsetsHelper(vector<vector<int> > &res, vector<int> &list, vector<int> &nums, int pos) {

        res.push_back(vector<int>(list));

        for (int i = pos; i < nums.size(); ++i) {
            list.push_back(nums[i]);
            subsetsHelper(res, list, nums, i+1);
            list.erase(list.begin() + list.size()-1);
        }
        return res;
    }
};