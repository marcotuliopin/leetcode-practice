struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 *TIME COMPLEXITY: O(n)
 *SPACE COMPLEXITY: O(1)
 *THOUGHT PROCESS: recursively invert each node individually.
 */
TreeNode* solution(TreeNode* root) {

    if (root == nullptr)
        return root;
    // b <-- a --> c
    TreeNode *tmp = root->left;
    root->left = root->right;
    // b a -->> c
    root->right = tmp;
    // c <-- a --> b
    solution(root->right);
    solution(root->left);

    return root;
}
