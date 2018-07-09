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
    Player( bool isWhite );
    
    /**
     * Default destructor
     */
    ~Player();

     /**
     * Determines if this is the white player
     *
     * @return if is white
     */
    bool isWhite() const;
    
    /**
     * Get the total score for captured pieces
     *
     * @return score
     */
    int score() const; 

    /**
     * Get the set of this player's pieces
     *
     * @return the set of pieces
     */
    set<Piece*>* myPieces() const;

    /**
     * Get this player's king
     *
     * @return the king
     */
    King* myKing() const;

    
  private:
    
    // Private attributes
    bool _isWhite;
    
}; // Player

#endif
