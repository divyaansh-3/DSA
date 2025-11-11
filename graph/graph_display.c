#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void displayGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node *temp = graph->adjLists[src], *prev = NULL;
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL)
            graph->adjLists[src] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    temp = graph->adjLists[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL)
            graph->adjLists[dest] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
}

struct Graph* insertNode(struct Graph* graph) {
    int newVertex = graph->numVertices;
    graph->numVertices++;
    graph->adjLists = realloc(graph->adjLists, graph->numVertices * sizeof(struct Node*));
    graph->adjLists[newVertex] = NULL;
    printf("Node %d inserted successfully.\n", newVertex);
    return graph;
}

struct Graph* deleteNode(struct Graph* graph, int vertex) {
    if (vertex >= graph->numVertices) {
        printf("Invalid vertex.\n");
        return graph;
    }
    for (int i = 0; i < graph->numVertices; i++)
        deleteEdge(graph, i, vertex);

    free(graph->adjLists[vertex]);
    for (int i = vertex; i < graph->numVertices - 1; i++)
        graph->adjLists[i] = graph->adjLists[i + 1];
    graph->numVertices--;
    graph->adjLists = realloc(graph->adjLists, graph->numVertices * sizeof(struct Node*));
    printf("Node %d deleted successfully.\n", vertex);
    return graph;
}

int main() {
    int vertices, choice, src, dest, node;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    while (1) {
        printf("\n--- Graph Menu ---\n");
        printf("1. Add Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Insert Node\n");
        printf("4. Delete Node\n");
        printf("5. Display Graph\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter source and destination to delete edge: ");
                scanf("%d %d", &src, &dest);
                deleteEdge(graph, src, dest);
                break;
            case 3:
                graph = insertNode(graph);
                break;
            case 4:
                printf("Enter node to delete: ");
                scanf("%d", &node);
                graph = deleteNode(graph, node);
                break;
            case 5:
                displayGraph(graph);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
