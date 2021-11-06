#include <iostream>
#include <vector>
// TODO(eric): need to re-implement 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
 public:
	ListNode* getIntersectiionNode(ListNode* headA, ListNode* headB) {
		ListNode* out;
		ListNode* r_a = revertList(headA);
		ListNode* r_b = revertList(headB);
		if (r_a->val != r_b->val) { return out; }
		while (r_a->next != nullptr && r_b->next != nullptr) {
			if (r_a->next->val == r_b->next->val) {
				r_a = r_a->next;
				r_b = r_b->next;
			} else {
				return r_a;
			}
		}
		out = r_a;
		return out; 
	}

 private:
	ListNode* revertList(ListNode* head) {
		ListNode* last = nullptr;
		ListNode* node = head;
		while (node != nullptr) {
		  ListNode* temp = node->next;
			node->next = last;
			last = node;
			node = temp;
		}
		return last;
	}
};
