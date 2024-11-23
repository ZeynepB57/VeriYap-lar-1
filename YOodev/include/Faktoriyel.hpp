
/**
* @file Faktoriyel.hpp
* @description Programa nasýl yapilacagini anlatmak icin metot tanimlar.
* @course 1/A
* @assignment 1
* @date 5.08.2022
* @author Zeynep Bezirci
*/
#include "Hesaplama.hpp"

#ifndef FAKTORIYEL_HPP
#define FAKTORIYEL_HPP

class Faktoriyel{
public:
    Faktoriyel(int);
    Hesaplama* getResult();
    ~Faktoriyel();
private:
    void calculateFact(int num);//factorial hesaplar
    Hesaplama * sonuc;
};


#endif /* FACTORIAL_HPP */
