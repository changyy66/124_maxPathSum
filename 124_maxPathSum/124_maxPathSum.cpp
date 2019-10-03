// 124_maxPathSum.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

1
/ \
2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

-10
/ \
9  20
	/  \
	15   7

输出: 42

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxNum = 0x80000000;
	int maxSum(TreeNode* root)
	{
		if (root->left == NULL&&root->right == NULL)
		{
			if (root->val > maxNum)maxNum = root->val;
			return root->val;
		}
		if (root->left == NULL)
		{
			int n = maxSum(root->right);
			if (n < 0)
			{
				n = root->val;
			}
			else
			{
				n += root->val;
			}
			if (n > maxNum)
			{
				maxNum = n;
			}
			return n;
		}
		if (root->right == NULL)
		{
			int n = maxSum(root->left);
			if (n < 0)
			{
				n = root->val;
			}
			else
			{
				n += root->val;
			}
			if (n > maxNum)
			{
				maxNum = n;
			}
			return n;
		}
		int m = maxSum(root->left);
		int n = maxSum(root->right);

		int k = root->val;
		if (m > 0)k += m;
		if (n > 0)k += n;
		if (k > maxNum)
		{
			maxNum = k;
		}
		int kk = m > n ? m : n;
		if (kk > 0)
			return root->val + kk;
		return root->val;
	}

	int maxPathSum(TreeNode* root) {
		int n = maxSum(root);
		return n > maxNum ? n : maxNum;
	}
};

int main()
{
    return 0;
}

