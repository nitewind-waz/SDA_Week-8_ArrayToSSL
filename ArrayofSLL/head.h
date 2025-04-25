#ifndef HEAD_H
#define HEAD_H

#include <stdbool.h>

typedef char* string;

typedef string infotype;

typedef struct Kota {
    infotype kt;
    struct Warga* next;
} Kota;

typedef struct Warga {
    infotype nm;
    struct Warga* next;
} Warga;

// Komponen dasar linked list

void initKota (Kota * K, infotype namaKota, int index);

bool isEmpty (const Kota  *K, int index);

void deleteName (Kota * K, infotype namaWarga, int index);

void insertWarga (Kota * K, infotype namaWarga, int index);

void deleteKota (Kota * K, int index);

#endif

