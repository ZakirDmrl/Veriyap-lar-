#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5

typedef struct Edge {
    int targetNode;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int numNodes;
    Edge* edges[MAX_NODES];
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; ++i) {
        graph->edges[i] = NULL;
    }
    return graph;
}

void addNode(Graph* graph) {
    if (graph->numNodes < MAX_NODES) {
        graph->numNodes++;
    } else {
        printf("Maksimum düğüm sayısına ulaşıldı!\n");
    }
}

void addDirectedEdge(Graph* graph, int source, int target) {
    if (source >= 0 && source < MAX_NODES && target >= 0 && target < MAX_NODES) {
        Edge* newEdge = (Edge*)malloc(sizeof(Edge));
        newEdge->targetNode = target;
        newEdge->next = graph->edges[source];
        graph->edges[source] = newEdge;
    } else {
        printf("Geçersiz düğüm indeksi!\n");
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; ++i) {
        printf("Düğüm %d:", i);

        Edge* currentEdge = graph->edges[i];
        if (currentEdge == NULL) {
            printf(" Belirtilen düğüme çıkış yok\n");
        } else {
            while (currentEdge != NULL) {
                printf(" -> %d", currentEdge->targetNode);
                currentEdge = currentEdge->next;
            }
            printf("\n");
        }
    }
}

int main() {
    Graph* myGraph = createGraph();

    // Add nodes
    addNode(myGraph);
    addNode(myGraph);
    addNode(myGraph);
    addNode(myGraph);
    addNode(myGraph);

    // Add directed edges in the desired order
    addDirectedEdge(myGraph, 0, 3);
    addDirectedEdge(myGraph, 0, 1);
    addDirectedEdge(myGraph, 1, 4);
    addDirectedEdge(myGraph, 1, 2);
    addDirectedEdge(myGraph, 2, 4);
    addDirectedEdge(myGraph, 2, 3);
    addDirectedEdge(myGraph, 3, 0);
    addDirectedEdge(myGraph, 4, 2);

    // Print the graph
    printGraph(myGraph);

    // Free memory
    for (int i = 0; i < myGraph->numNodes; ++i) {
        Edge* currentEdge = myGraph->edges[i];
        while (currentEdge != NULL) {
            Edge* nextEdge = currentEdge->next;
            free(currentEdge);
            currentEdge = nextEdge;
        }
    }
    free(myGraph);

    return 0;
}
