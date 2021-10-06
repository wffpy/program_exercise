#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
 public:
	int wiggleMaxLength(std::vector<int>& nums) {
		if (std::count(nums.begin(), nums.end(), nums[0]) == nums.size()) {
			return nums.size();
		}
		bool pre = nums[1] > nums[0] ? false : true;
		std::vector<int> result;
		result.reserve(nums.size());
		for (int index = 1; index < nums.size(); index++) {
			int value = 0;
			if ((nums[index] > nums[index - 1]) != pre) {
				result.push_back(nums[index - 1]);
				pre = nums[index] > nums[index - 1];
			} else {
			}
			if (index == (nums.size() - 1) && result.size() == 1) {
				result.pop_back();
			}
			if (index == (nums.size() - 1) && result.size() > 0) {
				result.push_back(nums[index]);
			}
		}
		for (auto num : result) {
			std:cout << num << ", ";
		}
		std::cout << std::endl;
		return result.size();
	}
};

int main  () {
	std::cout << "wiggleMaxLength test" << std::endl;
	// std::vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
	std::vector<int> nums = {1,1,1,1};
	Solution s;
	int max_length = s.wiggleMaxLength(nums);
	std::cout << "max_length: " << max_length << std::endl;
	return 0;
}