#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
 public:
	int singleNumber(std::vector<int>& nums) {
		int out = 0;
		std::map<int, int> non_repeat; 
		for (int num : nums) {
			if (non_repeat.count(num) == 0) {
				non_repeat[num] = 1;
			} else {
				non_repeat[num] += 1;
			}
		}
		for (auto iter : non_repeat) {
			if (iter.second == 1) {
				out = iter.first;
			}
		}
		return out;
	}
};

int main () {
	std::vector<int> input = {2, 2, 1, 3, 4, 5, 3, 4, 5};
	Solution solu;
	int out = solu.singleNumber(input);
	std::cout << "output: " << out << std::endl;
	return 0;
}