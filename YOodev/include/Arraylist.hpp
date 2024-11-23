
/**
* @file Arraylist.hpp
* @description Arraylist olusturmak icin metot tanimlar.
* @course 1/A
* @assignment 1
* @date 5.08.2022
* @authorZeynep Bezirci
*/

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP


class Arraylist{
public:
    Arraylist();
    void sonaEkle( char item);//dizinin sonuna eleman ekler
    void indiseEkle(int i, char item);//dizin istelilen indisine eleman ekler
    int boyut() const;//dizini boyutunu verir
    char indistenAl(int i) ;//belirtilen indisteki elemani verir
    void indistenSil(int i);//belirtilen indisteki elemani siler 
    void uzerineEkle(int ,char);//dizinin istenilen yerine eleman koyar  insertten farki indisteki elemanin uzerine yaziliyor olmasi
    void tersCevir();//diziyi tersine cevirir
    ~Arraylist();
    
private:
    char *dizi;
    int uzunluk;
    int kapasite;
    void alanBuyut(int);//yeni alan olusturur
};


#endif /* ARRAYLIST_HPP */
