#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> out;
		if (nums.size() == 0) {
			return out;
		}
		// 1.sort
		std::sort(nums.begin(), nums.end());
		// std::for_each(nums.begin(), nums.end(), [&](int v) { std::cout << v << ", "; });
		std::cout << std::endl;
		// 2. choose
		int size = nums.size();
		int first = 0;
		int second = size - 1;
		int third = -1;
		for (first = 0; nums[first] <= 0 && first < size -1; first++) {
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			second = size - 1;
			for (second; nums[second] >= 0 && second > 0; second--) {
				if (second < size -1 && nums[second] == nums[second + 1]) {
					continue;
				}
				if (first == second) break;
				// std::cout << "first: " << first << "  second: " << second << std::endl;
				// std::cout << "first: " << nums[first] << "  second: " << nums[second] << std::endl;
				if (nums[first] + nums[second] >= 0) {
					third = first + 1;
					if (third > size -1 || third == first || third == second) break;
					while (nums[third] <= 0) {
						if (nums[first] + nums[second] + nums[third] == 0) {
							// std::cout << "success !!!!!!!!" << std::endl;
							out.push_back({nums[first], nums[third], nums[second]});
							break;
						}
						third++;
					}
				} else {
					third = second - 1;
					if (third < 0 || third == first || third == second) break;
					while(nums[third] > 0) {
						if (nums[first] + nums[second] + nums[third] == 0) {
							// std::cout << "success !!!!!!!!" << std::endl;
							out.push_back({nums[first], nums[third], nums[second]});
							break;
						}
						third--;
					}
				}
			}
		}

		return out;
	}
};

int main () {
	// std::vector<int> input = {-1,0,1,2,-1,-4};
	std::vector<int> input = {0, 0, 0};
	Solution solu;
	auto out = solu.threeSum(input);
	for (auto v : out) {
		for (auto n : v) {
			std::cout << n << ", ";
		}
		std::cout << endl;
	}
}