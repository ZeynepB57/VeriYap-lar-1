/**
* @file Faktoriyel.cpp
* @description Programa nasýl yapilacagini anlatmak icin metotlara govde tanimlar
* @course 1/A
* @assignment 1
* @date 5.08.2022
* @authorZeynep Bezirci
*/

#include "Faktoriyel.hpp"
#include <string>

#include <iostream>
#include <sstream>

Hesaplama * Faktoriyel::getResult() {
    return sonuc;   // sonucu döndürür
}

Faktoriyel::Faktoriyel(int sayi) {
    calculateFact(sayi);
}


void Faktoriyel::calculateFact(int sayi) {//faktoriyal hesaplar


  string str;
  stringstream ss;  
  ss << sayi;  
  ss >> str;

      Hesaplama *faktor = new Hesaplama(str);


    Hesaplama *eskiDeger;

    if (sayi <= 1) {
        delete faktor ;
        faktor=new Hesaplama("1");
        sonuc =faktor;
        return;

    } else {
        for (int i = (sayi-1); i >=1 ; --i) {

            ss.clear();
            ss << i;  
            ss >> str; 
            
            Hesaplama * geciciSayi = new Hesaplama(str); //bir sonraki sayi 
//           

            eskiDeger = faktor;
            faktor =(*eskiDeger)*=(*geciciSayi);

            delete eskiDeger; //eski deger silinir
            delete geciciSayi; //gecici sayiyi siler
        }
    }

    sonuc = faktor;

    int bastakiSifirSayisi = 0; //basindaki 0 larin sayisi icin degisken

    for (int z = 0; z < faktor->dizidekiSayi->boyut(); z++) { //sonucun basindaki 0 sayisini bulmak icin

        if (faktor->dizidekiSayi->indistenAl(z) != '0') {
            bastakiSifirSayisi = z;
            break;

        }

    }//sonuc sifir ise tek sifir yapar
    if (bastakiSifirSayisi == faktor->dizidekiSayi->boyut()) {
        delete faktor;
        faktor = new Hesaplama("0");
        bastakiSifirSayisi = -1;
    }

    //sayinin basindaki sifirlari temizler
    while (bastakiSifirSayisi > 0) { // basta sifir kalmayana kadar döner 
        faktor->dizidekiSayi->indistenSil(0);   
        bastakiSifirSayisi--;
    }

    sonuc = faktor;  
}

Faktoriyel::~Faktoriyel(){
	if(sonuc!=NULL) delete sonuc;
}