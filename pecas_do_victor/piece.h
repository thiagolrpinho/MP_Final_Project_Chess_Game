#ifndef PIECE_H
#define PIECE_H

#include <ostream>
#include "square.h"
#include "board.h"
class Player;

using namespace std;

class Piece 
{
 public:
   
    /**
    * Cria uma peça
    *
    * @param isWhite se a cor da peça for branca
    */
    Piece(bool isWhite);
    
    
    
    /**
     * Default destructor
     */
    virtual ~Piece();



    /**
    * Move a peça para um quadrado tendo certeza que o movimento da peça é válido.
    *
    * @param peça a peça no quadrado
    * @return se o movimento for válido, retorna esse movimento
    */
    virtual bool moveTo(Player& byPlayer, Square& toSquare);

   
   
    /**
    * Da um "set" no quadrado onde a peça estiver
    *
    * @param local do quadrado
    */
    virtual void setLocation(Square* location);

   
   
    /**
    * Pega o valor da peça
    *
    * @return o valor
    */
    virtual int value() const = 0;

   
   
    /**
    * Determina se e peça é branca
    *
    * @return se é branca
    */
    bool isWhite() const;

    
	
	/**
     * Pega a cor da peça
     *
     * @return a cor da peça
     */
    string color() const;    
    
   
   
    virtual void display() const = 0;   

   
   
    /**
    * Determina se a peça pode se mover para um dado quadrado baseado na geometria do movimento
    *
    * @param quadrado o quadrado destino
    * @return se o movimento é válido
    */
    virtual bool canMoveTo(Square& location) const = 0;

   
   
    /**
    * Determina se a peça está em um quadrado
    *
    * @return Se está no quadrado
    */
    bool isOnSquare() const;

   
   
    /**
    * Pega o local da peça
    *
    * @return o quadrado onde a peça estiver
    */
    Square* location() const;

 protected:
    bool _isWhite;
    string _color;
    
 private:

    // Private attributes
    Square* _square;

}; // Peça

#endif
