#include<stdlib.h>
#include<stdio.h>



main(){
	
typedef struct{
	int valor;
    Square& cordenadas_do_quadrado
}jogada;


jogada jogadas[1000];
int k;
int num=0;



//for que passa por todas as peças do jogo
{

//for que passa por todos os quadrados do jogo
{
   
   piece.checar(cordenadas_quadrado_atual);

}

}



piece.moveTo(melhor_jogada().cordenadas_do_quadrado);

   
}








bool Piece::checar_todos_movimento_possiveis(piece peça, Square& cordenada_atual)
{
    bool validMove = false;
    Piece* toCapture = NULL;
    Square* fromSquare = _square;
    
        /// Assertiva de entrada que checa se a peça está se movendo na geometria correta
        if(canMoveTo(toSquare))
        {
            /// checa se o quadrado destino tem uma peça que pode ser comida
            if(toSquare.occupied())
            {
                toCapture = toSquare.occupiedBy();
                
                /// Assertiva de entrada: checa se a peça que está sendo comida é de cor diferente
                if(toCapture->isWhite() != byPlayer.isWhite())
                {
                	jogadas[k].valor=toCapture->value();
                	jogada[k].cordenadas_do_quadrado
                	k++;
                	num++;
                    validMove = true;
                }
            }
            else 
            {
                jogadas[k].valor=0;
                jogada[k].cordenadas_do_quadrado
                	k++;
                	num++
                	validMove = true;
            }
            }
    }
    
    
jogada melhor_jogada(){
    jogada melhor;
    melhor.valor=-9999;
    
    for(k=0;k<num;k++){
    	
    	if(jogadas[k].valor>=melhor.valor){
    		melhor.cordenadas_do_quadrado = jogadas[k].cordenadas;
		}
		
	}
	return melhor;
}



