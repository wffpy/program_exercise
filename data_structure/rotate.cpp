#include <iostream>
#include <algorithm>
#include <vector>


class Solution {
 public:
	void rotate(std::vector<std::vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i <= row/2; i++) {
			for (int j = 0; j < col/2; j++) {
				exchange(matrix[i][j], matrix[j][row - 1 - i], matrix[row - 1 - i][row - 1 - j], matrix[row - 1 -j][i]);
			}
		}
	}

	void exchange(int& a, int& b, int& c, int& d) {
		a = a + b + c + d;
		b = a  - b - c - d;
		c = a - b - c - d;
		d = a - b - c -d;
		a = a - b  - c - d;
	}
};

int main () {
	std::vector<std::vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Solution solu;
	solu.rotate(input);
	std::for_each(input.begin(), input.end(), [&](std::vector<int> v) { std::for_each(v.begin(), v.end(), [&](int n) { std::cout << n << ", "; } ); });
	return 0;
}
