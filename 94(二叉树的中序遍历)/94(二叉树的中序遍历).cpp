/*
题目描述：
给定一个二叉树，返回它的中序 遍历。

示例:
输入: [1,null,2,3]
1
\
2
/
3

输出: [1,3,2]
*/
#include"../utils/utils/BTree.h"
#include<vector>
#include<stack>

/*解法1：递归解法*/
class Solution1 {
public:
	vector<int> res;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root != nullptr) {
			if (root->left != nullptr) {
				inorderTraversal(root->left);
			}
			res.push_back(root->val);
			if (root->right != nullptr) {
				inorderTraversal(root->right);
			}
		}
		return res;
	}
};

/*解法2：迭代*/
class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) {
			return res;
		}
		stack<TreeNode*> st;
		while (!st.empty() || root != nullptr) { //root始终指向栈顶元素
			while (root != nullptr) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			res.push_back(root->val);
			root = root->right;
		}
		return res;
	}
};