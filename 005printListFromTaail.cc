#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
    
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arr;
        stack<int> s;
        ListNode *p = head;
        while(p!=NULL) {
            s.push(p->val);
            p=p->next;
        }
        while(!s.empty()){
            arr.push_back(s.top());
            s.pop();
        }
        return arr;
    }
};
