#include "Salvar.hpp"

using namespace std;

/** This is the main board. 
 * This board contains all the pieces of a chess game in the initial positions, this positions
 * will be modified by the informations of all movements made in a game conteined in a .pgn file.
 * 
 * Any board will be allways inte same formact;
 *  
tabuleiro[8][8] ={
                        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
                        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        { '0', '0', '0', '0', '0', '0', '0', '0'},
                        { '0', '0', '0', '0', '0', '0', '0', '0'},
                        { '0', '0', '0', '0', '0', '0', '0', '0'},
                        { '0', '0', '0', '0', '0', '0', '0', '0'},
                        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
                    };
*/

/** The function removepeca removes the piece to make the move registered in .pgn file
 * This function receives what piece need to be removed from its place to be possible to
 * make a move as informed in the .pgn file.
 * 
 * If if receives one piece and returns a board,
 *  else it wont do any move;
 * */
 
void removepeca(char (*tabuleiro)[8][8], char peca) {
	for(int i = 0; i < 8; i++)
    	for(int j = 0; j < 8; j++)
    		if((*tabuleiro)[i][j] == peca) {
    			(*tabuleiro)[i][j] = '0';
    			return;
    		}
}

/** The function carregarTab loads all the information contained in the .pgn file.
 * This funtion loads all the information in the .pgn file, this information tells what needed to be 
 * moved or removed in the board to simulate movements made in a game.
 * 
 * If it receives a valid .pgn file it returns a valid board
 * else it return a error message.
 * */
void carregaTab(char (*tabuleiro)[8][8]){		//ALTERAR NA HORA DE JUNTAR TUDO PARA RETORNAR O TIPO ADEQUADO
    char Carregar[100000];
    char letra, peca, x, y;
    int coordx, coordy;
    int index = 0, i = 0;


    ifstream carrega;
    carrega.open("../saved_games/jogo.pgn");

    if(!carrega.is_open( )){
        cout << "Não foi possível abrir arquivo! Programa será terminado!\n";
        carrega.clear( );
        return;
    }


    while(carrega.get(letra)){
        if(letra != ']'){
            Carregar [index]= letra;
            index ++;
        }else{
            Carregar [index]= ']';
            index ++;
        }
    }
    carrega.close();
    cout << Carregar << endl;


    while(Carregar[i] != '1' || Carregar[i+1] != '.') {
    	i++;
    }

    i = i + 3;
    while(i < index - 1) {
    	if (Carregar[i] == 'T' || Carregar[i] == 'C' || Carregar[i] == 'B' || Carregar[i] == 'R' || Carregar[i] == 'Z' || Carregar[i] == 'P' ||  
    	Carregar[i] == 't' || Carregar[i] == 'c' || Carregar[i] == 'b' || Carregar[i] == 'r' || Carregar[i] == 'z' || Carregar[i] == 'p') {
    		peca = Carregar[i];
    		removepeca(tabuleiro, peca);
    		i++;
    		x = Carregar[i];
    		i++;
    		y = Carregar[i];

    		coordx = x - 'a';
    		coordy = y - '1';

    		(*tabuleiro)[coordy][coordx] = peca;

    		i++;
    	} else {
    		i++;
    	}
    }
}
/** The function salvarTab saves the statement of the game.
 * This function is used to save all the information as the event, the location, the names of the players,
 * what round is, the date of the event and other informations of the game. This will save all the movemets of the chess game
 * that will be saved, including the removed pieces from the game.
 * 
 * If it receives all the informations in the correct formact it returns a .pgn file
 * else it returns a error message
 * */
void salvarTab(){
    char Event[100];
    char Local[100];
    char Data[20];
    int round, tamMaxStr = 100;
    char player1[100];
    char player2[100];
    char resultado[2];
    char jogadas[100][3];

    cout << "Digite o nome do evento: \n";
    fgets(Event, tamMaxStr, stdin);
    strtok(Event, "\n");

    cout << "Informe o local do evento: \n";
    fgets(Local, tamMaxStr, stdin);
    strtok(Local, "\n");
    
    cout << "Informe a data do evento: \n";
    fgets(Data, tamMaxStr, stdin);
    strtok(Data, "\n");

    cout << "Informe o round da partida: \n";
    cin >> round;
    getchar();
    
    cout << "Informe o nome do primeiro jogador: \n";
    fgets(player1, tamMaxStr, stdin);
    strtok(player1, "\n");
    
    cout << "Informe o nome do segundo jogador: \n";
    fgets(player2, tamMaxStr, stdin);
    strtok(player2, "\n");

    cout << "Informe o resultado: \n";
    fgets(resultado, 10, stdin);
    strtok(resultado, "\n");

    ofstream arquivo;
    arquivo.open("jogo.pgn");
    arquivo << "[" << "Event " << '"' << Event << '"' << "]" << endl;
    arquivo << "[" << "Local " << '"' << Local << '"' << "]" << endl;
    arquivo << "[" << "Date " << '"' << Data << '"' << "]" << endl;
    arquivo << "[" << "Round " << '"' << round << '"' << "]" << endl;
    arquivo << "[" << "White " << '"' << player1 << '"' << "]" << endl;
    arquivo << "[" << "Black " << '"' << player2 << '"' << "]" << endl;
    arquivo << "[" << "Result " << '"' << resultado << '"' << "]*" << endl;

    //Receber as jogadas para montar o .pgn.
    arquivo.close();

}