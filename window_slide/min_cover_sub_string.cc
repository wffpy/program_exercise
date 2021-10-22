#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

class Solution {
public: 
	std::string minWindow(std::string s, std::string t) {	
		std::string output;
		int min = s.size();
		
		auto map_str = Str2Dict(t);
		int size = s.size();
		std::cout << "size: " << size << std::endl;
		std::list<char> sub_str;
		for (auto c : s) {
			std::cout << "char : " << c << std::endl;
			if (map_str.find(c) != map_str.end()) {
				map_str[c] = true;
			}

			sub_str.push_back(c);
			std::cout << "char : " << c << std::endl;
			if (judge(map_str)) {
				if (min > sub_str.size()) { 
					min = sub_str.size();
					output.clear();
					std::for_each(sub_str.begin(), sub_str.end(), [&](char ch) { output += ch; });
					std::cout << "temp output: " << output << std::endl;
				}
				map_str[sub_str.front()] = false;
				sub_str.pop_front();
			}

			while (sub_str.size() > 0 && map_str.count(sub_str.front()) == 0) {
				sub_str.pop_front();
			}
			if (sub_str.size() > 1 && sub_str.front() == c) {
				sub_str.pop_front();
				while (sub_str.size() > 0 && map_str.count(sub_str.front()) == 0) {
					sub_str.pop_front();
				}
			}
		}

		return output;
	}

	std::map<char, bool> Str2Dict(std::string t) {
		std::map<char, bool> dict;
		for (char c : t) {
			std::cout << "t: " << c << std::endl;
			dict[c] = false;
		}
		return dict;
	}

	bool judge (std::map<char, bool>& map_str) {
		std::cout << "after judge" << std::endl;
		auto iter = map_str.begin();
		for (; iter != map_str.end(); iter++) {
			if (!(iter->second)) return false;
		}
		std::cout << "after judge" << std::endl;
		return true;
	}
};

int main() {
	std::string s_str = "ADOBECODEBANC";
	std::string t_str = "ABC";
	Solution min_wind_solu;
	std::string out = min_wind_solu.minWindow(s_str, t_str);
	std::cout << "output: " << out << std::endl;
	return 0;
}