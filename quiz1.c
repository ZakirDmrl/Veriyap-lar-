#include <stdio.h>
#include <stdlib.h>

struct hucre {
    int icerik;
    struct hucre* sonraki;
};

struct hucre* hucre_olustur(int icerik) {
    struct hucre* yeni_hucre = (struct hucre*)malloc(sizeof(struct hucre));
    if (yeni_hucre == NULL) {
        fprintf(stderr, "Hata: Bellek tahsisi basarisiz.\n");
        exit(EXIT_FAILURE);
    }
    yeni_hucre->icerik = icerik;
    yeni_hucre->sonraki = NULL;
    return yeni_hucre;
}

void liste_basina_ekle(int icerik, struct hucre** liste_basi) {
    struct hucre* yeni = hucre_olustur(icerik);
    yeni->sonraki = *liste_basi;
    *liste_basi = yeni;
}

void liste_sonuna_ekle(int icerik, struct hucre** liste_basi) {
    struct hucre* yeni = hucre_olustur(icerik);
    if (*liste_basi == NULL) {
        *liste_basi = yeni;
    } else {
        struct hucre* iter = *liste_basi;
        while (iter->sonraki != NULL) {
            iter = iter->sonraki;
        }
        iter->sonraki = yeni;
    }
}

void liste_yaz_recursive(struct hucre* liste_basi) {
    if (liste_basi == NULL) {
        return;
    }
    printf(" %3d ", liste_basi->icerik);
    liste_yaz_recursive(liste_basi->sonraki);
}

int main() {
    struct hucre* list = NULL;

    liste_sonuna_ekle(10, &list);
    liste_sonuna_ekle(11, &list);
    liste_basina_ekle(5, &list);
    liste_sonuna_ekle(8, &list);
    liste_basina_ekle(4, &list);

    liste_yaz_recursive(list);
    printf("\n");

    return 0;
}