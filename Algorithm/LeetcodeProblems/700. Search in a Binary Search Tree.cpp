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
class Solution {                                        //�������ĺ������������stack��BFS
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

class Solution {                                        //��������������������ö��ֲ��Һ�BFT���ص㣺
                                                        //�����������Ӣ�Binary Search Tree����Ҳ��Ϊ�����������������������ordered binary tree��
                                                        //�������������sorted binary tree������ָһ�ÿ������߾����������ʵĶ�������
                                                        //��1��������ڵ�����������գ��������������нڵ��ֵ��С�����ĸ��ڵ��ֵ��
                                                        //��2��������ڵ�����������գ��������������нڵ��ֵ���������ĸ��ڵ��ֵ��
                                                        //��3������ڵ����������Ҳ�ֱ�Ϊ�����������
                                                        //��4��û�м�ֵ��ȵĽڵ㡣
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
