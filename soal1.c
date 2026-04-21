/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Selasa, 21 April 2026
 *   Nama (NIM)          : Darfis Ahmad Dostriano (13224096)
 *   Nama File           : Manuskrip_Retak.c
 *   Deskripsi           : Sebuah naskah kuno hasil digitalisasi ditemukan dalam kondisi rusak. Huruf-hurufnya masih terbaca, 
tetapi beberapa simbol kurung tampak tidak lengkap akibat proses pemindaian yang gagal. Tim 
filologi digital ingin memulihkan naskah itu dengan menghapus sesedikit mungkin simbol kurung 
agar struktur teks kembali valid, tanpa mengubah urutan karakter lainnya.
 * 
 */


 #include <stdio.h>
 #include <string.h>

 int main() {
    char str[256];
    scanf("%s", str);
    int len = strlen(str);

    int karakter[256];
    for (int i = 0; i < len; i++) {
        karakter[i] = 1;
    }

    int BukaKurung = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            BukaKurung++;  
        }  
        else if (str[i] == ')') {
            if (BukaKurung > 0)
            BukaKurung--;
            else {
            karakter[i] = 0;  
            }
        }
    }

    int TutupKurung = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == ')') {
            TutupKurung++;
        }
        else if (str[i] == '(') {
            if (TutupKurung > 0) {
                TutupKurung--;
            }
            else {
                karakter[i] = 0;  
            }
        } 
    }

    char hasil[256];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (karakter[i]) {
            hasil[j++] = str[i];
        }
    }
    hasil[j] = '\0';
    printf("%s\n", hasil);
    return 0;
 }
