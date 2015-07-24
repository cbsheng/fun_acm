#include <vector>
#include <iostream>

using namespace std;

void permuteHelper(vector<vector<int> > &res, vector<int> &list, vector<int> nums) {
    
    if (nums.size() == 0) {
        res.push_back(list);
    }
    else {
        for (int i = 0; i < nums.size(); ++i) {
            list.push_back(nums[i]);
            vector<int> tmp(nums);
            tmp.erase(tmp.begin() + i);
            permuteHelper(res, list, tmp);
			cout << "$ " << nums.size() << " " << (list.end() - nums.size()-1) - list.begin() <<endl;
			vector<int> ttmp(list.begin(), list.end()-nums.size()-1);
			/*
			cout << "##"  << endl;
			for(auto k : ttmp) {
				cout << k << " ";
			}
			cout << endl;
			*/
			list = ttmp;
			//for (int j = 0; j < nums.size(); ++j) list.erase(list.begin() + list.size() - 1);
            //list.erase(list.end() - nums.size(), list.end());
			/*for (auto i : list) {
				cout << i << " ";
			}
			cout << endl;
			*/
        }
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    vector<int> list;
    permuteHelper(res, list, nums);
    return res;
}

int main()
{
	vector<int> n;
	n.push_back(1);
	n.push_back(2);
	n.push_back(3);
	vector<vector<int> > res = permute(n);
	for (auto i : res) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}