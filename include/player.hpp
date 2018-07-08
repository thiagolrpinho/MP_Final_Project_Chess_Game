/**
 * player.hpp
 *
 * This class represents a chess player.
 *
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "piece.hpp"
#include "king.hpp"

#include <string>
using std::string; 

#include <set>
using std::set;


class Player 
{
  public:
    
    /**
     * Creates a Player
     *
     * @params x, y the location of the square on the board
     */
    Player(string name, bool isWhite, King& myKing, set<Piece*>& myPieces);
    
    /**
     * Default destructor
     */
    ~Player();
    
  private:
    
    // Private attributes
    bool _isWhite;
    set<Piece*>& _myPieces;
    set<Piece*> _capturedPieces;
    King& _myKing;
    
}; // Player

#endif
