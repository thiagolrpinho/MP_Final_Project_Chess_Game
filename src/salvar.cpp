#include "../include/salvar.hpp"

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
 
void removepeca(char (*tabuleiro)[8][8], char peca, int x, int y) {


	cout << "peca: " << peca << " x: " << x << " y: " << y << endl;

	int i, j;

	switch(peca) {
		case 'p':
			if((*tabuleiro)[x][y+1] == peca) {
				(*tabuleiro)[x][y+1] = '0'; 
				return;
			}
			if((*tabuleiro)[x+1][y+1] == peca) {
				(*tabuleiro)[x+1][y+1] = '0';
				return;
			}
			if((*tabuleiro)[x-1][y+1] == peca) {
				(*tabuleiro)[x-1][y+1] = '0';
				return;
			}
			if((*tabuleiro)[x+2][y] == peca) {
				(*tabuleiro)[x+2][y] = '0';
				return; 
			}
		case 'P':
			if((*tabuleiro)[x-1][y] == peca) {
				(*tabuleiro)[x-1][y] = '0';
				cout << "a";
			}
			if((*tabuleiro)[x-1][y-1] == peca && x != 0 && y != 0) {
				(*tabuleiro)[x-1][y-1] = '0';
				cout << "b";
			}
			if((*tabuleiro)[x-1][y+1] == peca) {
				(*tabuleiro)[x-1][y+1] = '0';
				cout << "c";
			}
			if((*tabuleiro)[x-2][y] == peca) {
				(*tabuleiro)[x-2][y] = '0';
				cout << "d";
			}
			return;
		case 't':
			for(i = 0; i < 8; i++)
				if((*tabuleiro)[i][y] == peca) {
					(*tabuleiro)[i][y] = '0';
					return;
				}
			for(i = 0; i < 8; i++)
				if((*tabuleiro)[x][i] == peca) {
					(*tabuleiro)[x][i] = '0';
					return;
				}

		case 'T':
			for(i = 0; i < 8; i++)
				if((*tabuleiro)[i][y] == peca) {
					(*tabuleiro)[i][y] = '0';
					return;
				}
			for(i = 0; i < 8; i++)
				if((*tabuleiro)[x][i] == peca) {
					(*tabuleiro)[x][i] = '0';
					return;
				}

		default:
			for(i = 0; i < 8; i++)
    			for(
    				j = 0; j < 8; j++)
    				if((*tabuleiro)[i][j] == peca) {
    					(*tabuleiro)[i][j] = '0';
    					return;
					}
	}

	return;
}

/** The function carregaTab loads all the information contained in the .pgn file.
 * This funtion loads all the information in the .pgn file, this information tells what needed to be 
 * moved or removed in the board to simulate movements made in a game.
 * 
 * If it receives a valid .pgn file it returns a valid board
 * else it return a error message.
 * */
void carregaTab(char (*tabuleiro)[8][8]){
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
    		i++;
    		x = Carregar[i];
    		i++;
    		y = Carregar[i];

    		coordx = x - 'a';
    		coordy = y - '1';
    		cout << "peca1: " << peca << " x: " << x << " y: " << y << endl;

    		removepeca(tabuleiro, peca, coordy, coordx);

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
void salvarTab(char (*tabuleiro)[8][8]){
    char Event[100];
    char Local[100];
    char Data[20];
    int round, tamMaxStr = 100;
    char player1[100];
    char player2[100];
    char resultado[10];
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
    arquivo.open("../saved_games/jogoS.pgn");
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
/** The function verificar checks the inserted piece
 * This function is used to check if the inserted piece can be inserted without pass the limit of numbers of piece type
*/
bool verificar(char (*tabuleiro)[8][8], char peca) {
	int contador = 0;

	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if((*tabuleiro)[i][j] == peca)
				contador++;

	if ((peca == 'z' || peca == 'Z') && contador == 1)
		return false;
	if ((peca == 'b' || peca == 'B' || peca == 't' || peca == 'T' || peca == 'c' || peca == 'C') && contador == 2)
		return false;
	if ((peca == 'p' || peca == 'P') && contador == 8)
		return false;
	if ((peca == 'R' || peca == 'r')  && contador == 9)
		return false;
	return true;
}

/** This function receives a empty board and makes a custom chess board.
 * This function will receive informations of a board created by the user and one by one will put
 * the pieces in the board of chess.
 * 
 * if the piece is vaid and the coodenade two the function will give a board
 * else will give a error message.
 * */
void editar(char (*tabuleiro)[8][8]){
    char coord[5];
    char confirmacao = 's';
    int x = 0;
    int y = 0;
    
    cout << "Informe as posições das peças em coordenadas\n LETRA seguidos de NUMERO, INICIAL DO NOME DA PECA  e B OU P para pecas brancas ou pretas respectivamente :\n";

    while(confirmacao == 's') {
        cout << "Informe o que será adicionado: ";
        fgets(coord, 5, stdin);
        
        if((coord[0] >= 'a'  && coord[0] <= 'h')  &&  (coord[1] >= '1'  && coord[1] <= '8')){
            x = coord[0] - 'a'; 
            y = coord[1] - '1';
            if(coord[3] == 'P' || coord[3] == 'p')
            	coord[2] = toupper(coord[2]);
            if(coord[3] == 'B' || coord[3] == 'b')
            	coord[2] = tolower(coord[2]);
            if(verificar(tabuleiro, coord[2]) == false)
            	cout << "Ja possui o limite de '" << coord[2] << "'" << endl;
            else {
            	(*tabuleiro)[x][y] = coord[2];
            }
        } else
            cout << "Posiçao invalida\n";

        cout << "Deseja inserir mais uma peça? (s/n)\n";
        cin >> confirmacao;
        cin.ignore(1, '\n');
    }
}