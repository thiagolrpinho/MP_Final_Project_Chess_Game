#ifndef PIECE_H
#define PIECE_H

#include <ostream>
#include "square.hpp"
#include "board.hpp"
class Player;

using namespace std;

class Piece 
{
 public:
   
    /**
    * Cria uma pe�a
    *
    * @param isWhite se a cor da pe�a for branca
    */
    Piece(bool isWhite);
    
    
    
    /**
     * Default destructor
     */
    virtual ~Piece();



    /**
    * Move a pe�a para um quadrado tendo certeza que o movimento da pe�a � v�lido.
    *
    * @param pe�a a pe�a no quadrado
    * @return se o movimento for v�lido, retorna esse movimento
    */
    virtual bool moveTo(Player& byPlayer, Square& toSquare);

   
   
    /**
    * Da um "set" no quadrado onde a pe�a estiver
    *
    * @param local do quadrado
    */
    virtual void setLocation(Square* location);

   
   
    /**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    virtual int value() const = 0;

   
   
    /**
    * Determina se e pe�a � branca
    *
    * @return se � branca
    */
    bool isWhite() const;

    
	
	/**
     * Pega a cor da pe�a
     *
     * @return a cor da pe�a
     */
    string color() const;    
    
   
   
    virtual void display() const = 0;   

   
   
    /**
    * Determina se a pe�a pode se mover para um dado quadrado baseado na geometria do movimento
    *
    * @param quadrado o quadrado destino
    * @return se o movimento � v�lido
    */
    virtual bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const = 0;

   
   
    /**
    * Determina se a pe�a est� em um quadrado
    *
    * @return Se est� no quadrado
    */
    bool isOnSquare() const;

   
   
    /**
    * Pega o local da pe�a
    *
    * @return o quadrado onde a pe�a estiver
    */
    Square* location() const;
    
    public: char code_symbol_;

 protected:
    bool _isWhite;
    string _color;
    
 private:

    // Private attributes
    Square* _square;

}; // Pe�a

#endif
