#include <iostream>
#include <vector>
#include <stack>

using namespace std;                    //���ĺ����������1���ӵ�һ�����������һ����������
//               ��2���������ı���Ҳ������������
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
