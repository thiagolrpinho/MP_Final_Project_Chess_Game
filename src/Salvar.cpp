#include "Salvar.hpp"

/* The function abrePgn receive an file with extension .pgn that contains some iformations.
 It contains the information of place, date, players, winner,
 and the plays made in the game of chess.*/

/* The function carregaTab uses the information gained in abrePgn and put it in the form of a 
board of chess after all the movments registered in the .pgn file*/


void removepeca(char tabuleiro[][8], char peca) {		//TEM Q PASSAR O TABULEIRO POR REFERENCIA NAO CONSEGUI AINDA
	for(int i = 0; i < 8; i++)
    	for(int j = 0; j < 8; j++)
    		if(tabuleiro[i][j] == peca)
    			tabuleiro[i][j] = '0';
}


void carregaTab(char tabuleiro[][8]){
    char Carregar[100000];
    char letra, peca, x, y;
    int coordx, coordy;
    int index = 0, i = 0;


    ifstream carrega;
    carrega.open("../saved_games/jogo.pgn");

    if(!carrega.is_open( )){
        cout << "Não foi possível abrir arquivo! Programa será terminado!\n";
        carrega.clear( ); //reseta o objeto leitura, para limpar memória do sistema}
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

    i = i + 3;	// pegar o movimento dps do numero.
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
    		coordy = y - '0';

    		tabuleiro[coordx][coordy] = peca;

    		i++;
    	} else {
    		i++;
    	}
    }


    // mostrando tabuleiro
    for(int a = 0; a < 8; a++) {
    	cout << endl;
    	for(int b = 0; b < 8; b++)
    		cout << tabuleiro[b][a];
    }





}
/* The function salvarTab saves the statement of the game and other informations of the game.*/
void salvarTab(){
    char Event[100];
    char Local[100];
    char Data[20];
    int round, tamMaxStr = 100;
    char player1[100];
    char player2[100];
    char resultado[2];
    char jogadas[100][3];

    getchar();
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

int main(){
    char tabuleiro [8][8];
    int op = 0;


    //iniciando matriz
    for(int i = 0; i < 8; i++)
    	for(int j = 0; j < 8; j++)
    		tabuleiro[i][j] = '0';


    
    cout << "_____________________________\n";
    cout << "Digite a opcao desejada:\n";
    cout << "1-Salvar Tabuleiro\n";
    cout << "2-Carregar Tabuleiro\n";
    cin >> op;
    switch(op){
        case 1:
            salvarTab();
            break;
        case 2:
            carregaTab(tabuleiro);
            break;
        default:
            cout << "Opção invalida.\n";
            break;
    }
    return 0;
}