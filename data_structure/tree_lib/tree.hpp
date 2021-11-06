#include <iostream>
#include <vector>

template<typename DATATYPE>
struct TreeNode
{
	DATATYPE val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(DATATYPE v) : val(v), left(nullptr), right(nullptr) {}
	TreeNode(DATATYPE v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

template<typename DATATYPE>
TreeNode<DATATYPE>* buildSubTree(std::vector<DATATYPE>& inputs, int index) {
	int node_size = inputs.size();
	int left_index = 2 * index + 1;
	int right_index = 2 * index + 2;
	TreeNode<DATATYPE>* node = nullptr;
	if (index >= node_size) return node;
	node = new TreeNode<DATATYPE>(inputs[index]);
	// add left
	if (left_index < node_size) {
		auto left_node = buildSubTree<DATATYPE>(inputs, left_index);
		node->left = left_node;
	}
	// add right
	if (right_index < node_size) {
		auto right_node = buildSubTree<DATATYPE>(inputs, right_index);
		node->right = right_node;
	}
	return node;
}

template<typename DATATYPE>
TreeNode<DATATYPE>* buildTree(std::vector<DATATYPE> inputs) {
	TreeNode<DATATYPE>* root;
	int node_size = inputs.size();
	root = buildSubTree(inputs, 0);
	return root;
}

template<typename DATATYPE>
void InOrderImpl(TreeNode<DATATYPE>* root, std::list<DATATYPE>& values) {
	if (root == nullptr) return;
	InOrderImpl(root->left, values);
	values.push_back(root->val);
	InOrderImpl(root->right, values);
}

template<typename DATATYPE>
std::vector<DATATYPE> InOrder(TreeNode<DATATYPE>* root) {
	std::list<DATATYPE> values;
	InOrderImpl<DATATYPE>(root, values);
	int node_size = values.size();
	std::vector<DATATYPE> outputs;
	outputs.resize(node_size);
	std::cout << "node_size: " << node_size << std::endl;
	std::copy(values.begin(), values.end(), outputs.begin());
	return outputs;
}
