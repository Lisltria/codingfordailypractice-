#include <iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {

	ListNode* reList(ListNode *lastNode,ListNode *node) {
		if(node->next == NULL){
			node->next = lastNode;
			return node;
		}
		else {
			struct ListNode *tmp;
			tmp = node->next;
			node->next = lastNode;
			return reList(node,tmp);
		}
	}
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead != NULL) {
			return reList(NULL,pHead);
		}
		else return NULL;
    }
};
