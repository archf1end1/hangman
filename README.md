# Hangman Game

A classic command-line word-guessing game written in C++ where players try to guess a secret word letter by letter within a limited number of attempts.

## Features

- **Random Word Selection**: Words are randomly chosen from a predefined list
- **Letter-by-Letter Guessing**: Players guess one letter at a time
- **Visual Progress Tracking**: Shows guessed letters in their correct positions
- **Limited Attempts**: Players have 6 incorrect guesses before losing
- **Input Validation**: Ensures only single alphabetic characters are accepted
- **Case Insensitive**: Accepts both uppercase and lowercase letters
- **Replay Functionality**: Option to play multiple rounds
- **Win/Loss Detection**: Clear feedback when game ends

## Requirements

- C++ compiler (g++, clang++, or similar)
- C++11 or later standard (uses `<random>` library features)

## Compilation

To compile the Hangman game, use the following command:

```bash
g++ -o hangman hangman.cpp
```

Or with C++ standard specification:

```bash
g++ -std=c++11 -o hangman hangman.cpp
```

## Usage

1. Run the compiled executable:
   ```bash
   ./hangman
   ```

2. Choose from the menu options:
   - **1**: Start a new game
   - **2**: Exit the program

3. During gameplay:
   - Guess letters one at a time
   - Track your progress with the displayed word pattern
   - You have 6 incorrect guesses before losing

## Game Rules

1. **Objective**: Guess the secret word by suggesting letters
2. **Attempts**: You have 6 incorrect guesses maximum
3. **Input**: Only single alphabetic characters are allowed
4. **Case**: Letters are automatically converted to lowercase
5. **Winning**: Guess all letters in the word before running out of attempts
6. **Losing**: Make 6 incorrect guesses without completing the word

## Word List

The game includes the following words:
- hello
- world
- someone
- paris
- tiger
- lion

## Example Game Session

```
Welcome to HANGMAN GAME
Choose from following options
1).Start the game
2).Exit the game
1
______

Enter your Guess: e
Correct
___e__

Enter your Guess: a
Incorrect, you have 5 chances left
___e__

Enter your Guess: o
Correct
_o_e__

Enter your Guess: m
Correct
_ome__

Enter your Guess: s
Correct
some__

Enter your Guess: n
Correct
someon

Enter your Guess: e
Correct
someone
You Won the Game

Choose from following options
1).Start the game
2).Exit the game
2
Game Ended
```

## Code Structure

### Main Components

- **`main()`**: Program entry point, handles menu system and game loop
- **`startGame()`**: Core game logic, manages guessing attempts and game state
- **`randomWord()`**: Selects a random word from the predefined list
- **`userGuess()`**: Handles user input with validation
- **`correctGuess()`**: Checks if guessed letter exists in the word and updates display
- **`chooseOption()`**: Menu option selection with input validation

### Data Structures

- **Word Storage**: `std::vector<std::string>` for the secret word list
- **Random Generation**: `std::mt19937` and `std::uniform_int_distribution` for random word selection
- **Game State**: String manipulation to track guessed letters and display progress

## Technical Implementation

### Random Word Selection
- Uses modern C++ random number generation (`<random>` library)
- Mersenne Twister engine (`std::mt19937`) for high-quality randomness
- Uniform distribution for fair word selection

### Input Validation
- **Letter Validation**: Ensures input is a single alphabetic character
- **Case Conversion**: Automatically converts to lowercase using `tolower()`
- **Error Handling**: Prompts for re-entry on invalid input
- **Stream Clearing**: Prevents input buffer issues

### Game Logic
- **Progress Display**: Uses underscores to represent unguessed letters
- **Letter Matching**: Searches entire word for multiple occurrences of guessed letter
- **Attempt Tracking**: Counts incorrect guesses separately from correct ones
- **Win/Loss Detection**: Compares current progress with target word

## Input Validation Features

- **Single Character Only**: Rejects multi-character input
- **Alphabetic Only**: Ensures only letters are accepted
- **Automatic Case Handling**: Converts input to lowercase
- **Buffer Management**: Clears input stream on invalid input
- **Continuous Validation**: Loops until valid input is received

## Game Flow

1. **Initialization**: Display welcome message and menu
2. **Word Selection**: Randomly choose word from predefined list
3. **Game Setup**: Initialize display string with underscores
4. **Guessing Loop**: 
   - Accept user letter guess
   - Check if letter exists in word
   - Update display and attempt counters
   - Check win/loss conditions
5. **Game End**: Display result and return to main menu

## Error Handling

- **Invalid Menu Input**: Prompts for valid integer option
- **Invalid Letter Input**: Requires single alphabetic character
- **Input Stream Management**: Clears and ignores problematic input
- **Boundary Checking**: Prevents array out-of-bounds access

## Limitations

- **Fixed Word List**: Limited to 6 predefined words
- **No Duplicate Guess Tracking**: Doesn't prevent repeated letter guesses
- **No Hint System**: No clues or categories provided
- **No Difficulty Levels**: All words treated equally
- **No Score Tracking**: No statistics across multiple games
- **No Custom Words**: Cannot add new words during runtime

## Future Enhancements

Potential improvements could include:
- **Expanded Word Database**: Larger word list or file-based word storage
- **Categories**: Themed word groups (animals, cities, etc.)
- **Difficulty Levels**: Words categorized by length or complexity  
- **Hint System**: Optional clues for difficult words
- **Duplicate Prevention**: Track previously guessed letters
- **Score System**: Points based on word difficulty and attempts used
- **Custom Word Lists**: Allow users to add their own words
- **Visual Hangman**: ASCII art representation of hangman drawing
- **Multiplayer Mode**: Two-player word submission
- **Time Limits**: Add urgency with timed rounds

## Educational Value

This project demonstrates:
- Modern C++ random number generation
- String manipulation and character processing
- Input validation and error handling
- Game state management
- Modular function design
- Menu-driven program architecture
