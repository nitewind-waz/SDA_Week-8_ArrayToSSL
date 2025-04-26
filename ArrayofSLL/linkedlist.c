#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "head.h"


void initKota(Kota *K, infotype namaKota) {
    K->kt = (char *)malloc(strlen(namaKota) + 1);
    if (K->kt == NULL) {
        printf("Gagal alokasi nama kota!\n");
        exit(1);
        }
    strcpy(K->kt, namaKota);
    K->next = NULL;
}



bool isEmpty (const Kota  *K, int index) {
    return K[index].next == NULL;
}

void deleteName(Kota *K, infotype namaWarga, int index) {
    if (isEmpty(K, index)) {
        printf("Tidak ada nama yang harus dihapus!\nerror code: MEMORY_UNDERFLOW\n");
        return;
    }

    Warga* temp = K[index].next;
    Warga* prev = NULL;

    // Mencari node dengan nama yang cocok
    while (temp != NULL && strcmp(temp->nm, namaWarga) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Nama tidak ditemukan!\n");
        return;
    }

    if (prev == NULL) {
        K[index].next = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Nama berhasil dihapus!\n");
}


void insertWarga(Kota *K, infotype namaWarga, int index) {

    Warga *P = (Warga *)malloc(sizeof(Warga));
    if (namaWarga == NULL) {
        printf("Nama tidak boleh NULL!\n");
        return;
    }

    P->nm = (char *)malloc(strlen(namaWarga) + 1);

    if (P->nm == NULL) {
        printf("alokasi memori gagal!");
        free(P);
        exit(1);
    }

    strcpy(P->nm, namaWarga); // Salin string
    P->next = NULL;

    if (isEmpty(K, index) || strcmp(namaWarga, K[index].next->nm) < 0) {
        P->next = K[index].next;
        K[index].next = P;
        return;
    }

    Warga *temp = K[index].next;
    while (temp->next != NULL && strcmp(temp->next->nm, namaWarga) < 0) {
        temp = temp->next;
    }

    P->next = temp->next;
    temp->next = P;
}

void deleteKota (Kota * K, int index) {
	Warga* temp = K[index].next;
	while (temp->next != NULL) {
		Warga* hapus = temp;
		temp = temp->next;
		free(hapus);
	}
    K[index].next = NULL;
    free(K[index].kt);
    K[index].kt = NULL;
    printf("Kota dan semua warganya berhasil dihapus!\n");
}

void printAllKota(Kota *K) {
    for (int x = 0; x < 5; x++) {
        if (K[x].kt == NULL || strlen(K[x].kt) == 0) {
            printf("Kota ke-%d: (Belum diinisialisasi)\n", x+1);
            continue;
        }

        printf("Kota: %s\n", K[x].kt);
        Warga* temp = K[x].next;
        int nomor = 1;
        while (temp != NULL) {
            printf("  %d. %s\n", nomor++, temp->nm);
            temp = temp->next;
        }
        printf("\n");
    }
}

