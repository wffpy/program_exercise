#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution {
 public:
	int majorityElement (std::vector<int>& nums) {
		int out = 0;
		int major_base = nums.size() / 2;
		std::sort(nums.begin(), nums.end());
		std::map<int, int> num_map;
		int count = 1;
		if (nums.size() == 1) return nums[0];
		for (int index = 0; index < nums.size() - 1; index++) {
			if (nums[index] == nums[index + 1]) {
				count += 1;
			} else {
				count = 1;
			}
			if (count > major_base) {
				return nums[index];
			}
		}
		return out;
	}
};

int main () {
	std::vector<int> input = {3, 3, 1, 2, 3};
	Solution solu;
	int out = solu.majorityElement(input);
	std::cout << "major test: " << out << std:: endl;
	return 0;
}