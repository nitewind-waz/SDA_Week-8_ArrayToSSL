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
    initKota (&K[0], "Bandung");
    initKota (&K[1], "Jakarta");
    initKota (&K[2], "Solo");
    initKota (&K[3], "Yogya");
    initKota (&K[4], "Semarang");

    for (;;){
        system("cls");
        printf("1. Tambah Nama\n2. Hapus Nama\n3. Hapus Kota\n4. Print Semua\n5. Exit\nPilih->");
        scanf("%d", &selector);
        switch (selector) {
            case 1:
                printf("Ingin tambah dikota mana?\n0.Bandung\n1.Jakarta\n2.Solo\n3.Yogya\n4.Semarang\n...");
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
                free(locNama);
                break;
            case 2:
                printf("Ingin hapus dikota mana?\n0.Bandung\n1.Jakarta\n2.Solo\n3.Yogya\n4.Semarang\n...");
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
                printf("Ingin hapus dikota mana?\n0.Bandung\n1.Jakarta\n2.Solo\n3.Yogya\n4.Semarang\n...");
                scanf("%d",&locIndex);
                deleteKota (&K[locIndex], locIndex);
                printf("Tekan ENTER!\n");
                getchar(); getchar();
                break;
            case 4:
                printAllKota(K);
                printf("Tekan ENTER!\n");
                getchar(); getchar();
                break;
            case 5:
                break;
        }
        if (selector == 5) {
            break;
        }
    }

    return 0;
}