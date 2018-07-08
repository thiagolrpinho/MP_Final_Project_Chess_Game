# MP_Final_Project_Chess_Game


## First things first

Using trello and toggl to organize.

# Chess Game with simple AI


Chess is played on a square board of eight rows (called ranks and denoted with numbers 1 to 8) and eight columns (called files and denoted with letters a to h). The colors of the 64 squares alternate and are referred to as light and dark squares. The chessboard is placed with a light square at the right-hand end of the rank nearest to each player.

By convention, the game pieces are divided into white and black sets, and the players are referred to as White and Black respectively. Each player begins the game with 16 pieces of the specified color, which consist of one king, one queen, two rooks, two bishops, two knights, and eight pawns.

![alt text](https://raw.githubusercontent.com/thiagolrpinho/MP_Final_Project_Chess_Game/develop/chess_rules/annotated-chess_algebraic_naming-squares.png)


## How to play

First clone this repository. 

### Prerequisites

You need g++ installed which is native on ubuntu. 


### Installing

After extracting it, enter on the folder using your terminal and write 
```
make
```

### Play it
After that, write on your console:
```
./play_game
```

## Running the tests

On the folder you installed your Chess Game with simple AI, write in the terminal:
To make a program to run all the tests:
```
make all_tester
```
If you want to see the tests before running it, write:
```
./all_tester --list-tests
```
Or just run it using
```
./all_tester 
```
*Warning
    The all_tester is not fully automatized because I'm new to catch library of tests and don't know how to automatize input and output on terminal tests.
    This happens only with tests_game_interface.cpp*

###Running other tests
To run other tests just go to the main folder of the project:
To test only the Binary Tree used on the game.
```
make board_square_tester
```

Beside the previous tests, if you want to test too the game statements of the game:
```
make board_tester
```

If you want to test too the game engine:
```
make engine_tester
```

### Gcov Test
If you have gcov and gcovr installed, you can generate the 
test coverture of the binary tree by typing:
```
make gcov_board
```
And then:
```
./gcov_board
```

You can additionally check game statements and game engine by changing *gcov_board_square*
for *gcov_board* or *gcov_engine* respectively on the previous list of instruction.
You can also just generate for all tests by doing:
```
make gcov_tester
```
And then:
```
./gcov_tester
```

To generate a graphical representation of how much the code is covered by the tests you can type:
```
make gcovr_html
```
The output files are located insides the './test/gcov' folder that must be previously created if not.


## More information
There's a folder created with doxygen that contains an interactive way to see the classes and methods used in the game.

## Built With

* [Catch](http://catch-lib.net/) - The test library used

## Author

* **Thiago Luis Rodrigues Pinho** - *Chess Game with simple AI* - [Thiago Luis](https://github.com/thiagolrpinho/MP_Final_Project_Chess_Game)



## Acknowledgments

* It was my first time developing using TTD method in a team. I learned a lot and I am grateful for 
the experience. 
* It think this was a bit too complex for a three weeks project. 
* I wish I could have organized my code more. 
* Thanks for reading until here.
* Sorry for english and programing mistakes. If any mistakes were made, please inform us and we'll fix it

