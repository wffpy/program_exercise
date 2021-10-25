#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
	std::vector<std::vector<int>> generateMatrix(int n) {
		std::vector<std::vector<int>> out;
		for (int i = 0; i < n; i++) {
			std::vector<int> v(n, 0);
			out.push_back(v);
		}
		int dir_num = 0;
		int dir = 0;
			int i = 0;
			int j = 0;
		std::vector<int> dy = {1, 0, -1, 0};
		std::vector<int> dx = {0, 1, 0, -1};
		for (int num = 1; num <= n * n; num++) {
			out[i][j]  = num;
			if ((i + dx[dir_num]) < 0 || (i + dx[dir_num]) > n - 1 || j + dy[dir_num] < 0 || j + dy[dir_num] > n - 1 || out[i + dx[dir_num]][j + dy[dir_num]] != 0) {
				dir_num += 1;
				dir_num = dir_num % 4;
			} 
			i += dx[dir_num];
			j += dy[dir_num];
			if (out[i][j] != 0) {
				break;
			}
		}
		return out;
	}
};

int main () {
	int n = 4;
	Solution solu;
	auto out = solu.generateMatrix(n);
	std::for_each(out.begin(), out.end(), [&](std::vector<int> v) { std::for_each(v.begin(), v.end(), [&](int n) { std::cout << n << ", "; } ); });
	// std::cou 
	return 0;
}