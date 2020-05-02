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
class Solution {                //DFS
public:
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;
        if (root->children.empty())
            return 1;
        int childMaxDepth = INT_MIN;
        for (auto node:root->children)
        {
            int childDepth = maxDepth(node);
            if (childMaxDepth < childDepth)
            {
                childMaxDepth = childDepth;
            }
        }
        return childMaxDepth + 1;
    }
};

class Solution {                //BFS
public:
    int maxDepth(Node* root) {

        int depth = 0;
        queue<pair<Node*, int>> q;
        if (root != NULL)
        {
            q.push(make_pair(root, 1));
        }
        while (!q.empty())
        {
            pair<Node*, int> p = q.front();
            q.pop();
            root = p.first;
            int current_depth = p.second;
            depth = max(depth, current_depth);
            for (auto c:root->children)
            {
                q.push(make_pair(c, current_depth + 1));
            }
        }
        return depth;
    }
