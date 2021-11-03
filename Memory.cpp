#include <iostream>
#include<vector>
#include<string>
#include<ctime>
#include "m/matrix.h"

using namespace std;

//what's initially in the board which is a empty box 
const string ORIG = "?"; 

void generateBoard(matrix<string>&board)
{
  //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
  vector<string>tiles={"👓", "👓", "☂️", "☂️", "🧦", "🧦", "👟", "👟", "🧥", "🧥", " 🥾", " 🥾", "👑", "👑", "🎩", "🎩"};

  //Matrix index always starts at 0

  //Runs a for loop over rows from 0 to 3 
  for(int rows  = 0; rows <= 3; rows++)
  {
    //Runs a inner for loop for columns for 0-3
    for(int col = 0; col <= 3; col++)
    {
      //Then generates 0 - 15 random numbers to be the location for a tiles and puts it around the board, no pair is represented more than once 
      int rand_num = rand() % (15 - 0 + 1) + 0;
      board[rows][col] = tiles[rand_num];
    }
  }
}

//A function that prints out the current board and takes the board as a parameter 
void drawBoard(matrix<string>&board)
{
  //Prints out a x - axis of indexes for the board 
  cout<<" 0️"<<' '<<"1️"<<' '<<"2️"<<' '<<"3️";
  cout<<endl;
  for(int rows = 0; rows <= 3; rows++)
  {
    //Prints the left side of the indexes vertically 
    cout<<rows ; 
    //Runs a for loop printing the board itself with proper spacing either being revealed or hidden 
    for(int col = 0; col <= 3; col++)
    {
      cout<<board[rows][col]<<' ';
    }
    //Prints the right side of the indexes vertically 
    cout<<rows;

    //Prints a new line 
    cout<<endl;
  }
  //Prints out a x - axis of indexes for the board 
  cout<<" 0️"<<' '<<"1️"<<' '<<"2️"<<' '<<"3️";
}

void collectGuess(int &row1, int &row2, int &col1, int &col2, matrix<string>&board)
{
  //Creates a local variable as a boolean to be used in the while loop down below in this function 
  bool condition = false; 
  //Asks the user for their row 1 and collects it 
  cout<<endl<<"Input guess row1: ";
  cin>>row1;

  //Asks the user for their col 1 and collects it 
  cout<<endl<<"Input guess col1: ";
  cin>>col1;

  //Asks the user for their row 2 and collects it 
  cout<<endl<<"Input guess row2: ";
  cin>>row2;

  //Asks the user for their col 2 and collects it 
  cout<<endl<<"Input guess col2: ";
  cin>>col2;

  //A while loop that keeps running as long as condition variable is false
  while(condition == false)
  {
    //Checks if the the row and col for both are between 0 and 3 so it's valid 
    if(row1 >= 0 && col1 >= 0 && row2 >= 0 && col2 >= 0 && row1 <= 3 && col1 <= 3 && row2 <= 3 && col2 <= 3)
    {
      //If that space is occupied on the board for either coordinates and doesn not equal a blank space it is invalid and asks again the user for input 
      if((board[row1][col1] != ORIG) || (board[row2][col2] != ORIG))
      {
        cout<<endl<<"Invalid values ";
      
        cout<<endl<<"Input guess row1: ";
        cin>>row1;

        cout<<endl<<"Input guess col1: ";
        cin>>col2;

        cout<<endl<<"Input guess row2: ";
        cin>>row2;

        cout<<endl<<"Input guess col2: ";
        cin>>col2;
      } 

      //Else condition is true and escapes the while loop 
      else
      {
        condition = true; 
      }
    }
  }
}


void revealCurrent2(int &row1, int &row2, int &col1, int &col2, matrix<string>&board, matrix<string>&key)
{
  //Sets the board coordinates for the row and col * 2 equal to the hidden matrix with the tiles 
 board[row1][col1] = key[row1][col1];
 board[row2][col2] = key[row2][col2];
}

void unmarkCurrent2(int &row1, int &row2, int &col1, int &col2, matrix<string>&board)
{
  //Unmarks the coordinates as a ? 
  board[row1][col1] = "?";
  board[row2][col2] = "?";
}

bool checkMatch(int &row1, int &row2, int &col1, int &col2, matrix<string>&board)
{
  //If the postion on the board for the row1 col1 is equal to row2 col2 return true meaning a match is found 
  if(board[row1][col1] == board[row2][col2])
  {
    return true;
  }

  //Else no match is found return false 
  else
  {
    return false; 
  }
}

int main()
{
  //A fancy function that makes all the random numbers possible randomly generated 
  srand(time(0));
  
  //A string to ask the user if they want to play again 
  string ask_again; 

  do{
    //revealed board with the filled in spots in the matrix as a ?
    matrix<string>board(4, 4, "?");
    //hidden board being the key 
    matrix<string>key(4, 4);

    //Creates the userinput variables of the rows and cols 
    int row1;
    int row2;
    int col1;
    int col2; 

    //Creates a variable called number of matches starting at 8 and generates the board function is called 
    int matches = 8;
    generateBoard(key);

    do{
      //Erases whatver is on the screen
      system("clear");
      //Draws the board with the function
      drawBoard(board);
      //Prints the number of matches left for the user to keep in mind while playing the game 
      cout<<endl<<"Matches Left to Make: "<<matches; 
      //Collect guess is called to gather userinput
      collectGuess(row1, row2, col1, col2, board);
      //Draw board is called
      drawBoard(board);
      //RevealCurrent2 is called 
      revealCurrent2(row1, row2, col1, col2, board, key);
      //Erases whatver is on the screen
      system("clear");
      //Draws the board again 
      drawBoard(board);
      cin.get();
      cin.get();
      //If checkMatch the function is true a match is found and subtracted from the total num of matches variables 
      if(checkMatch(row1, row2, col1, col2, board) == true)
      {
        matches = matches - 1;
      }
      //Else unmark function is called 
      else
      {
        unmarkCurrent2(row1, row2, col1, col2, board);
      }

      //If matches is 0 the game is over and asks the user if they want to play again 
      if(matches == 0)
      {
        cout<<"Would you like to play again (yes or no): ";
        cin>>ask_again;
      }
      //While loop aka the game keeps running as long as matches is greater than 0
    }while(matches>0);

  //Outside while loop keeps running as long as the ask again variable is yes 
  }while(ask_again == "yes");
}