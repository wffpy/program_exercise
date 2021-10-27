#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
 public:
	bool wordPattern(std::string pattern, std::string s) {
		bool out = true;
		int size = pattern.length();
		std::vector<std::string> words;
		size_t pos;
		std::string delimter = " ";
		while((pos = s.find(delimter)) != std::string::npos) {
			std::cout << "pos " << pos << std::endl;
			words.push_back(s.substr(0, pos));
			s.erase(0, pos + delimter.length());
		}
		words.push_back(s);
		if (words.size() != size) {
			std::for_each(words.begin(), words.end(), [&](std::string w) { std::cout << w << std::endl; });
			std::cout << "false: " << "size no match " << words.size() << " vs " << size << std::endl;
			return false;
		}
		
		std::map<char, std::string> ch_map;
		for (int index = 0; index < size; index++) {
			char c = pattern[index];
			auto iter = ch_map.find(c);
			if (iter == ch_map.end()) {
				ch_map[c] = words[index];
			} else {
				if (ch_map[c] != words[index]) {
					std::cout << "false" << std::endl;
					return false;
				}
			}
		}
		return out;
	}
};

int main () {
	std::string pattern = "abba";
	std::string s = "dog cat cat dog";
	Solution solu;
	solu.wordPattern(pattern, s);
}