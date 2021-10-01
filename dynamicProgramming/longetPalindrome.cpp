#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
class Solution {

public:
    string longestPalindrome(string s) {
			auto output = findLongest(s);
			std::cout << "output: " << output << std::endl;
			if (isPalind(s)) {
				return s;
			}
			return s;
    }
private:
	bool isPalind(std::string s);
	std::string longerStr(std::string s1, std::string s2);
	std::string findLongest(std::string s);
	std::map<std::string, std::string> record;
};

bool Solution::isPalind(std::string s) {
	bool result = true;
	int size = s.size();
	for (int index = 0; index < size / 2; index++) {
		if (s[index] != s[size - 1 - index]) {
			return false;
		}
	}
	return result;
}

std::string Solution::longerStr(std::string s1, std::string s2) {
	if (s1.size() > s2.size()) {
		return s1;
	}
	return s2;
}

std::string Solution::findLongest(std::string s) {
	std::string result;
	auto iter = record.find(s);
	if (iter != record.end()) {
		return iter->second;
	}
	if (isPalind(s)) {
		record[s] = s;
		return s;
	}
	int s_size = s.size();
	std::string max_str;
	for (int index = 1; index < s_size; index++) {
		std::string first = s.substr(0, index);
		std::string second = s.substr(index, s_size - index);
		// std::cout << "first: " << first << "   second: " << second << std::endl;
		std::string first_p = findLongest(first);
		std::string second_p = findLongest(second);
		auto longer = longerStr(first_p, second_p);
		max_str = longerStr(longer, max_str);
	}
	
	record[s] = max_str;
	result = max_str;
	return result;
}

int main () {
	std::cout << "longedt Palindrome" << std::endl;
	std:string str = "fiehbbababfdjiexdwwwwwwwwwwwwwwwwwwwww";
	Solution solu;
	auto output = solu.longestPalindrome(str);
	std::cout << output << std::endl;
	return 0;
}