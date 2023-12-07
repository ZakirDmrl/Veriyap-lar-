// Single Linked List olusturma ekleme,silme işlemleri:
#include <stdio.h>
#include <stdlib.h> // import malloc

struct Node{
    int data;
    struct Node* sonraki;
};
struct Node* olustur(int veri){
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    if(!yeni) printf("Islem basarisiz!");
    yeni->data = veri;
    yeni->sonraki = NULL;
    return yeni; 
}
void sil(struct Node** head, int pos) {
    struct Node* prev = NULL;
    struct Node* temp = *head;

    // Liste boş mu diye kontrol ediliyor
    if (!(*head))
        return; // id bulunamadı, çünkü liste boş

    // Düğümü bulmak için liste taranıyor
    while (pos--<=0) {
        prev = temp;
        temp = temp->sonraki;
    }

    // Belirtilen veriye sahip düğüm bulundu mu kontrol ediliyor
    if (prev == NULL && temp == NULL)
        return; // id bulunamadı

    // Düğüm liste başında mı bulunuyor kontrol ediliyor
    else if (prev != NULL && temp == NULL) {
        *head = prev->sonraki;
        free(prev);
    }

    // Düğüm liste sonunda mı bulunuyor kontrol ediliyor
    else if (prev == NULL && temp != NULL) {
        *head = temp->sonraki;
        free(temp);
    }

    // Düğüm liste ortasında mı bulunuyor kontrol ediliyor
    else {
        prev->sonraki = temp->sonraki;
        free(temp);
    }
}


void ekle(struct Node** head, int data) {
    struct Node* new_node = olustur(data);
    int loc;
    if (new_node == NULL) {
        printf("Dugum olusturmada hata oluştu\n");
        return;
    }
    else {
        printf("Kacinci indexe ekleme yapacaksin: ");
        scanf("%d", &loc);

        // Başlangıç düğümünü geçici bir değişkende saklayın
        struct Node* temp_head = *head;

        // Belirtilen indekse kadar liste ilerleyin
        for (int i = 1; i < loc; i++) {
            if (temp_head == NULL) {
                printf("Gecersiz indeks!\n");
                free(new_node);
                return;
            }
            temp_head = temp_head->sonraki;
            
        }

        // Yeni düğümü ekleyin
        
        if(loc == 0){
            new_node->sonraki = temp_head;
            *(head) = new_node;
            return;
        }
        new_node->sonraki = temp_head->sonraki;
        temp_head->sonraki = new_node;

    }

    printf("Islem basariyla gerceklesti.\n");
}

void yazdir(struct Node* head){
    struct Node* temp;
    if(!head){
        printf("\nListede eleman yoktur!\n");
    }
    else{
        temp = head;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp -> sonraki;
        }
        printf("\n");
    }
}
int main(){
    struct Node* head= olustur(1);
    ekle(&head,10);
    yazdir(head);
    ekle(&head,15);
    yazdir(head);
    ekle(&head,20);
    yazdir(head);

    sil(&head,1);
    yazdir(head);

    return 0;
}