#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{

    return 0;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {  //C++递归实现，广度优先搜索思想

        //处理每两个相应的节点时有三种情况

        if (t1 == NULL) //如果t1为NULL，把以t2为根节点的树连接到t1的位置
            return t2;
        if (t2 == NULL) //同上
            return t1;

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
}

TreeNode mergeTrees(TreeNode t1, TreeNode t2) {     //JAVA实现,广度优先搜索（BFS）思想
        if (t1 == null)
            return t2;
        stack<TreeNode[]> s; stack = new Stack < > ();
        stack.push(new TreeNode[] {t1, t2});
        while (!stack.isEmpty()) {
            TreeNode[] t = stack.pop();
            if (t[0] == null || t[1] == null) {
                continue;
            }
            t[0].val += t[1].val;
            if (t[0].left == null) {
                t[0].left = t[1].left;
            } else {
                stack.push(new TreeNode[] {t[0].left, t[1].left});
            }
            if (t[0].right == null) {
                t[0].right = t[1].right;
            } else {
                stack.push(new TreeNode[] {t[0].right, t[1].right});
            }
        }
        return t1;
    }
