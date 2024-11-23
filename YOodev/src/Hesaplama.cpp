
/**
* @file Hesaplama.cpp
* @description Programa nasýl yapilacagini anlatmak icin metotlara govde tanimlar
* @course 1/A
* @assignment 1
* @date 5.08.2022
* @authorZeynep Bezirci
*/

#define CHARTOINT 48    //'0' in ascii karsiligi
#define INTTOCHAR 48
#include "Hesaplama.hpp"

#include <iostream>

Hesaplama::Hesaplama(string sayi) {//parametreli constructor
    dizidekiSayi = new Arraylist();

    for (int i = 0; i < sayi.length(); i++) {
        dizidekiSayi->sonaEkle(sayi[i]);
    }
}

Hesaplama::Hesaplama(int times, string sayi) {//terarli sayi constructori
    dizidekiSayi = new Arraylist();

    for (int i = 0; i < times; i++) {
        for (int j = 0; j < sayi.length(); j++) {
            dizidekiSayi->sonaEkle(sayi[j]);
        }

    }
}

Hesaplama::Hesaplama() { //parametresiz constructor
    dizidekiSayi = new Arraylist();

}


Hesaplama* Hesaplama::operator*=(Hesaplama& num1) {
    //iki buyuk sayiyi odevede istenildigi gibi carpma fonsiyonu

    //sayilarin boyutlari
    int boy1 = num1.dizidekiSayi->boyut();
    int boy2 = this->dizidekiSayi->boyut();


    Hesaplama *sonuc = new Hesaplama(boy1 + boy2, "0");

    if (boy1 == 0 || boy2 == 0) {//sayi girilmeden enter tuþuna basýlýrsa sonuc yapýlýr
        delete sonuc;
        sonuc = new Hesaplama("0");
        return sonuc;
    }

    int kontrol1 = 0;
    int kontrol2 = 0;

    //asýl faktoriyel hesabý
    for (int i = boy1 - 1; i >= 0; i--) {       //girilen sayinin boyutu kadar döner
        int elde = 0; //elde baþta 0 olduðu için 
        int n1 = num1.dizidekiSayi->indistenAl(i) - CHARTOINT; //sayinin basmaginin n1 e atanmasi

        kontrol2 = 0;   

        for (int j = boy2 - 1; j >= 0; j--) {

            int n2 = this->dizidekiSayi->indistenAl(j) - CHARTOINT; //sayinin basamagi n1 e atanmasi

            int sum = (n1 * n2) + (sonuc->dizidekiSayi->indistenAl(kontrol1 + kontrol2) - CHARTOINT) + elde; //eldeli bir sekilde bastoplanmasi

            elde = sum / 10; //eldeyi bulmak icin

            sonuc->dizidekiSayi->uzerineEkle(kontrol1 + kontrol2, (sum % 10) + INTTOCHAR); //sonuca ata
            kontrol2++; //bir sonraki indisten sayi almak icin

        }
        //elde 0 dan buyukse sayiye ekler
        // sola kaydirma islemi icin
        if (elde > 0) {
            int num = sonuc->dizidekiSayi->indistenAl(kontrol1 + kontrol2) - CHARTOINT;
            sonuc->dizidekiSayi->uzerineEkle(kontrol1 + kontrol2, (num + elde) + CHARTOINT);
        }
      
       

    }

    //arraylite atacagýmýz icin sonucu ters cevirir
    sonuc->dizidekiSayi->tersCevir();
   
    return sonuc;
}


void Hesaplama::printBD(){
    cout<<endl<<"printBD"<<endl;

     if (this->dizidekiSayi != NULL) {
        for (int i=0;i<this->dizidekiSayi->boyut();i++)
             cout<<this->dizidekiSayi->indistenAl(i);

} else cout<<"No value!!!"<<endl;

}

Hesaplama::~Hesaplama() {

    if (this->dizidekiSayi != NULL) {
        delete this->dizidekiSayi;
    }
}

ofstream& operator<<(ofstream& myfile, Hesaplama& yazilacak) {//dosyaya yazma fonksiyonu

    for (int i = 0; i < yazilacak.dizidekiSayi->boyut(); i++) {
        myfile << yazilacak.dizidekiSayi->indistenAl(i);

    }
    return myfile;
}