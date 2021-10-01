#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
			compute(s);
			return 0;
    }
	// std::string clearSpace(std::string s);
private:
	int compute(string s);
	std::string clearSpace(std::string s);
	int char2Int(char c);
	int getValue(std::string s, int pos, bool dir);
	std::string updateComputeStr(std::string s, int pos, int val);
};

int Solution::getValue(std::string s, int pos, bool dir) {
	int result = 0;
	int start = pos;
	if (dir) {
		auto pre_pos = s.find_last_of("+", pos);
		if (pre_pos == std::string::npos) {
			pre_pos = s.find_last_of("*", pos);
		}
		if (pre_pos != std::string::npos) {
			auto sub_str = s.substr(pre_pos+1, pos-pre_pos-1);
			result = std::stoi(sub_str);
		} else {
			auto sub_str = s.substr(0, pos);
			result = std::stoi(sub_str);
		}
	} else {
		auto suf_pos = s.find_first_of("+", pos);
		if (suf_pos == std::string::npos) {
			suf_pos = s.find_first_of("*", pos);
		}
		if (suf_pos != std::string::npos) {
			auto sub_str = s.substr(pos+1, suf_pos);
			result = std::stoi(sub_str);
		} else {
			auto sub_str = s.substr(pos+1);
			result = std::stoi(sub_str);
		}
	}
	return result;
}

std::string Solution::updateComputeStr(std::string s, int pos, int val) {
	std::string result;
	auto pre_pos = s.find_last_of("+", pos);
	if (pre_pos == std::string::npos) {
		pre_pos = s.find_last_of("*", pos);
		if (pre_pos == std::string::npos) {
			pre_pos = 0;
		}
	}
	auto suf_pos = s.find_first_of("+", pos);
	if (suf_pos == std::string::npos) {
		suf_pos = s.find_first_of("*", pos);
	}
	s.replace(pre_pos+1, suf_pos-1, std::to_string(val));
	result = s;
	return result;
}

int Solution::compute(std::string s) {
	int result = 0;
	auto str = clearSpace(s);
	std:cout << "clearspace str: " << str << std::endl;
	std::size_t found = str.find("*");
	if (found != std::string::npos) {
		int lhs = getValue(str, found, true);
		int rhs = getValue(str, found, false);
		std::cout << "lhs: " << lhs << "    rhs: " << rhs << std::endl;
		int temp_result = lhs * rhs;
		auto update_str = updateComputeStr(s, found, temp_result);
		compute(update_str);
	} else {
		std::size_t found = str.find("+");
		if (found != std::string::npos) {
			int lhs = getValue(str, found, true);
			int rhs = getValue(str, found, false);
			std::cout << "lhs: " << lhs << "    rhs: " << rhs << std::endl;
			int temp_result = lhs * rhs;
			auto update_str = updateComputeStr(s, found, temp_result);
			compute(update_str);
		} else {
			result = std::stoi(s);
		}
	}
	return result;
}

std::string Solution::clearSpace(std::string s) {
	int index = 0;
	if (!s.empty()) {
		while ((index = s.find(" ", index)) != std::string::npos)
		{
			s.erase(index, 1);
		}
	}
	return s;
}

int Solution::char2Int(char c) {
	return c - '0';
}

int main() {
	std::cout << "score of math" << std::endl;
	std::string computation = "3 + 4 * 5 + 2 * 3";
	Solution solu;
	// std::cout << solu.clearSpace(computation) << std::endl;
	std::vector<int> results = {0, 1, 2, 3};
	solu.scoreOfStudents(computation, results);
}