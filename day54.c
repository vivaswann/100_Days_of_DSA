/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return NULL;
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;
    
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        if (curr) {
            curr->left = newNode(arr[i++]);
            if (i < n) queue[tail++] = curr->left;
            if (i < n) {
                curr->right = newNode(arr[i++]);
                queue[tail++] = curr->right;
            }
        }
    }
    free(arr);
    free(queue);
    return root;
}

void printZigzag(struct Node* root) {
    if (!root) return;

    struct Node* queue[1000];
    int head = 0, tail = 0;
    queue[tail++] = root;
    bool leftToRight = true;

    while (head < tail) {
        int levelSize = tail - head;
        int* currentLevel = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct Node* node = queue[head++];
            int index = leftToRight ? i : (levelSize - 1 - i);
            currentLevel[index] = node->data;

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }

        for (int i = 0; i < levelSize; i++) {
            printf("%d ", currentLevel[i]);
        }
        
        leftToRight = !leftToRight;
        free(currentLevel);
    }
}

int main() {
    struct Node* root = buildTree();
    printZigzag(root);
    return 0;
}
