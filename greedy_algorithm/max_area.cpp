#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int size = height.size();
		int max_area = 0;
		int left_index = 0;
		int right_index = size - 1;
		int min_height = std::min(height[left_index], height[right_index]);
		while (left_index != right_index) {
			int area = (right_index - left_index) * min_height;
			max_area = area > max_area ? area : max_area;
			if (height[left_index] > height[right_index]) { 
				right_index--;
			} else {
				left_index++;
			}
			min_height = std::min(height[left_index], height[right_index]);
		}
		return max_area;
	}
};

int main() {
	std::cout << "max area test" << std::endl;
	std::vector<int> height = {1,8,6,2,5,4,8,3,7};
	// std::vector<int> height = {4,3,2,1,4};
	Solution solu;
	auto result = solu.maxArea(height);
	std::cout << "result: " << result << std::endl;
	return 0;
}