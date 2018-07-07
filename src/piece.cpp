#include <string>
#include "piece.h"
#include "player.h"

/// Assertiva de entrada da fun��o: if(isWhite)
Piece::Piece(bool isWhite) : _isWhite(isWhite), _square(NULL)
{
    if(isWhite) /// Assertiva de entrada que checa se a pe�a � branca
        _color = "W";
    else
        _color = "B";
        /// Assertiva de sa�da: Se "isWhite" for verdadeiro, a assertiva garante q a pe�a ser� considerada branca
}

Piece::~Piece()
{
}



/// Assertivas de entrada da fun��o: 
///if(_isWhite == byPlayer.isWhite()), 
///if(canMoveTo(toSquare)),  
///if(byPlayer.inCheck()), 
///if(toCapture->isWhite() != byPlayer.isWhite()) 
bool Piece::moveTo(Player& byPlayer, Square& toSquare)
{
    bool validMove = false;
    Piece* toCapture = NULL;
    Square* fromSquare = _square;
    
    /// Assertiva de entrada que checa  se a pe�a est� sendo movida pelo jogador correto
    if(_isWhite == byPlayer.isWhite())
    {
        /// Assertiva de entrada que checa se a pe�a est� se movendo na geometria correta
        if(canMoveTo(toSquare))
        {
            /// checa se o quadrado destino tem uma pe�a que pode ser comida
            if(toSquare.occupied())
            {
                toCapture = toSquare.occupiedBy();
                
                /// Assertiva de entrada: checa se a pe�a que est� sendo comida � de cor diferente
                if(toCapture->isWhite() != byPlayer.isWhite())
                {
                    validMove = true;
                }
            }
            else 
            {
                validMove = true;
            }
            /// Assertiva de sa�da: garante que a pe�a � capaz de fazer tal movimento
           
		   
		    if(validMove)
            {
            
                if(toCapture)
                {
                    toCapture->setLocation(NULL);
                } 
                
                /// tira a pe�a do quadrado em que ela estava ocupando
                _square->setOccupier(NULL);
                
                /// seta a nova posi��o da pe�a
                _square = &toSquare;
                
                /// seta o novo ocupante do quadrado
                _square->setOccupier(this);
                
                /// Assertiva de entrada:checa se ap�s o movimento o jogador se deixou em cheque
                if(byPlayer.inCheck())
                {
                    /// se tiver em cheque o movimento � negado
                    validMove = false;
                    
                    /// reseta o movimento da pe�a
                    _square = fromSquare;
                    
                    /// atualiza o ocupante do qaudrado
                    _square->setOccupier(this);
                    
                    /// reseta o ocupante do outro quadrado com e pe�a do oponente ou NULL
                    toSquare.setOccupier(toCapture);
                    
                    /// caso alguma pe�a tenha sido capturada, ela � posta no lugar de novo
                    if(toCapture)
                    {
                        toCapture->setLocation(&toSquare);
                    }
                    
                }
                /// Assertiva de sa�da: se byPlayer.inCheck() for falso, � garantido que o jogador n�o se deixou em cheque
                
                else 
                {
                    /// se n�o tiver em cheque ent�o o movimento � feito e come a pe�a do oponente se necess�rio
                    if(toCapture)
                    {
                        byPlayer.capture(toCapture);
                    } 
                }
            }
        }
    }
    
    return validMove;
}

void Piece::setLocation(Square* location)
{
    _square = location;
}

bool Piece::isWhite() const
{
    return _isWhite;
}

string Piece::color() const
{
    return _color;
}

bool Piece::isOnSquare() const
{
    return _square;
}

Square* Piece::location() const
{
    return _square;
}
