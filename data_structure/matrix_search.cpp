#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
 public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		int lower_i, lower_j = 0;
		int upper_i = matrix.size() - 1;
		int upper_j = matrix[0].size() - 1;
		return search(matrix, target, 0, upper_i, lower_j, upper_j);
		// while (lower_i != upper_i || lower_j != upper_j) {
		// 	int i = (lower_i + upper_i) / 2; 
		// 	int j = (lower_j + upper_j) / 2;
		// 	if (matrix[i][j] == target) {
		// 		return true;
		// 	} else if  (matrix[i][j] < target) {
		// 		lower_i = i;
		// 		lower_j = j;
		// 	} else {
		// 		upper_i = i;
		// 		upper_j = j;
		// 	}
		// }
	}

	bool search(std::vector<std::vector<int>>& matrix, int target, int row_start, int row_end, int col_start, int col_end) {
		std::cout << "start : [" << row_start  << ", " << col_start << "]";
		std::cout << "  end : [" << row_end  << ", " << col_end << "]" << std::endl;

		if (row_start == row_end && col_start == col_end) {
			if (matrix[row_start][col_start] == target) {
				return true;
			} else {
				return false;
			}
		}
		int lower_i = row_start;
		int lower_j = col_start;
		int upper_i = row_end;
		int upper_j = col_end;
		
		int i;
		int j;
		// std::cout << "coordinate: " << i << ", " << j << "]" << std::endl;
		while (1) { 
			if (i == (lower_i + upper_i) / 2 && j == (lower_j + upper_j) / 2) {
				break;
			}
			j = (lower_j + upper_j) / 2;
			i = (lower_i + upper_i) / 2;
			std::cout << "update: " << i << ", " << j << "]" << std::endl;
			if (matrix[i][j] == target)  {
				std::cout << "find" << std::endl;
				return true;
			} else if (matrix[i][j] < target) {
				lower_i = i;
				lower_j = j;
			} else if (matrix[i][j] > target) {
				upper_i = i;
				upper_j = j;
			}
		}

		std::cout << "coordinate: " << i << ", " << j << "]" << std::endl;
		if (j + 1 <= col_end) {
			bool right_up = search(matrix, target, row_start, i, j + 1, col_end);
			if (right_up) return true;
		}
		if (i + 1 <= row_end) {
			bool left_down = search(matrix, target, i + 1, row_end, 0, j-1);
			if (left_down) return true;
		}
		return false;
	}

};

int main () {
	std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

	Solution solu;
	solu.searchMatrix(matrix, 23);
	return 0;
}
