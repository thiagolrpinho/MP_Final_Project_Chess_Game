/**
 * player.hpp
 *
 * This class represents a chess player.
 *
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "piece.hpp"

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

    
  private:
    
    // Private attributes
    bool _isWhite;
    
}; // Player

#endif
