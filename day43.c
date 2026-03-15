/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL)
        return -1;

    struct Node* temp = front;
    int val = temp->data;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(x);
        }
        else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (arr[0] == -1) return 0;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    inorder(root);

    return 0;
}
