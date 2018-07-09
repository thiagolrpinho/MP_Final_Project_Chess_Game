// #include "editar.hpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

/** This is the main board. 
 * This board contains all the pieces of a chess game in the initial positions, this positions
 * will be modified by the informations of all movements made in a game conteined in a .pgn file.
 * 
 * Any board will be allways inte same formact;
 * */  
char tabuleiro[8][8] ={
                        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
                        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        { '0', '0', '0', '0', '0', '0', '0', '0'},
                        { '0', '0', '0', '0', '0', '0', '0', '0'},
                        { '0', '0', '0', '0', '0', '0', '0', '0'},
                        { '0', '0', '0', '0', '0', '0', '0', '0'},
                        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
                    };

/** This function makes a custom chess board.
 * This function will receive informations of a board created by the user and one by one will put
 * the pieces in the board of chess.
 * 
 * if the piece is vaid and the coodenade two the function will give a board
 * else will give a error message.
 * */
void editar(){
    char coord[4];
    char confirmacao;
    int x = 0;
    int y = 0;
    
    cout << "Informe as posições das peças em coordenadas\n LETRA seguidos de NUMERO, INICIAL DO NOME DA PECA B OU P para pecas brancas ou pretas respectivamente :\n";

    while(confirmacao == 's'){
        cout << "Informe o que será adicionado: ";
        fgets(coord, 4, stdin);
        
        if((coord[0] >= 'a'  && coord[0] <= 'h')  &&  (coord[1] >= '1'  && coord[1] <= '8')){
            x = coord[0] - 'a'; 
            y = coord[1] - '1';

            if(coord[3] <= 'Z' && coord[3] >= 'A')
                tabuleiro[x][y] = toupper(coord[2]);
            if(coord[3] <= 'z' && coord[3] >= 'a')
                tabuleiro[x][y] = tolower(coord[2]);
        }else
            cout << "Peça invalida \n";
        cout << "Deseja inserir mais uma peça? (s/n)\n";
        cin >> confirmacao;
    }
}