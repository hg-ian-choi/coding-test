struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// My Solution 1
int sumOfLeftLeaves1(struct TreeNode* root) {
    int sum = 0;

    if (root) {
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            }
        }
        sum += sumOfLeftLeaves1(root->left) + sumOfLeftLeaves1(root->right);
    }

    return sum;
}

// My Solution 2: with flag
int addLeftVal(struct TreeNode* root, int isLeft) {
    int sum = 0;

    if (root) {
        if (!root->left && !root->right && isLeft) {
            sum += root->val;
        } else {
            sum += addLeftVal(root->left, 1) + addLeftVal(root->right, 0);
        }
    }

    return sum;
}

int sumOfLeftLeaves2(struct TreeNode* root) {
    return addLeftVal(root->left, 1) + addLeftVal(root->right, 0);
}
