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


/// Assertiva de entrada da função: if(_delegate)
bool Pawn::moveTo(Player& byPlayer, Square& to)
{
    bool valid = false;
    int promoted_pawn=0;
    
    /// Assertiva de entrada que checa se o peão foi promovido
    /// se o peão tiver sido promovido
    if(_delegate)
    {
        /// usa as regras de movimento da peça em que o peão se promoveu
        valid = _delegate->moveTo(byPlayer, to);
        
        /// se o movimento for válido, move o peão
        if(valid)
        {
            /// unseta o ocupante do quadrado do peão 
            location()->setOccupier(NULL);
            
           /// seta a nova posição do peão
            setLocation(&to);
            
            /// seta o novo ocupante do quadrado
            location()->setOccupier(this);
        }
        /// Assertiva de saída: é garantido que o peão promovido se moverá de acordo com as regras da nova peça
    }
    else 
    {
        /// se ele não tiver sido promovido, ele se moverá normalmente igual a um peão
        valid = RestrictedPiece::moveTo(byPlayer, to);
        
        /// se o movimento é válido e o peão atingiu o final do tabuleiro, ele é promovido 
    
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


///Assertiva de entrada da função: if(!hasMoved() && translationY == 2 && translationX == 0 && Board::getBoard()->isClearVertical(*(this->location()), location))
bool Pawn::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();
    
    /// se o peão for promovido, usar as regras de movimento da nova peça
    if(_delegate)
    {
        validMove = _delegate->canMoveTo(location);
    }
    /// senão, usa as regras de movimento padrão do peão
    else 
    {
        // andar para frente significa andar para atras do ponto de vista das peças pretas
        if(!isWhite())
        {
            translationX *= -1;
            translationY *= -1;
        }
        
        /// o movimento é válido se ele for um movimento de um quadrado pra frente(se não tiver nenhuma peça na frente)
        if(!location.occupied() && translationY == 1 && translationX == 0)
        {
            validMove = true;
        }
        
        ///  se o peão n tiver se movido no jogo e os dois quadrados a sua frente estiverem livres, o peão poderá fazer seu movimento especial de se mover 2 quadrados para frente
        /// Assertiva de entrada que checa se o peão já se moveu no jogo
        else if(!hasMoved() && translationY == 2 && translationX == 0 &&
                Board::getBoard()->isClearVertical(*(this->location()), location))
        {
            validMove = true;
            /// Assertiva de saída: é garantido que o peão não se moveu antes do seu movimento especial 
        }
        
        /// o movimento também é válido se o peão for comer uma peça na diagonal
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
