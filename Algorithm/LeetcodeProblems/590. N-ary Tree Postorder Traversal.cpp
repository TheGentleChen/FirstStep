#include <iostream>
#include <vector>
#include <stack>

using namespace std;                    //树的后序遍历：（1）从第一颗子树到最后一颗子树遍历
//               （2）对子树的遍历也满足上述规则
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution                      //DFS
{
public:
    vector<int> postorder(Node* root)
    {

        if (root != NULL)
        {
            for (auto node:root->children)
                postorder(node);
            ret.push_back(root->val);
        }

        return ret;
    }
private:
    vector<int> ret;
};

class Solution                      //BFS
{
public:
    vector<int> postorder(Node* root)
    {

        vector<int> ret;
        if (root != NULL)
        {
            stack<Node*> s;
            s.push(root);

            while (!s.empty())
            {
                Node* node = s.pop();
                ret.push_back(node->val);
                for (auto a:node->children)
                {
                    s.push(a);
                }
                ret.reverse();
            }
        }

        return ret;
    }
};
