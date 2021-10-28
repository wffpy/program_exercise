#include <vector>
#include <algorithm>
#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

class Solution {
 public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int> inorder) {
		TreeNode* root = new TreeNode(preorder[0]);
		if (preorder.size() == 1 && inorder.size() == 1) {
			return root;
		} 
		auto iter = std::find(inorder.begin(), inorder.end(), preorder[0]);
    int dis = std::distance(inorder.begin(), iter);
		std::cout << "dis: " << dis << std::endl;
		std::vector<int> pre_order_left(preorder.begin() + 1, preorder.begin() + dis + 1);
		std::vector<int> in_order_left(inorder.begin(), inorder.begin() + dis);

		std::vector<int> pre_order_right(preorder.begin() + dis + 1, preorder.end());
		std::vector<int> in_order_right(inorder.begin() + dis + 1, inorder.end());

		TreeNode* left = buildTree(pre_order_left, in_order_left);
		TreeNode* right = buildTree(pre_order_right, in_order_right);
		root->left = left;
		root->right = right;
		std::cout << printTree(root) << std::endl;
		return root;
	}
 private:
	std::string printTree(TreeNode* root) {
		std::string out;
		if (root != nullptr) {
			out += printTree(root->left);
			out += std::to_string(root->val) + " ";
			out += printTree(root->right);
		}
		return out;
	}
};

int main() {
	std::vector<int> preorder = {3, 9, 20, 15, 7};
	std::vector<int> inorder = {9, 3, 15, 20, 7};
	Solution solu;
	solu.buildTree(preorder, inorder);
	return 0;
}