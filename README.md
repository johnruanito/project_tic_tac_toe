This project consists of a simple implementation of the classic tic-tac-toe game in C++. The code is contained in the file "Project-Tic_Tac_Toe.cpp", where the main function is the program's entry point.

Functionalities:
Representative Board:

It uses a 3x3 matrix to represent the game board.
Initializes the board with numbers representing blank spaces.
Board View:

The drawBoard function displays the current board on the screen, showing the positions occupied by each player's markers.
Tie Check:

The isBoardFull function checks whether the board is completely filled, indicating a draw.
Winner Verification:

The isWinner function checks whether a player won, analyzing all winning possibilities in the rows, columns and diagonals.
Player Change:

The changePlayer function changes the current player between 'X' and 'O' after each move.
Making Plays:

The makeMove function requests the current player's move, checks the validity of the move, and updates the board.
Beginning of the game:

The startGame function coordinates the start and execution of the game, calling the necessary functions until there is a winner or a draw.
Home Menu:

The menuStart function displays a menu with options to play, get game information, or exit. The menu is presented until the user makes a valid choice.
How to Execute:
Clone the repository.
Compile and run the "Project-Tic_Tac_Toe.cpp" file.
Home Menu:
Play (Option 1):

Start the game of tic-tac-toe.
About (Option 2):

Displays information about the game.
Exit (Option 3):

Closes the program.
Comments:
The game is played on the console, and instructions are provided as you play.
To play, the user enters the desired row and column.
The program automatically checks whether there was a winner or whether the game ended in a draw.
Have fun playing the classic tic-tac-toe!