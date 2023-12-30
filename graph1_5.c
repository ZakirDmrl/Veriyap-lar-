#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10
int ID = 0;
int komsular[MAX_SIZE][MAX_SIZE] = {0};
typedef struct node{
char data[15];
int id;

}Node;

typedef struct graph{
Node* nodelar[MAX_SIZE];
}Graph;


Node* createNode(char data[]){                   
    Node *newNode = malloc(sizeof(newNode));
    for (int i = 0; i <= strlen(data); i++){
        newNode->data[i] = data[i];
    }
    newNode->id = ID;
    ID++;

    return newNode;
}

void komsuEkle(int id1,int id2){
    komsular[id1][id2] = 1;
    komsular[id2][id1] = 1;

}
void matrisYazdir(){
    int i,j=0;
    for(i=0;i<MAX_SIZE;i++){
        for(j = 0;j<MAX_SIZE;j++){
            printf("%d ",komsular[i][j]);
        }
        printf("\n");
    }
}
void komsuYazdir(int id,Graph *myGraph){
    for(int i = 0; i < MAX_SIZE; i++){
        if(komsular[i][id] == 1){
            printf("%s ",myGraph->nodelar[i]->data);
        }
    }
}

void nodeEkle(char data[],Graph *myGraph){
 myGraph->nodelar[ID] = createNode(data);
}

int main(){
    Graph mygraph;
   nodeEkle("adana",&mygraph);
   nodeEkle("istanbul",&mygraph);
   nodeEkle("kayseri",&mygraph);
   nodeEkle("siirt",&mygraph);

    komsuEkle(0,1);
    komsuEkle(2,1);
    matrisYazdir();
    komsuYazdir(1,&mygraph);






    return 0;
}