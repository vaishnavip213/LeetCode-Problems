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
    pair<int,int> traverse(TreeNode* root , int& cnt){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> leftdata = traverse(root->left,cnt);
        pair<int,int> rightdata = traverse(root->right,cnt);
        int sum = leftdata.first + rightdata.first + root->val;
        int nodes = leftdata.second + rightdata.second + 1;
        int avg = sum/nodes;
        if(avg==root->val){
            cnt++;
        }
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        traverse(root,count);
        return count;
    }
};