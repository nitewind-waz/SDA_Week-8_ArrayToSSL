#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int main(){
    // Kamus Data Local
    int selector;
    int locIndex;
    char name[50];
    string locNama;
	Kota K[5];

    // InitKota
    initKota (&K[0], "Bandung", 0);
    initKota (&K[1], "Jakarta", 1);
    initKota (&K[2], "Solo", 2);
    initKota (&K[3], "Yogya", 3);
    initKota (&K[4], "Semarang", 4);

    for (;;){
        system("cls");
        printf("1. Tambah Nama\n2. Hapus Nama\n3. Hapus Kota\n4. Print Semua\nPilih->");
        scanf("%d", &selector);
        switch (selector) {
            case 1:
                printf("Ingin tambah dikota mana? ");
                scanf("%d",&locIndex);

                printf("Masukkan Nama: ");
                scanf("%s",name);

                locNama = (string) malloc(strlen(name) + 1);
                if (locNama == NULL) {
                    printf("Gagal mengalokasikan memori!\n");
                    exit(1);  // Keluar jika alokasi gagal
                }
                strcpy(locNama, name);
                insertWarga (&K[locIndex], locNama, locIndex);
                break;
            case 2:
                printf("Ingin hapus dikota mana? ");
                scanf("%d",&locIndex);
                printf("Masukkan Nama: ");
                scanf("%s",name);

                locNama = (string) malloc(strlen(name) + 1);
                if (locNama == NULL) {
                    printf("Gagal mengalokasikan memori!\n");
                    exit(1);  // Keluar jika alokasi gagal
                }
                strcpy(locNama, name);
                deleteName (&K[locIndex], locNama, locIndex);
                break;
            case 3:
                printf("Ingin hapus dikota mana? ");
                scanf("%d",&locIndex);
                deleteKota (&K[locIndex], locIndex);
                break;
            case 4:
                break;
        }
        if (selector == 4) {
            break;
        }
    }

    return 0;
}