#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;
    struct TreeNode* root = createNode(nums[mid]);
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}
struct TreeNode* convertSortedArrayToBST(int* nums, int numsSize) {
    return sortedArrayToBST(nums, 0, numsSize - 1);
}

)
void printInOrder(struct TreeNode* root) {
    if (root == NULL) return;

    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}

int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode* root = convertSortedArrayToBST(nums, numsSize);

    printf("In-Order Traversal of BST: ");
    printInOrder(root);
    printf("\n");

    return 0;
}
