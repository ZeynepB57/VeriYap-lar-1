/**
* @file Arraylist.cpp
* @description Arraylist olusturmak icin metotlara govde tanimlar.
* @course 1/A
* @assignment 1
* @date 5.08.2022
* @author Zeynep Bezirci
*/

#include "Arraylist.hpp"
#include <iostream>

Arraylist::Arraylist() {

    uzunluk = 0;
    kapasite = 0;
    dizi = NULL;



}

void Arraylist::alanBuyut(int yeniKapasite) {
    if (kapasite >= yeniKapasite) return; //yeni kapasiteye gerek yoksa bir þey yapma
    char *ch = new char[yeniKapasite]; //ch ye  buyuk kapasiteli dizi olusturur
    for (int i = 0; i < uzunluk; i++) { 
        ch[i] = dizi[i];  // tek tek elemanlarý atanýr
    }
    if (dizi != 0) { //items dizisi degil ise silinir heap bellekte cop olusmamasi icin
        delete[] dizi;
    }
    dizi = ch; //gecici dizinin adresi yenikaasiteye yollar
    kapasite = yeniKapasite; //kapasite bilgisi yenilenir


}

void Arraylist::sonaEkle(char sayi) { //dizinin sonuna ekleme 

    indiseEkle(uzunluk, sayi);
}

void Arraylist::uzerineEkle(int i, char item) {//diziye eleman koyar
    if (dizi == NULL) {
        throw "hatali";
    }
    if (i < 0 || i > uzunluk) throw "hatali";

    dizi[i] = item;
}

void Arraylist::indiseEkle(int i, char item) {//dizi icine ekme yapar

    if (i < 0 || i > uzunluk) throw "hatali";
    if (uzunluk >= kapasite)

        if (kapasite) { //capacity sifirsa birden baslatiyor
            alanBuyut(2 * kapasite);
        } else {

            alanBuyut(1);
        }
    for (int j = uzunluk - 1; j >= i; j--) {
        dizi[j + 1] = dizi[j]; //dizi i den itibaren bir saga kaydirilir
    }
    dizi[i] = item;
    uzunluk++;
}

int Arraylist::boyut() const //dizini boyutunu verir
{
    return uzunluk;
}


char Arraylist::indistenAl(int i) {//indisteki elemani getirir
    if (i < 0 || i >= uzunluk) {
        throw "indeks disinda";
    }
    return dizi[i];
}

void Arraylist::indistenSil(int i) {//belirtilen indisteki elemani siler
    if (i < 0 || i >= uzunluk) {
        throw "indeks disinda";
    }

    for (int j = i + 1; j < uzunluk; j++) dizi[j - 1] = dizi[j];
    uzunluk--;
}

void Arraylist::tersCevir() {//diziyi tersine cevirir
    int gecici;
    for (int i = 0; i < uzunluk / 2; i++) {
        gecici = dizi[i];
        dizi[i] = dizi[uzunluk - i - 1];
        dizi[uzunluk - i - 1] = gecici;
    }

}

Arraylist::~Arraylist() {

    if (dizi != NULL) {

        delete[] dizi;
    }
}