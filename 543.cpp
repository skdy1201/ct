#include <algorithm>
using std::max;

#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




//class Solution {
//public:
//
//    int diameterOfBinaryTree(TreeNode* root) {
//        
//        if (root->left == nullptr && root->right == nullptr)
//            return 0;
//
//        int leftcount = diameterOfBinaryTree(root->left);
//        int rightcount = diameterOfBinaryTree(root->right);
//
//        return max(leftcount, rightcount) + 1;
//
//
//    }
//};



class Solution {
public:

    int maxDia = 0;


    int heightModified(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int leftHt = heightModified(root->left);

        int rightHt = heightModified(root->right);

        maxDia = max(maxDia, leftHt + rightHt + 1);

        return max(leftHt, rightHt) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root)
    {

        heightModified(root);

        return maxDia - 1;
    }



};