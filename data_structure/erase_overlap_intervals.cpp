#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
	int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
		int num = 0;
		std::vector<int> overlaps;
		overlaps.reserve(intervals.size());
		std::sort(intervals.begin(), intervals.end(),
			[&](std::vector<int>& lhs, std::vector<int>& rhs) {
				if (lhs[0] == rhs[0]) {
					return lhs[1] > rhs[1];
				} else {
					return lhs[0] < rhs[0];
				}
				});
		std::for_each(intervals.begin(), intervals.end(), 
		[&](std::vector<int> v) {
			std::for_each(v.begin(), v.end(), [&](int n) { std::cout << n << ", "; }); 
			});
		std::cout << std::endl;
		int interval_size = intervals.size();
		int count = 0;
		for (int index = 0; index < interval_size - 1; index++) {
			if (intervals[index][1] > intervals[index + 1][0]) {
				num++;
			}
			// for (int i = index + 1; i < interval_size; i++) {
			// 	if (intervals[index][1] > intervals[i][0]) {
			// 		++count;
			// 		continue;
			// 	}
			// 	break;
			// }
			// overlaps.push_back(count);
		}

		// std::for_each(overlaps.begin(), overlaps.end(), [](int v) { std::cout << v << ", "; });
		// std::cout << std::endl;
		
		return num;
	}
};

int main () {
	std::vector<std::vector<int>> input = {{3, 4}, {2, 3}, {1, 2}, {1, 3}, {2, 4}};
	Solution solu;
	int rm_num = solu.eraseOverlapIntervals(input);
	std::cout << "remove num: " << rm_num << std::endl;
	return 0;
}