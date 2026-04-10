//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int v;
    int w;
} Edge;

typedef struct {
    Edge edges[MAX];
    int size;
} AdjList;

typedef struct {
    int v;
    int dist;
} Node;

typedef struct {
    Node heap[MAX];
    int size;
} MinHeap;

AdjList graph[MAX];
int dist[MAX];
int visited[MAX];

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i) {
    while (i && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        swap(&h->heap[(i - 1) / 2], &h->heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap *h, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if (r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap *h, int v, int dist) {
    h->heap[h->size].v = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

Node pop(MinHeap *h) {
    Node root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapifyDown(h, 0);
    return root;
}

void addEdge(int u, int v, int w) {
    graph[u].edges[graph[u].size].v = v;
    graph[u].edges[graph[u].size].w = w;
    graph[u].size++;
}

void dijkstra(int n, int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (h.size) {
        Node cur = pop(&h);
        int u = cur.v;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int i = 0; i < graph[u].size; i++) {
            int v = graph[u].edges[i].v;
            int w = graph[u].edges[i].w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        graph[i].size = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}
