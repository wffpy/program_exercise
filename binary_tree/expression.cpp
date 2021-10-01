#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

struct Node{
	std::string data;
	struct Node* left;
	struct Node* right;
};

class Tree {
 public: 
	Tree () : root(new Node) {}
	void build(std::string s);
	void buildTree(std::string s, Node* p);
	std::string print();
	int compute();
 private:
	int findLowestExp(std::string s);
	std::string removePat(std::string s);
	std::string printTree(Node* root);
	int computeNode(Node* node);

	std::unique_ptr<Node> root;
};

int Tree::computeNode(Node* node) {
	int result = 0;
	auto left_node = node->left;
	auto right_node = node->right;
	if ((left_node == nullptr) && (right_node == nullptr)) {
		result = std::stoi(node->data);
	} else if ((left_node != nullptr) && (right_node != nullptr)) {
		switch(node->data[0]) {
			case '+': {
				result = computeNode(left_node) + computeNode(right_node);
				break;
			}
			case '*' : {
				result = computeNode(left_node) * computeNode(right_node);
				break;
			}
			default:
				std::cout << "error!!!!!!!!!!!!!!!!!!!" << std::endl;
				break;
		}
	}
	return result;
}

int Tree::compute() {
	// suffix order traverse
	return computeNode(root.get());
}

void Tree::build(std::string s) {
	buildTree(s, root.get());
}

std::string Tree::print() {
	auto result = printTree(root.get());
	return result;
}

std::string Tree::printTree(Node* root) {
	// middle order with recursion
	std::string result = "";
	Node* left = root->left;
	Node* right = root->right;
	if (left != NULL) {
		std:string left_exp = printTree(left);
		result += left_exp;
	}
	result += root->data;
	if (right != NULL) {
		std::string right_exp = printTree(right);
		result += right_exp;
	}
	return result;
}

std::string Tree::removePat(std::string s) {
	if (s[0] == '(' && s[s.size() -1] == ')') {
		s = s.substr(1, s.size() -2);
	}
	return s;
}

int Tree::findLowestExp(std::string s) {
	int pos = -1;
	int lowest = 100;
	for (int index = 0; index < s.size();) {
		int prior = -1;
		switch (s[index]) 
		{
			case '+': {
				prior = 0;
				break;
			}
			case '*' : {
				prior = 1;
				break;
			}
			case '(' : {
				prior = 100;
				while(s[index] != ')') {
					index++;
				}
				break;
			}
		default:
			index++;
			continue;
			break;
		}
		if (prior < lowest) {
			pos = index;
		}
		index++;
	}
	return pos;
}

void Tree::buildTree(std::string s, Node* p) {
	int pos = findLowestExp(s);
	std::cout << "input_str: " << s << std::endl;
	std::cout << "pos: " << pos << std::endl;
	if (pos != -1) {
		p->data = s[pos];
		Node* left = new Node();
		Node* right = new Node();
		p->left = left;
		p->right = right;
		std::string left_exp = removePat(s.substr(0, pos));
		std::string right_exp = removePat(s.substr(pos + 1));
		std::cout << "left_exp: " << left_exp << "   right_exp: " << right_exp << std::endl;
		buildTree(left_exp, left);
		buildTree(right_exp, right);
	} else {
		p->data = s;
		p->left = NULL;
		p->right = NULL;
	}
}

int main() {
	std::cout << "Expression Binary Tree";
	Tree tree;
	Node root;
	// tree.buildTree("(e+f)*a*b+c", &root);
	tree.build("(1+2)*3*4+5");
	// std::cout << "middle tree: " << tree.printTree(&root) << std::endl;
	std::cout << "middle tree: " << tree.print() << std::endl;
	std:cout << "compute: " << tree.compute() << std::endl; 

	return 0;
}