#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
	int subarraySum(std::vector<int>& nums, int k) {
		int size = nums.size();
		int head = 0;
		int tail = 0;
		int sum = 0;
		int count = 0;
		while (tail < size && head <= tail) {
			if (head == tail) {
				sum = nums[tail];
				if (tail < size) {
					tail++;
				}
			} else if (head < tail) {
				if (sum == k) {
					++count;
				} else if (sum < k) {
					++tail;
					sum += nums[tail];
					if (tail == size - 1) 
						break;
				} else if (sum > k) {
					sum = sum - nums[head];
					++head;
				}
			}
		}
	}
};

int main() {
	std::vector<int> input = {1, 2, 3}; 
	Solution solu;
	int num = solu.subarraySum(input, 3);
	std::cout << "num: " << num << std::endl;
	return 0;
}