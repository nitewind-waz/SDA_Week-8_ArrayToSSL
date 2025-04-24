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

void deleteName (Kota *K, infotype namaWarga, int index) {
    if (isEmpty(K,index)) {
        printf("Tidak ada nama yang harus dihapus!!\n");
        return;
    }
    else {
        Warga* temp = K[index].next;
        Warga* tmp2 = K[index].next;
        infotype nama;
        nama = namaWarga;
        while (temp->nm != nama){
            temp = temp->next;
            tmp2 = temp;
        }
        tmp2->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
}

void insertWarga (Kota *K, infotype namaWarga, int index) {
    Warga* P = (Warga*) malloc(sizeof(Warga));
    if (P == NULL) {
        printf("Memory could not be allocated");
        exit(0);
    } else {
        P->nm = namaWarga;
        if (isEmpty(K,index)) {
            K[index].next = P;
        }
        else {
            Warga* temp = K[index].next;
            Warga* tmp2 = K[index].next;
            while (temp->next != NULL) {
                tmp2 = temp;
                temp = temp->next;
                if (tmp2->nm[0]<P->nm[0] && temp->nm[0]>P->nm[0]) {
                    P->next = tmp2->next;
                    tmp2->next = P;
                }
            }
        }
    }
}