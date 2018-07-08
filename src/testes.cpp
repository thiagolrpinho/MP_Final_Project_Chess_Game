#include <iostream>
#include <fstream>
#include <string.h>
#include "Salvar.cpp"

using namespace std;

int main(){
    try{
        menu(1);
        //cout << "Xadrez 123 de oliveira 4\nBrasilia - DF - Brasil\n20/02/2000\n45\nCaio C. F. Alves\nMarcelo A. C. Nazare\n1/2-1/2\n";

        ofstream arquivo;
        arquivo.open("jogo.pgn");
        
        if(!arquivo.is_open( )){
            throw 'a';
        }
    }catch(int e){
        cout << "Cannot create the .pgn file.\n";
    }
    return 0;
}