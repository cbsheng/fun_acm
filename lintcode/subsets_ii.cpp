class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        vector<int> nums(S);
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        vector<int> list;
        subsetsHelper(res, list, nums, 0);
        return res;
    }
    
    void subsetsHelper(vector<vector<int> > &res, vector<int> &list, vector<int> &nums, int pos) {

        res.push_back(vector<int>(list));

        for (int i = pos; i < nums.size(); ++i) {
            if (i != pos && nums[i] == nums[i - 1]) {
                continue;
            }

            list.push_back(nums[i]);
            subsetsHelper(res, list, nums, i + 1);
            list.erase(list.begin() + list.size() - 1);
        }
    }
};

