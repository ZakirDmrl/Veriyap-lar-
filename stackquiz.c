#include <stdio.h>

#include <stdlib.h>

#define SENTINEL -100000000  // işaret değer 


struct dugum{

   int icerik;

   struct dugum *sonraki;

};

struct dugum *dugum_olustur(int icerik){

    struct dugum *d;

    d=(struct dugum*)malloc(sizeof(struct dugum));

    if(d==NULL){

        printf("Yer ayrilamadi... exit...");

        exit(1);

    }

    d->icerik=icerik;

    d->sonraki =NULL;

    return d;

}

void ekle(int icerik, struct dugum **dugum_gostergesi){

    struct dugum *d=dugum_olustur(icerik);

    d->sonraki = *dugum_gostergesi;

    *dugum_gostergesi=d;

}

int cikar(struct dugum **yigin_gostergesi){

  if (*yigin_gostergesi == NULL) {
        printf("Yigin bos, cikarma yapilamaz.\n");
        return SENTINEL;
    }
    int cikarilan = (*yigin_gostergesi)->icerik;
    *yigin_gostergesi = (*yigin_gostergesi)->sonraki;
    // free((*yigin_gostergesi));

    return cikarilan;
}

int yigin_bosmu(struct dugum *yigin_isaretcisi){   
    if(yigin_isaretcisi->sonraki == NULL){
        return 1;
    }
    else{
        return 0;
    }

}

void yazdir1(struct dugum *yigin_gostergesi){
    struct dugum *tmp;
    tmp = yigin_gostergesi;
    while(tmp!=NULL){
        printf("%d  ",tmp->icerik);
        tmp = tmp->sonraki;
    }
    printf("\n");
}

void recursive_yazdir(struct dugum *yigin_gostergesi){
    if(yigin_gostergesi!=NULL){
        printf("%d  ",yigin_gostergesi->icerik);
        recursive_yazdir(yigin_gostergesi->sonraki);
    }
    else
    {
        printf("\n");
    }
}


int main() {

    int a;

    struct dugum *yigin_gostergesi=NULL;

    ekle(100,&yigin_gostergesi);

    ekle(20,&yigin_gostergesi);

    ekle(60,&yigin_gostergesi);

    yazdir1(yigin_gostergesi);

    

    a=cikar(&yigin_gostergesi);

    if(a!=SENTINEL) printf("çıkarılan eleman : %d\n",a);

    printf("yığının son hali : \n");

    recursive_yazdir(yigin_gostergesi);

    int x=yigin_bosmu(yigin_gostergesi);  //  fonk., yığın boş ise 1 değil ise 0 döndürecek

    printf("%d",x);  // yığın boş ise ekrana 1 değil ise 0 yazdırmalı

    return 0;

}