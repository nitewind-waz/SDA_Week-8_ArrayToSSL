#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "head.h"

void initKota (Kota * K, infotype namaKota, int index) {
    K[index].next = NULL;
    K[index].kt = namaKota;
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
    if (P == NULL) {
        printf("Alokasi Gagal!\nError Code: FAIL_ALLOC\n");
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
	printf("Kode Berhasil dihapus!\n");
}