//Project No: 6th
//Project Name: Hangman Game
//Author: Archf1end1

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <limits>

std::string randomWord(std::mt19937&, std::uniform_int_distribution<>&, const std::vector<std::string>&);
char userGuess();
int chooseOption();
void startGame(std::mt19937&, std::uniform_int_distribution<>&, const std::vector<std::string>&);
bool correctGuess(const std::string&, std::string&, const char&);


int main() {

  const std::vector<std::string> secretWord = {"hello", "world", "someone", "paris", "tiger", "lion"};

  std::cout << "Welcome to HANGMAN GAME\n";

  int listLen = secretWord.size() - 1;
  std::mt19937 eng(std::random_device{}());
  std::uniform_int_distribution<> dist(0, listLen);

  int option {};
  bool conti = true;
  while(conti) {
    option = chooseOption();
    switch (option) {
      case 1:
        startGame(eng, dist, secretWord);
        break;
      case 2:
        std::cout << "Game Ended\n";
        conti = false;
        break;
      default:
        std::cout << "Invalid choice\n";
        break;
    }
  }

  return 0;

}


std::string randomWord(std::mt19937& eng, std::uniform_int_distribution<>& dist, const std::vector<std::string>& secretWord) {

  int randNum = dist(eng);

  return secretWord.at(randNum);

}

char userGuess() {
  std::string input;
  while(true) {
    std::cout << "Enter your Guess: ";
    std::cin >> input;

    if(input.length() == 1 && std::isalpha(input[0])) {
      return tolower(input[0]);
    } else {
      std::cout << "Invalid input. Please enter a single letter.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

int chooseOption() {

  int option {};
  std::cout << "Choose from following options\n";
  std::cout << "1).Start the game\n";
  std::cout << "2).Exit the game\n";
  while (!(std::cin >> option)) {
    std::cout << "Enter integer options\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return option;
}

void startGame(std::mt19937& eng, std::uniform_int_distribution<>& dist, const std::vector<std::string>& secretWord) {

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string currentWord = randomWord(eng, dist, secretWord);

  int chances = 5;
  std::string displayedWord {};
  for(int i = 0; i < currentWord.size(); i++) {
    displayedWord.append("_");
  }
  std::cout << displayedWord << '\n';

  char letter {};
  int incorrectGuess = 0;
  const int MAX_INCORRECT_GUESS = 6;
  while (true) { 
    letter = userGuess();
    if(correctGuess(currentWord, displayedWord, letter)) {
      std::cout << "Correct\n";
    } else {
      incorrectGuess++;
      std::cout << "Incorrect, you have " << MAX_INCORRECT_GUESS - incorrectGuess << " chances left\n";
    }

    if(displayedWord == currentWord) {
      std::cout << "You Won the Game\n";
      return;
    } else if (incorrectGuess >= MAX_INCORRECT_GUESS && displayedWord != currentWord) {
      std::cout << "Sorry you lost the game\n";
      std::cout << "The correct word was: " << currentWord << "\n";
      return;
    }
    std::cout << displayedWord << "\n";
  }
}

bool correctGuess(const std::string& currentWord, std::string& displayedWord, const char& letter) {
  bool found = false;
  for(int i = 0; i < displayedWord.size(); i++) {
    if(letter == currentWord[i]) {
      displayedWord[i] = letter;
      found = true;
    }
  }
  return found;
}
