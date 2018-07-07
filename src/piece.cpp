#include <string>
#include "piece.h"
#include "player.h"

/// Assertiva de entrada da função: if(isWhite)
Piece::Piece(bool isWhite) : _isWhite(isWhite), _square(NULL)
{
    if(isWhite) /// Assertiva de entrada que checa se a peça é branca
        _color = "W";
    else
        _color = "B";
        /// Assertiva de saída: Se "isWhite" for verdadeiro, a assertiva garante q a peça será considerada branca
}

Piece::~Piece()
{
}



/// Assertivas de entrada da função: 
///if(_isWhite == byPlayer.isWhite()), 
///if(canMoveTo(toSquare)),  
///if(byPlayer.inCheck()), 
///if(toCapture->isWhite() != byPlayer.isWhite()) 
bool Piece::moveTo(Player& byPlayer, Square& toSquare)
{
    bool validMove = false;
    Piece* toCapture = NULL;
    Square* fromSquare = _square;
    
    /// Assertiva de entrada que checa  se a peça está sendo movida pelo jogador correto
    if(_isWhite == byPlayer.isWhite())
    {
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
                    validMove = true;
                }
            }
            else 
            {
                validMove = true;
            }
            /// Assertiva de saída: garante que a peça é capaz de fazer tal movimento
           
		   
		    if(validMove)
            {
            
                if(toCapture)
                {
                    toCapture->setLocation(NULL);
                } 
                
                /// tira a peça do quadrado em que ela estava ocupando
                _square->setOccupier(NULL);
                
                /// seta a nova posição da peça
                _square = &toSquare;
                
                /// seta o novo ocupante do quadrado
                _square->setOccupier(this);
                
                /// Assertiva de entrada:checa se após o movimento o jogador se deixou em cheque
                if(byPlayer.inCheck())
                {
                    /// se tiver em cheque o movimento é negado
                    validMove = false;
                    
                    /// reseta o movimento da peça
                    _square = fromSquare;
                    
                    /// atualiza o ocupante do qaudrado
                    _square->setOccupier(this);
                    
                    /// reseta o ocupante do outro quadrado com e peça do oponente ou NULL
                    toSquare.setOccupier(toCapture);
                    
                    /// caso alguma peça tenha sido capturada, ela é posta no lugar de novo
                    if(toCapture)
                    {
                        toCapture->setLocation(&toSquare);
                    }
                    
                }
                /// Assertiva de saída: se byPlayer.inCheck() for falso, é garantido que o jogador não se deixou em cheque
                
                else 
                {
                    /// se não tiver em cheque então o movimento é feito e come a peça do oponente se necessário
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
