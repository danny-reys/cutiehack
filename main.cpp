#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

//HANGMAN GAME

void alphaList(vector<char> list, vector <bool> glist, vector <bool> blist);

void hangmanImage(int tries);

int main() {

  //variables for players
  string player1;
  char player2;
  int numOfChars;
  int attempts = 6;
  string tbfString;
  bool guessed = false;
  
  vector<char> alphabet{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  vector<bool> goodList(26, false);
  vector<bool> badList(26, false);

  cout <<"\n" << "\n"; // new line
  //Display 
  cout << "Welcome to Hangman!";
  cout <<"\n";
  cout << "Player 1 enter a word for Player 2 to guess!" << endl;


  // ask user for input (word)
  cin >> player1;

  numOfChars = player1.length();

  for(int i = 0; i < numOfChars; i++){
    player1[i] = tolower(player1[i]);  
  }

  cout << "\n"; //new line
  
  for (unsigned int i = 0; i < numOfChars; ++i) {
    tbfString.push_back('_');
  }



  
  while (attempts > 0 && tbfString != player1) {
    guessed = false;
    
    // display hangman
    hangmanImage(attempts);
    
    // display guessed/unguessed letters
    cout << tbfString;

    cout << "\n" << "\n";
    cout <<"PLAYER 2, guess a letter!" << " attempts left: " << attempts << endl;
    cin >> player2;
    player2 = tolower(player2);

    //assign the underscore values to correctly guessed character
    for (int i = 0; i < numOfChars; ++i) {
        if (player2 == player1[i]) {
          guessed = true;
          tbfString[i] = player2;
          // change the vector at player2 letter to true
          int j = 0;
          while (player2 != alphabet.at(j)) {
            ++j;
          }
          goodList.at(j) = true;
        }
    }
    // reduce attempt amount by 1 if the guess was wrong
    if (!guessed) {
        --attempts;
      int j = 0;
      while (player2 != alphabet.at(j)) {
        ++j;
      }
      badList.at(j) = true;
    }

     alphaList(alphabet, goodList, badList);
  }


  if (tbfString == player1) {
    hangmanImage(attempts);
    cout << "\n"; //new line
    cout << tbfString << endl;
    cout << "You guessed the word right!" << endl << endl;
  }
  else {
    hangmanImage(attempts);
    cout << tbfString << endl;
    cout << "The answer was " << player1 << ", better luck next time" << endl << endl;
  }

      
  // print out alphabet (shows available letters to be used) 
cout << "Thank you very much for playing our game and shout out to Kris Miller!!!" << endl;
cout << "Programmed by Anderson Wang, Jaime (Danny) Reyes, and Julian Lopez" << endl;
   
  

  // while (player2 != players1) 

  return 0;
} // main end 

void hangmanImage(int tries) {
  cout << "__________" << endl;
  cout << "| |      |" << endl;
  cout << "| |"; if (tries < 6) {cout << "      o";} cout << endl;
  cout << "| |"; if (tries < 3) {cout << "     /|\\";} else if (tries < 4) {cout << "     /|";} else if (tries < 5) {cout << "      |";} cout << endl;
  cout << "| |"; if (tries < 2 ) {cout << "     /";} if (tries < 1 ) {cout << " \\";} 
 cout << endl;
  cout << "|_|________" << endl;
}


void alphaList(vector<char> list, vector <bool> glist, vector <bool> blist) {
  for(int i = 0; i < list.size(); ++i){
    if(i == list.size() -1){
      if(glist.at(i) == true) {
        cout << "\033[32m" << list.at(i) << "\033[0m" << endl;
      }
      else if(blist.at(i) == true) {
        cout << "\033[31m" << list.at(i) << "\033[0m" << endl;
      }
      else {
        cout << list.at(i) << endl;
      }
    }
    else {
      if(glist.at(i) == true) {
        cout << "\033[32m" << list.at(i) << "\033[0m" << ", ";
      }
      else if(blist.at(i) == true) {
        cout << "\033[31m" << list.at(i) << "\033[0m" << ", ";
      }
      else {
        cout << list.at(i) << ", ";
      }
    }
  }
}