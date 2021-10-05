#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
	vector<int> maxNum(vector<int>& nums1, vector<int>& nums2, int k) {
		std::vector<int> result;
		int size_1 = nums1.size();
		int size_2 = nums2.size();
		int index_1 = 0;
		int index_2 = 0;
		for (int i = 0; i < k; i++) {
			int need = k - i;
			int max_nums1 = nums1[index_1];
			int max_nums2 = nums2[index_2];
			int max_value = -1;
			int temp_index_1 = -1;
			int temp_index_2 = -1;
			int slide_szie_1 = size_2 > need ? size_1 : size_1 + size_2 - need;
			if (index_1 < nums1.size()) {
				if (slide_szie_1 == 0) {
					if (nums1[index_1] > max_value) {
						max_value = nums1[index_1];
						temp_index_1 = index_1;
					}
				} else {
					for (int j = index_1; j < index_1 + slide_szie_1; j++) {
						if (nums1[j] > max_value) {
							max_value = nums1[j]; 
							temp_index_1 = j;
						}
					}
				}
			}

			int slide_szie_2 = size_1 > need ? size_2 : size_1 + size_2 - need;
			if (index_2 < nums2.size()) {
				if (slide_szie_2 == 0) {
					if (nums2[index_2] > max_value) {
						max_value = nums2[index_2];
						temp_index_2 = index_2;
					}
				} else {
					for (int l = index_2; l < index_2 + slide_szie_2; l++) {
						if (nums2[l] > max_value) {
							max_value = nums2[l];
							temp_index_2 = l;
						}
					}
				}
			}
			// std::cout << "max_value: " << max_value << std::endl;
			result.push_back(max_value);
			if (temp_index_2 > -1 ) {
				index_2 = temp_index_2 + 1;
				size_2 = nums2.size() - index_2;
			} else if (temp_index_1 > -1) {
				index_1 = temp_index_1 + 1;
				size_1 = nums1.size() - index_1;
			} else {
				// std::cout << "error: " << std::endl;
			}
			// std::cout << "index1: " << index_1 << std::endl;
			// std::cout << "index2: " << index_2 << std::endl;
			// std::cout << "nums1 size: " << size_1 << std::endl;
			// std::cout << "nums2 size: " << size_2 << std::endl;
		}
		return result;
	}

};


int main() {
	std::cout << "max_num test" << std::endl;
	// std::vector<int> nums1 = {3, 4, 6, 5};
	std::vector<int> nums1 = {6, 7};
	// std::vector<int> nums2 = {9, 1, 2, 5, 8, 3};
	std::vector<int> nums2 = {6, 0, 4};
	// int k = 5;
	int k = 5;
	Solution s;
	s.maxNum(nums1, nums2, 5);

	return 0;
}