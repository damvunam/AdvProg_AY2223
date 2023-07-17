#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

int generateRandomNumber();
int getPlayerGuess();
void printAnswer(int guess, int secretNumber);
bool playAgain();
void guessIt();

int main(){
  do {
    guessIt();
  } while (playAgain());
  
  return 0;
}

void guessIt(){
    srand(time(0));
  int secretNumber = generateRandomNumber();
  int guess;
  // cout << generateRandomNumber();

  do {
    guess = getPlayerGuess();
    printAnswer(guess, secretNumber);
  } while (guess != secretNumber);
}

bool playAgain(){
  cout << "Do you want to play again? (Yes/No)" << endl;
  string answer;
  cin >> answer;
  return answer == "Yes";
}

int generateRandomNumber(){
  return rand() % 100 + 1;
}

int getPlayerGuess(){
  int guess;
  cout << "Enter your guess from 1 to 100 " << endl;
  cin >> guess;
  return guess;
}

void printAnswer(int guess, int secretNumber){
  if(guess > secretNumber){
    cout << "Your number is higher" << endl;
  } else if (guess < secretNumber){
    cout << "Your number is lower" << endl;
  } else {
    cout << "Congratulation! You win" << endl;
  }
}
