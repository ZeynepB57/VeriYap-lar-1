
/**
* @file Test.cpp
* @description main fonksiyonunun oldugu sinif.
* @course 1/A
* @assignment 1
* @date 5.08.2022
* @authorZeynep Bezirci
*/

#include <cstdlib>
#include <iostream>
#include "Arraylist.hpp"
#include "Hesaplama.hpp"
#include "Faktoriyel.hpp"

/*
 * 
 */
int main(int argc, char** argv) {


    ofstream dosya("Sonuc.txt"); //Sonuc.txt dosyasini acilmasi yada olusturulmasi inin yapildi
    int num = 100;

    std::cout << "Faktoriyeli alinacak sayiyi giriniz:\n";

    std::cin>>num;

    Faktoriyel * fakt = new Faktoriyel(num);
    
    dosya << *fakt->getResult(); //sonucu dosyaya yazmak icin

	delete fakt;  //oluþturulan iþaretciyi sileer cop oluþmamasý icin


    return 0;
}
