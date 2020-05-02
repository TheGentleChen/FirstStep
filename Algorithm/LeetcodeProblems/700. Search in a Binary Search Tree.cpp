#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {                                        //二叉树的后序遍历，运用stack和BFS
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root)
        {
            stack<TreeNode*> s;
            s.push(root);
            while (!s.empty())
            {
                TreeNode* node = s.top();
                if (node->val == val)
                    return node;
                s.pop();
                if (node->left != NULL)
                    s.push(node->left);
                if (node->right != NULL)
                    s.push(node->right);
            }
        }

        return NULL;
    }
};

class Solution {                                        //二叉树的先序遍历，运用二分查找和BFT的特点：
                                                        //二叉查找树（英语：Binary Search Tree），也称为二叉搜索树、有序二叉树（ordered binary tree）
                                                        //或排序二叉树（sorted binary tree），是指一棵空树或者具有下列性质的二叉树：
                                                        //（1）若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
                                                        //（2）若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
                                                        //（3）任意节点的左、右子树也分别为二叉查找树；
                                                        //（4）没有键值相等的节点。
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root)
        {
            if (root->val == val)
                return root;
            else if (root->val > val)
                return searchBST(root->left, val);
            else
                return searchBST(root->right, val);
        }

        return NULL;
    }
};
