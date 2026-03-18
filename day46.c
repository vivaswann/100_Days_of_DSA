/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* levelOrder(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    int* result = (int*)malloc(10000 * sizeof(int));
    int size = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = queue[front++];
        result[size++] = node->val;

        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }

    *returnSize = size;
    return result;
}
