#include <iostream>
#include <ctime>
#include <vector>
 
using namespace std;
//Location And Naming Constant Emoji's of the different colored hearts for now make it numbers so it is simple to use and th labels of the hearts 1 to 5
 
const string label1 ="1️⃣";
const string label2 ="2️⃣";
const string label3 ="3️⃣";
const string label4 ="4️⃣";
const string label5 ="5️⃣";

const string RED = "❤️";
const string BLUE = "💙";
const string GREEN="💚";
const string YELLOW="💛";
const string PURPLE="💜";

//Const vector variable holding all the hearts in order to be used later on in the program 
const vector<string> HEARTS = {"ZERO", RED, BLUE, GREEN, YELLOW, PURPLE};
 
//Function For Introduction of game like the directions
void introduction()
{
 //Prints out the rules of the game 
 cout<<"Rules of Hearts!: ";
 cout<<endl<<"The computer has selected hearts of three colors and placed them in 3 positions. ";
 cout<<endl<<"Your task is to guess which color hearts are used AND in what positions they have been placed. ";
 cout<<endl<<"You have 10 tries. ";
 cout<<endl<<"While there are 5 possible colors, only 3 are used. ";
 cout<<endl<<"There is only one heart of each color. ";
}
 
//Function for printing the correct solution of numbers in order for guessing purposes
void correct_solution(vector<int>&order)
{
  cout<<"Take this out in real game! This just allows me to cheat while working!";
  cout<<endl<<"Correct Solution ";

  //Uses a for loop to print the correct order of the colored hearts later implemented in the program
  for(int index = 0; index<order.size(); index++)
  {
    cout<<HEARTS[order[index]]<<" "; 
  }
  cout<<endl;
}
 
//Function for asking the user for their guesses and printing the order of the random numbers or colored hearts in random order by the computer
void guess(int &guess1, int &guess2, int &guess3)
{
  //Asks user of there guesses all in 3 separate lines corresponding to integer variables and hearts and labels printed above for user refrence 
  cout<<"Enter your guesses: ";
  cout<<endl<<label1<<"   "<<label2<<"   "<<label3<< "   "<<label4<<"   "<<label5; 
  cout<<endl<<" ❤️ "<<" 💙 "<<" 💚 "<<" 💛 "<<" 💜 "<<endl;
  cin>>guess1;
  cin>>guess2;
  cin>>guess3; 
}
 
//Function for printing score like the colors correct, positions correct, and attempts left
void output(int &colors_correct, int &positions_correct, int &attempts, int &guess1, int &guess2, int &guess3, vector<int>&order)
{
  cout<<"-----------------------------------";
  //If the users postions for the hearts are correct it adds one to the postions correct score 
  if(guess1==order[0] && guess2 == order[1] && guess3 == order[2])
  {
    positions_correct += 1;
  }

  //If the user color for the heart is correct it adds one to the colors correct score 
  if((guess1 == order[0] || guess1 == order[1] || guess1 == order[2]) && (guess2==order[0] || guess2 == order[1] || guess2 == order[2]) && (guess3 == order[0] || guess3 == order[1] || guess3 == order[2]))
  {
    colors_correct += 1; 
  }

  //Decreases attempts starting at 10 in main by 1 everytime this happens in this function 
  attempts -= 1; 

  //Prints out the score for colors correct, postions correct, and the users attempts left 
  cout<<endl<<"Colors correct: "<<colors_correct;
  cout<<endl<<"Positions correct: "<<positions_correct;
  cout<<endl<<"Attempts left: "<<attempts; 
  cout<<endl<<"-----------------------------------";
}
 
//Function for asking user if they want to play again and having if and else conditions and upper lower function for char variable
bool play_again(char &playagain)
{
  //States the vector for the order of the hearts to correspond with now after the user wins it displays the correct solution from that function being called 
  vector<int>order;
  correct_solution(order);

  //Asks the user if they want to play agin and collects it in a char playagain variable 
  cout<<endl<<"Pretty decent ";
  cout<<"Want to play again? y/n: ";
  cin>>playagain;

  //If the user's option is yes either y or Y it returns true 
  if(tolower(playagain) == 'y')
  {
    return true; 
  }

  //Else it is assumed as no so it returns false 
  else
  {
    return false;
  }
}
 
int main() 
{
 //Fancy function from the libary ctime to make all numbers as random as possible 
 srand(time(0));
 
 //All under a while loop as long as the user wants to keep playing for the play again function above
 
 //In main name all the variables that are needed above in the functions are parameters
 
 //Enter your guesses variable will be a int 3 separate but collect all on one cin statementn like cin>>a cin>>b; cin>>c; or cin>>a>>b>>c;

  //Char play again variable
  char playagain;
    do {
    //do while loop to play again

    //Creates the 3 guess variables for the user guessing the order of the hearts 
    int guess1;
    int guess2;
    int guess3;
    
    //Int colors correct variable
    int colors_correct = 0;
    //Int positions correct variable
    int positions_correct = 0;
    //Int Attempts left variable
    int attempts = 10;
    
    //Vector Int variable for computer holding it's order of numbers in their positions
    
    //Instead of this generate 3 random numbers between 1 and 5 and put them in a vector or separate int variables maybe use a for loop for this
    int random1; 
    int random2; 
    int random3; 

    while(random1 == random2 || random2 == random3 || random3 == random1)
    {
      random1 = rand() % (5 - 1 + 1) + 1; 
      random2 = rand() % (5 - 1 + 1) + 1; 
      random3 = rand() % (5 - 1 + 1) + 1; 
    }
    
    //Puts the 3 random numbers used for the hearts in the vector order variable for refrence in above functions used as a parameter 
    vector<int>order ={random1, random2, random3};

    //While loop to keep running as long as the user is not correct for their guess of the hearts order or their attempts has reach 0
    while(!((positions_correct >=1 && colors_correct >= 1) || attempts == 0))
    {
      introduction();
      guess(guess1, guess2, guess3);
      output(colors_correct, positions_correct, attempts, guess1, guess2, guess3, order);
    }

    
    //end of loop to play again if playagain results in true since it is a bool function seen above  
    }while(play_again(playagain) == true);
}


