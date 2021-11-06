#include <vector>
#include <iostream>
#include <map>
#include <stack>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

class Solution {
 public:
	std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
		std::vector<std::vector<int>> out;
		std::stack<TreeNode*> path_stack;
		std::map<TreeNode*, int> sum_map;
		path_stack.push(root);
		while (!path_stack.empty()) {
			TreeNode* node = path_stack.top();
			std::vector<TreeNode*> childs = traverse(node);
			auto iter = childs.begin();
			for (; iter != childs.end(); iter++) {
				auto iter2 = sum_map.find(*iter);
				if (iter2 != sum_map.end()) continue;
				path_stack.push(*iter);
				// int sum = sum_map[node] + iter->val;
				sum_map[*iter] = sum_map[node] + iter->val;
				break;
			}
			if (childs.empty() && sum_map[node] == targetSum)  {
				:
			}

			if (iter == childs.end()) {
				path_stack.pop();
			}
		}
		return out;
	}

 private:
	std::vector<TreeNode*> traverse(TreeNode* root) {
		std::vector<TreeNode*> vec;
		vec.reserve(2);
		if (root->left != nullptr)
			vec.push_back(root->left);
		if (root->right != nullptr)
			vec.push_back(root->right);
		return vec;
	}

};