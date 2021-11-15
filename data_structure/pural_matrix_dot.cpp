#include <iostream>
#include <vector>

std::vector<std::vector<int>> HerTrans(std::vector<std::vector<int>>& input) {
	std::vector<std::vector<int>> result;
	int row_size = input.size();
	int col_size = input[0].size();
	for (int i = 0;  i < row_size; i++) {
		std::vector<int> vec(col_size);
		result.push_back(vec);
	}
	for (int i = 0; i < row_size; i++) {
		int shibu = true;
		for (int j = 0; j < col_size; j++) {
			int new_row = j / 2;
			int new_col = i * 2;
			if (!shibu)  {
				new_col += 1;
				result[new_row][new_col] = -input[i][j];
			} else {
				result[new_row][new_col] = input[i][j];
			}

			shibu = !shibu;
		}
	}
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			std::cout << result[i][j] << ", " ;
		}
		std::cout << std::endl;
	}

	return result;
}

std::vector<std::vector<int>> dot(std::vector<std::vector<int>>& input) {
	std::vector<std::vector<int>> result;
	std::vector<std::vector<int>> her;
	her = HerTrans(input);
	int input_row = input.size();
	int input_col = input[0].size();
	int out_row = input.size();
	int out_col = input.size();
	for (int i = 0; i < out_row; i++) {
		std::vector<int> vec(2 * out_row);
		result.push_back(vec);
	}

	for (int i = 0; i < out_row; i++) {
		for (int k = 0; k < out_row; k++) {
			int shi = 0;
			int xu = 0;
				for (int n = 0; n < input_col / 2; n++) {
					shi += input[i][2 * n] * her[n][2 * k] - input[i][2 * n + 1]*her[n][2 *k + 1];
					xu += input[i][2 * n] * her[n][2 * k + 1] + input[i][2 * n + 1]*her[n][2 * k];
				}
			result[i][k * 2] = shi; 
			result[i][k * 2 + 1] = xu;
		}
	}

	for (int i = 0; i < out_row; i++) {
		for (int j = 0; j < out_row; j++) {
			std::cout << result[i][j] << ", " ;
		}
		std::cout << std::endl;
	}
	return result;
}

int main() {
	std::cout << "test" << std::endl;
	std::vector<std::vector<int>> input = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}};
	dot(input);
	return 0;
}