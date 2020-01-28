#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	helper(root, 0, res);
	return res;
}
void helper(TreeNode* root, int level, vector<int>& res){
	if (!root) return;
	if (res.size() == level) res.push_back(root->val);
	helper(root->right, level + 1, res);
	helper(root->left, level + 1, res);
}

int main(){

	return 0;
}