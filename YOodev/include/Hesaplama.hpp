
/**
* @file Hesaplama.hpp
* @description Programa nasýl yapilacagini anlatmak icin metot tanimlar.
* @course 1/A
* @assignment 1
* @date 5.08.2022
* @authorZeynep Bezirci
*/

#ifndef HESAPLAMA_HPP
#define HESAPLAMA_HPP

#include <string>
#include <fstream>
#include "Arraylist.hpp"
using namespace std;
class Hesaplama{
    
public:
    //bigDecimal kurucu fonksiyonlar
    Hesaplama(string number);
    Hesaplama();
    Hesaplama(int,string);
    
    Hesaplama* operator *=(Hesaplama&);//iki BigDecimali odevde belirtildigi gibi carpar
    friend ofstream& operator<<(ofstream& myfile,Hesaplama& right);//dosyaya yazma arkadas fonksiyonu
    void printBD();
    Arraylist *dizidekiSayi;
    ~Hesaplama();

    
};


#endif /* BIGDECIMAL_HPP */
