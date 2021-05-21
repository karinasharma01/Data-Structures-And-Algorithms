#include<queue>
#include<vector>
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
vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL)
        {
            return {};
        }
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    vector<vector<int>> ans;
    vector<int> smallAns;
    while(!pendingNodes.empty())
    {
        int nodeCount=pendingNodes.size();
        while(nodeCount > 0)
        {
            TreeNode* currentNode=pendingNodes.front();
            smallAns.push_back(currentNode->val);
            pendingNodes.pop();
            if(currentNode->left!=NULL)
            {
                pendingNodes.push(currentNode->left);
            }
            if(currentNode->right!=NULL)
            {
                pendingNodes.push(currentNode->right);
            }
            nodeCount--;
        }
        ans.push_back(smallAns);
        smallAns.clear();
    }
    return ans;
}
};
