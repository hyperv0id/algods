#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/submissions/434275937/
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root == NULL){return root;}
        int r_path = max_path(root, limit);
        if(r_path < limit){
            return NULL;
        }
        return root;
    }
    int max_path(TreeNode* node, int limit, int pre_sum = 0){
        if(node == NULL){return INT_MIN;}
        int ans = pre_sum + node->val;
        cout << ans << endl;
        if(!node->left && !node->right){
            return ans;
        }
        int left = max_path(node->left, limit, ans);
        if(left < limit){
            node->left = NULL;
        }
        int right = max_path(node->right, limit, ans);
        if(right < limit){
            node->right = NULL;
        }
        return max(left, right);
    }
};
int main (int argc, char *argv[]) {
    
    return 0;
}
