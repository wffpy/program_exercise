#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
	bool increasingTriplet(std::vector<int>& nums) {
		int size = nums.size();
		int min = __INT_MAX__;
		int mid = __INT_MAX__;
		for (int index = 0; index < size; index++) {
			if (nums[index] > mid) return true;
			if (nums[index] < min) min = nums[index];
			else mid = nums[index];
		}
		return false;
	}
};
int main () {
	std::cout << "test inscreasing triple" << std:: endl;
	std::vector<int> input = {5, 4, 3, 2, 1, 0};
	Solution s;
	s.increasingTriplet(input);

	return 0;
}