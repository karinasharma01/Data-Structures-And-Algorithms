//Method-1 : Using BFS
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
    int findDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lDepth=findDepth(root->left);
        int rDepth=findDepth(root->right);
        return max(lDepth,rDepth)+1;
    }
    int findBottomLeftValue(TreeNode* root) {
        int depth = findDepth(root);
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));
        while(!q.empty())
        {
            int nodeCount = q.size();
            while(nodeCount)
            {
                pair<TreeNode*,int> p = q.front();
                q.pop();
                if(p.second==depth)
                    return p.first->val;
                if(p.first->left!=NULL)
                    q.push(make_pair(p.first->left,p.second+1));
                if(p.first->right!=NULL)
                    q.push(make_pair(p.first->right,p.second+1));
                nodeCount--;
            }
        }
        
        return 0;
    }
};

//Method-2:Recursion
class Solution {
public:
    void findBottomLeftValueUtil(TreeNode* root,int& maxDepth,int depth,int& ans)
    {
        if(root==NULL)
            return;
        findBottomLeftValueUtil(root->left,maxDepth,depth+1,ans);
        findBottomLeftValueUtil(root->right,maxDepth,depth+1,ans);
        if(depth > maxDepth)
        {
            maxDepth = depth;
            ans = root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int ans = root->val;
        findBottomLeftValueUtil(root,maxDepth,0,ans);
        return ans;
    }
};
