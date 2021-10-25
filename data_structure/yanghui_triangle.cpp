#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
 public:
	std::vector<int> getRow (int rowIndex) {
		int col_size = rowIndex + 1;
		std::vector<int> out;
		out.reserve(col_size);
		for (int col_index = 0; col_index < col_size; col_index++) {
			out.push_back(getValue(rowIndex, col_index));
		}
		return out;
	}
	int getValue (int row, int col) {
		int out;
		if (col == 0 || row == 0 || col == row) return 1;
		out = getValue(row - 1, col - 1) + getValue(row - 1, col);
		return out;
	}
};

int main() {
	Solution solu;
	std::vector<int> out = solu.getRow(4);
	std::for_each(out.begin(), out.end(), [&](int v) { std::cout << v << ", "; });
	std::cout << std::endl;
	return 0;
}