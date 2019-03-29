/****************************************
 *
 *
 *牛客网：剑指offer：重建二叉树：通过
 *
 *
 *
 *
 * ***************************************/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
	TreeNode* reConstruct(vector<int> &pre, vector<int> &vin, int l1, int r1, int l2, int r2 ){
		int mid = 0;
		for (int i = l2; i <= r2; i++) {
			if( pre[l1] == vin[i] ) {
				mid = i;
				break;
			}
		}
		TreeNode *t;
		t = new TreeNode(vin[mid]);
		if( mid > l2 )
			t->left = reConstruct(pre, vin, l1+1, l1 + mid -l2, l2, mid - 1 );
		if( mid < r2 )
			t->right = reConstruct(pre, vin, l1 + mid - l2 + 1, r1, mid+1, r2);
		return t;
	}
	public:
		TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin ){
			TreeNode *t;
			t = reConstruct(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
			return t;
		}
};
