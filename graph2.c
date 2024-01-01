/* 
Bu script graphdaki vertexler arasındaki en kısa mesafeyi bulmaya yarar.
Kullanılan algoritma: Dijkstra algoritması
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4 // Vertex sayisi

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // en kısa mesageyi tutar
    int visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0; // başlangıç noktasına olan uzaklık başlangıçta 0

   for (int count = 0; count < V - 1; count++)
    {
        int minDist = INT_MAX, minIndex; //  Henüz işlenmemiş vertexi içinde en kısa mesafeli vertexi buluyoruz
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == 0 && dist[v] <= minDist)
            {
                minDist = dist[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1; // Seçilen vertexi işaretliyoruz

        // Seçilen vertexin komşularını güncelliyoruz
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INT_MAX && dist[minIndex] + graph[minIndex][v] < dist[v])
            {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
        if (count == V - 2){
        printf("Vertex\tEn Kisa Mesafe\n");
        for (int i = 0; i < V; i++)
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main(){
int graph[V][V] = {
    {0, 5, 1, 0},
    {5, 0, 0, 2},
    {1, 0, 0, 3},
    {0, 2, 3, 0}
};
int source = 0;
dijkstra(graph, source);
    return 0;
}