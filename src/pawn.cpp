#include "pawn.hpp"
#include "queen.hpp"
#include "board.hpp"

Pawn::Pawn(bool isWhite) : RestrictedPiece(isWhite), _delegate(NULL)
{
}

Pawn::~Pawn()
{
    if(_delegate)
        delete _delegate;
}


void Pawn::setLocation(Square* location)
{
    Piece::setLocation(location);
}


int Pawn::value() const
{
    return 1;
}


/// Assertiva de entrada da fun��o: if(_delegate)
bool Pawn::moveTo(Player& byPlayer, Square& to)
{
    bool valid = false;
    int promoted_pawn=0;
    
    /// Assertiva de entrada que checa se o pe�o foi promovido
    /// se o pe�o tiver sido promovido
    if(_delegate)
    {
        /// usa as regras de movimento da pe�a em que o pe�o se promoveu
        valid = _delegate->moveTo(byPlayer, to);
        
        /// se o movimento for v�lido, move o pe�o
        if(valid)
        {
            /// unseta o ocupante do quadrado do pe�o 
            location()->setOccupier(NULL);
            
           /// seta a nova posi��o do pe�o
            setLocation(&to);
            
            /// seta o novo ocupante do quadrado
            location()->setOccupier(this);
        }
        /// Assertiva de sa�da: � garantido que o pe�o promovido se mover� de acordo com as regras da nova pe�a
    }
    else 
    {
        /// se ele n�o tiver sido promovido, ele se mover� normalmente igual a um pe�o
        valid = RestrictedPiece::moveTo(byPlayer, to);
        
        /// se o movimento � v�lido e o pe�o atingiu o final do tabuleiro, ele � promovido 
    
        if(valid)
        {
            if(Board::getBoard()->isEndRow(*location()))
            {
            	if(promoted_pawn==0){
                _delegate = new Queen(isWhite());
                _delegate->setLocation(location());
            }
            }
        }
    }
    
    return valid;
}


///Assertiva de entrada da fun��o: if(!hasMoved() && translationY == 2 && translationX == 0 && Board::getBoard()->isClearVertical(*(this->location()), location))
bool Pawn::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();
    
    /// se o pe�o for promovido, usar as regras de movimento da nova pe�a
    if(_delegate)
    {
        validMove = _delegate->canMoveTo(location);
    }
    /// sen�o, usa as regras de movimento padr�o do pe�o
    else 
    {
        // andar para frente significa andar para atras do ponto de vista das pe�as pretas
        if(!isWhite())
        {
            translationX *= -1;
            translationY *= -1;
        }
        
        /// o movimento � v�lido se ele for um movimento de um quadrado pra frente(se n�o tiver nenhuma pe�a na frente)
        if(!location.occupied() && translationY == 1 && translationX == 0)
        {
            validMove = true;
        }
        
        ///  se o pe�o n tiver se movido no jogo e os dois quadrados a sua frente estiverem livres, o pe�o poder� fazer seu movimento especial de se mover 2 quadrados para frente
        /// Assertiva de entrada que checa se o pe�o j� se moveu no jogo
        else if(!hasMoved() && translationY == 2 && translationX == 0 &&
                Board::getBoard()->isClearVertical(*(this->location()), location))
        {
            validMove = true;
            /// Assertiva de sa�da: � garantido que o pe�o n�o se moveu antes do seu movimento especial 
        }
        
        /// o movimento tamb�m � v�lido se o pe�o for comer uma pe�a na diagonal
        else if(location.occupied() && translationY == 1 && 
                (translationX == 1 || translationX == -1))
        {
            validMove = true;
        }        
    }

    return validMove;
}

void Pawn::display() const
{
    if(_delegate)
    {
        _delegate->display();
    }
    else
    {
        cout << _color + "P";
    }
}


char Pawn::getCodeSymbol()
{
  if ( isWhite )
  {
    return'p';

  } else {
    return 'P';
  }
  
}
