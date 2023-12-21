class Solution {
public:

    int rootcheck(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left = rootcheck(root->left);
        int right = rootcheck(root->right);

        return max(left, right) + 1;

    }

    bool isBalanced(TreeNode* root) {

        if (root == nullptr)
            return true;

        int left = rootcheck(root->left);
        int right = rootcheck(root->right);

        if (left - right == 1 || left - right == -1 || left - right == 0)
            return true;
        else
            return false;

    }
};