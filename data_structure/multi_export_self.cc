#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
 public:
	std::vector<int> productExportSelf(std::vector<int>& nums) {
		int size = nums.size();
		std::vector<int> out(size, 1);

		int pre_product = 1;
		int suf_product = 1;
		for (int index = 0; index < size; index++) {
			pre_product = nums[index] * pre_product; 
			out[index + 1] *= pre_product;
			suf_product = nums[size - 1 - index] * suf_product;
			out[size - 1 - index - 1] *= suf_product;
		}
		return out;
	}	
};

int main () {
	std::vector<int> input = {1, 2, 3, 4};
	Solution solu;
	std::vector<int> out = solu.productExportSelf(input);
	std::for_each(out.begin(), out.end(), [&](int v) { std::cout << v << ", ";});
	std::cout << std::endl;
	return 0;
}