#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<std::string> words = {
    "programming", "computer", "language", "hangman", "challenge"
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::string selectedWord = words[std::rand() % words.size()];
    std::string guessedWord(selectedWord.length(), '_');

    int incorrectGuesses = 0;
    const int maxIncorrectGuesses = 6;

    std::cout << "Welcome to Hangman!" << std::endl;

    while (incorrectGuesses < maxIncorrectGuesses && guessedWord != selectedWord) {
        std::cout << "Word: " << guessedWord << std::endl;
        std::cout << "Guess a letter: ";

        char guess;
        std::cin >> guess;

        bool correctGuess = false;
        for (size_t i = 0; i < selectedWord.length(); ++i) {
            if (selectedWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            ++incorrectGuesses;
            std::cout << "Incorrect guess! You have " << maxIncorrectGuesses - incorrectGuesses << " tries left." << std::endl;
        }
    }

    if (guessedWord == selectedWord) {
        std::cout << "Congratulations! You guessed the word: " << selectedWord << std::endl;
    }
    else {
        std::cout << "Sorry, you're out of tries. The word was: " << selectedWord << std::endl;
    }

    return 0;
}
