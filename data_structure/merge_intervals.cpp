#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
	std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
		std::vector<std::vector<int>> out;
		std::sort(intervals.begin(), intervals.end(), [&](std::vector<int> lhs, std::vector<int> rhs) { return lhs[0] < rhs[0]; });
		int size = intervals.size();
		for (int index = 0; index < size; index++) {
			if (out.size() == 0) {
				out.push_back(intervals[index]);
				continue;
			}
			std::vector<int> last = out.back();
			if (last[1] > intervals[index][1]) {
			} else if (last[1] > intervals[index][0]) {
				last[1] = intervals[index][1];
			} else {
				out.push_back(intervals[index]);
			}
		}
		return out;
	}
};

int main() {
	std::vector<std::vector<int>> input = {{15, 18}, {2, 6}, {8, 10}, {1, 3}};
	Solution solu;
	auto out = solu.merge(input);
	for (auto v : out) {
		std::for_each(v.begin(), v.end(), [&](int n) { std::cout << n << ", "; });
		std::cout << std::endl;
	}
 return 0;
}