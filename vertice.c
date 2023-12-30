#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int id;
    char* data;
}Vertice;

int * AddEdge(int adjMatrix[][5],Vertice id1,Vertice id2)
{
    adjMatrix [id1.id][id2.id] = adjMatrix[id2.id][id1.id] = 1;
    return adjMatrix;
}

int * RemoveEdge(int adjMatrix[][5],Vertice id1,Vertice id2)
{
  adjMatrix [id1.id][id2.id] = adjMatrix[id2.id][id1.id] = 0;  
  return adjMatrix;
}

int main(){
    int adjMatrix[5][5] = {0};
    Vertice v1,v2;
    v1.id = 1;
    v1.data = "Zakir";
    v2.id = 2;
    v2.data = "Emir";
    AddEdge(adjMatrix,v1,v2);
    int i,j;
    for(i=0 ; i<5; i++){
        for(j=0; j<5; j++){
            printf("%3d",adjMatrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}