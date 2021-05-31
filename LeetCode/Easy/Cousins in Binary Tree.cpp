/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        queue<pair<TreeNode*,TreeNode*>> q;
        TreeNode* parentX = NULL;
        TreeNode* parentY = NULL;
        TreeNode* temp = new TreeNode(-1);
        q.push(make_pair(root,temp));
        while(!q.empty())
        {
            int nodeCount = q.size();
            while(nodeCount > 0)
            {
                pair<TreeNode*,TreeNode*> p = q.front();
                q.pop();
                if(p.first->val==x)
                {
                    parentX = p.second;
                }
                if(p.first->val==y)
                {
                    parentY = p.second;
                }
                if(p.first->left!=NULL)
                {
                    q.push(make_pair(p.first->left,p.first));
                }
                if(p.first->right!=NULL)
                {
                    q.push(make_pair(p.first->right,p.first));
                }
                nodeCount--;
                if(parentX && parentY)
                    break;
            }
            if(parentX!=NULL && parentY!=NULL)
                return parentX!=parentY;
            if((parentX && !parentY) || (!parentX && parentY))
                return false;
        }
        return true;
    }
};
