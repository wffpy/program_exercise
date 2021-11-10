#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include "tree_lib/tree.hpp"

typedef TreeNode<int> Node;

class Solution {
 public:
	std::vector<std::vector<int>> zigzagLevelOrder(Node* root) {
		std::vector<std::vector<int>> out;
		std::list<std::list<Node*>> level_list;
		std::list<Node*> root_level;
		root_level.push_back(root);
		level_list.push_back(root_level);
		bool to_right = true;
		while(!level_list.empty()) {
			std::cout << "level: " << out.size() << std::endl;
			std::vector<int> out_data;
			std::list<Node*> cur_list = level_list.front();
			std::list<Node*> next_level;
			while (!cur_list.empty()) {
				Node* node = cur_list.front();
				if (node->left != nullptr) next_level.push_back(node->left);
				if (node->right != nullptr) next_level.push_back(node->right);
				out_data.push_back(node->val);
				cur_list.pop_front();
			}
			if (!next_level.empty()) level_list.push_back(next_level);
			if (!to_right) std::reverse(out_data.begin(), out_data.end());
			to_right = !to_right;
			level_list.pop_front();
			out.push_back(out_data);
		}
		return out;
	}
};

int main() {
	Solution solu;
	std::vector<int> inputs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
	Node* root = buildTree<int>(inputs);
	std::vector<int> outputs = TraverseTree<int>(root, ORDERTYPE::INORDER);
	std::for_each(outputs.begin(), outputs.end(), [&](int val) { std::cout << val << ", "; });
	std::cout << std::endl;
	auto out = solu.zigzagLevelOrder(root);
	for (auto vec : out) {
		for (auto value : vec) {
			std::cout << value << ", ";
		}
	}
	std::cout << std::endl;
	return 0;
}
