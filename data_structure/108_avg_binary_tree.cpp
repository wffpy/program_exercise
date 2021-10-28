#include <vector>
#include <iostream>
#include <stdlib.h>

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
	TreeNode* sortedArrayToBST(std::vector<int>& nums) {
		TreeNode* head = nullptr;
		int size = nums.size();
		for (int index = 0; index < size; index++) {
				TreeNode* new_node = new TreeNode(nums[index]);
				head = Insert(head, new_node);
		}
		std::cout << printTree(head) << std::endl;
		return head;
	}
 private:
	TreeNode* Insert(TreeNode* head, TreeNode* leaf) {
		if (head == nullptr || leaf == nullptr) return leaf;
		// insert node
		TreeNode* node = head;
		int val = leaf->val;
		while (node != nullptr) {
			if (node->val > val) {
				if (node->left == nullptr) {
					node->left = leaf;
					break;
				} else {
					node = node->left;
				}
			} else {
				if (node->right == nullptr) {
					node->right = leaf;
					break;
				} else {
					node = node->right;
				}
			}
		}

		TreeNode* root = head;
		int left_depth = depth(root->left) ;
		int right_depth = depth(root->right);
		std::cout << "left_depth: " << left_depth << std::endl;
		std::cout << "right_depth: " << right_depth << std::endl;
		if (abs(left_depth - right_depth) > 1) {
			if (left_depth > right_depth) {
				root = rightRotate(root);
			} else {
				root = leftRotate(root);
			}
		}

		if(isBalanced(root)) {
			std::cout << "this tree is balanced!!!!!!" << std::endl;
		} else {
			std::cout << "this tree is not balanced!!!!!!" << std::endl;

		}
		
		return root;
	}

	TreeNode* leftRotate(TreeNode* head) {
		if (head == nullptr) return head;
		TreeNode* root = nullptr;
		root = head->right;
		head->right = root->left;
		root->left = head;
		return root;
	}

	TreeNode* rightRotate(TreeNode* head) {
		if (head == nullptr) return head;
		TreeNode* root = nullptr;
		root = head->left;
		head->left = root->right;
		root->right = head;
		return root;
	}

	int depth(TreeNode* root) {
		if (root == nullptr) return 0;
		int left_depth = depth(root->left);
		int right_depth = depth(root->right);
		return std::max(left_depth, right_depth) + 1;
	}

	bool isBalanced(TreeNode* root) {
		int left_depth = depth(root->left) ;
		int right_depth = depth(root->right);
		if (abs(left_depth - right_depth) > 1) {
			return false;
		}
		return true;
	}

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
	std::vector<int> input = {-10, -3, 0, 5, 9};
	Solution solu;
	TreeNode* node = solu.sortedArrayToBST(input);
	std::cout << "root value: " << node->val << std::endl;
	return 0;
}