#include <iostream>
#include <algorithm>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
 public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* out;
		int count = 0;
		ListNode* curr_node = nullptr;
		ListNode* pre_cluster_end = nullptr;
		ListNode* curr_cluster_head = nullptr;
		ListNode* curr_cluster_end = nullptr;
		out = head;
		curr_node = head;
		while (curr_node != nullptr) {
			// record current cluster end
			if (count % k == 0) {
				curr_cluster_end = curr_node;
			} 
			if (count == k - 1) {
				out = curr_node;
			}
			ListNode* next_node = curr_node->next;
			// record current cluster head and reverse the current cluster
			if (count % k == k - 1) {
				curr_cluster_head = curr_node;
				// reverse K node
				ListNode* node = curr_cluster_end;
				ListNode* pre = nullptr;
				while (1) {
					ListNode* temp = node->next;
					node->next = pre;
					pre = node;
					if (node == curr_cluster_head) break;
					node = temp;
				}
				// update the next ptr of pre cluster end node
				if (pre_cluster_end != nullptr) {
					std::cout << "pre_cluster_end: " << pre_cluster_end->val << std::endl;
					pre_cluster_end->next = curr_cluster_head;
				} 
				pre_cluster_end = curr_cluster_end;
			}
			// update current node, and count
			curr_node = next_node;
			// if the remainder node number less than k, not change the sequence
			if (((count % k) < k - 1) && curr_node == nullptr) {
				if (pre_cluster_end != nullptr)
					pre_cluster_end->next = curr_cluster_end;
			}
			count++;
		}
		return out;
	}
};

int main() {
	std::vector<int> list = {0, 1, 2, 3, 4, 5};
	ListNode* head = new ListNode(0);
	ListNode* pre_node = head;
	for (int index = 0; index < list.size(); index++) {
		ListNode* node = new ListNode(list[index]);
		pre_node->next = node;
		pre_node = node;
	}

	Solution solu;
	ListNode* out = solu.reverseKGroup(head->next, 3);
	while (out != nullptr) {
		std::cout << out->val << ", ";
		out = out->next;
	}
	std::cout << std::endl;
}