#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define notVisited 1
#define waiting 2
#define visited 3

struct node
{
    char label[15];
    int counter;
    int state;
    struct node *komsular[100];
    struct node *next;
};
struct node* start = NULL;
struct node* last = NULL;
struct node* temp;
struct node* important;

void harftenDugum(char harf[15]){
    temp = start;
    while (strcmp(temp->label,harf) != 0)
    {
        temp = temp->next;
    }
    important = temp;
    
}
void komsuEkle(char src[15],char dest[15]){
    struct node* source;
    harftenDugum(src);
    source = important;
    struct node* destination;
    harftenDugum(dest);
    destination = important;
    source->komsular[source->counter] = destination;
    source->counter++;
    destination->komsular[destination->counter] = source;
    destination->counter++;
}
void sehirEkle(char sehir[15]){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->label,sehir);
    newNode->counter = 0;
    newNode->state = notVisited;
    newNode->next = NULL;
    if(start == NULL){
        start = newNode;
        last = newNode;
    }
    else{
        last->next = newNode;
        last = newNode;
    }
}
void sehirYazdir(){
    temp = start;
    while (temp->next != NULL){
        printf("%s\n", temp->label);
        temp = temp->next;
    }
    printf("%s\n", temp->label);
}
void komsuYazdir(char harf[15]){
    harftenDugum(harf);
    for( int i = 0; i < important->counter; i++){
        printf("Komsu: %s ",important->komsular[i]->label);
    }
}



void display(){
    int secim;
    int komsuSayisi;
    char sehirHarf[15];
    char sehirHarf1[15];
    while(1){
        printf("\n 1-) Sehir Ekle ...");
        printf("\n 2-) Sehir Yazdir ...");
        printf("\n 3-) Komsu Ekle ...");
        printf("\n 4-) Komsu Yazdir ...");
        printf("\n 5-) Cikis?");
        printf("\n -> ");
        scanf("%d",&secim);
        switch(secim){
            case 1: 
                printf("\n Sehirinizin Girin...");
                scanf("%s",sehirHarf);
                sehirEkle(sehirHarf);
                break;
            case 2:
                sehirYazdir();
                break;
            case 3:
                printf("Hangi sehre komsu eklemek istiyorsunuz ?");
                scanf("%s",sehirHarf);
                printf("\n Kac komsusu olacak:");
                scanf("%d",&komsuSayisi);
                for( int i = 0 ; i < komsuSayisi; i++){
                    printf("Lutfen %d. komsuyu girin: ",i+1);
                    scanf("%s",sehirHarf1);
                    komsuEkle(sehirHarf,sehirHarf1);
                }
                break;
            case 4:
                    printf("Hangi sehrin komsularini görmek istiyorsun: ");
                    scanf("%s",sehirHarf);
                    komsuYazdir(sehirHarf);
                    break;
            case 5:
                exit(0);
            default :
                printf("Hatali Secim !!! \n");
                break;
                        
        }
    }
}

int main(){
    display();
    return 0;
}