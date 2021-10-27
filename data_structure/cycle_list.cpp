#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
 public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *out = nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr) {
			fast = updateFast(fast);
			slow = updateSlow(slow);
			if (fast == nullptr) {
				std::cout << "not cycle " << std::endl;
				return out;
			}
			std::cout << "fast: " << fast->val << std::endl;
			std::cout << "slow: " << slow->val << std::endl;

			if (fast == slow) {
				break;
			}
		}

		fast = head;
		int count = 0;
		while(1) {
			fast = updateSlow(fast);
			slow = updateSlow(slow);
			count++;
			if (fast == slow) {
				out = fast;
				break;
			}
		}
		std::cout << "pos: " <<  count << std::endl;
		return out;
	}
 private:
	ListNode* updateSlow(ListNode* node) {
		return node->next;
	}
	ListNode* updateFast(ListNode* node) {
		if (node->next != nullptr) 
			return node->next->next;
		return nullptr;
	}
};

int main () {
	std::vector<int> list = {0, 1, 2, 3, 4, 5};
	int pos = 1;
	ListNode* head = new ListNode(0);
	ListNode* cycle_node = nullptr;
	ListNode* pre_node = head;
	for (int index = 0; index < list.size(); index++) {
		ListNode* node = new ListNode(list[index]);
		pre_node->next = node;
		if (pos == index) {
			cycle_node = node;
		}
		if (index == list.size() - 1) {
			node->next = cycle_node;
		}
		pre_node = node;
	}

	Solution solu;
	solu.detectCycle(head->next);
	return 0;
}