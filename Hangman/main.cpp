/* 
 * File:   main.cpp
 * Author: Adeola Uthman
 *
 * Created on April 9, 2016, 10:27 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;



class HangmanGame {
    
    //The word that needs to be guessed
    string MYSTERY_WORD;

    //A hint to the user
    string HINT;

    //The part of the word that the user has guessed so far
    string usersWord;
    
    //The letters that have been guessed so far
    string guessedLetters;

    //The amount of wrong guesses and the maximum number of wrong guesses allowed
    int wrong, maxWrong;

    //The amount of right guesses and the maximum number of right guesses needed to win
    int right, maxRight;


    public:
        HangmanGame() {
            MYSTERY_WORD = "Computer Science";
            HINT = "Study of systems, theory, AI, software, hardware, etc.";
            usersWord = "";
            guessedLetters = "";
            wrong = 0;
            maxWrong = 10;
            right = 0;
        }
        
        /* Starts the hangman game. */
        void BeginGame() {
            //Loop through to set up the user's word and the maximum right answers needed
            for(char c : MYSTERY_WORD) {
                if(c == ' ') {
                    usersWord += " ";
                } else {
                    usersWord += "_";
                    maxRight++;
                }
            }
            
            PrintUnderscores();
            PrintInfo();
            GuessAgain();
            
        } //End of method

    private:
        /* Prints of the underscores for what the user has guessed so far. */
        void PrintUnderscores() {
            for(char c : usersWord) {
                cout << c << " ";
            }
        }

        /* Prints out important info for the player. */
        void PrintInfo() {
            cout << "\n";
            cout << "Hint: " << HINT << "\n";
            cout << "Guessed: " << guessedLetters << "\n";
            cout << "Wrong: " << wrong;
        }

        /* Prompts the user for a new guess. */
        void GuessAgain() {
            cout << "\n";
            cout << "Guess a letter: ";
            char guess; cin >> guess;
            GuessLetter(guess);
        }
        
        
        /* Returns the number of times guess is found in the mystery word. */
        int GetOccurances(char guess) {
            int times = 0;
            for(char c : MYSTERY_WORD) {
                if(guess == c) {
                    times++;
                }
            }
            return times;
        }
        
        /* Checks if the guess is a letter. */
        bool IsLetter(char guess) {
            //Vectors are just like Lists; use push_back to add to the end of the vector
            vector<char> letters = vector<char>();
            //Lowercase
            letters.push_back('a');letters.push_back('b');letters.push_back('c');
            letters.push_back('d');letters.push_back('e');letters.push_back('f');
            letters.push_back('g');letters.push_back('h');letters.push_back('i');
            letters.push_back('j');letters.push_back('k');letters.push_back('l');
            letters.push_back('m');letters.push_back('n');letters.push_back('o');
            letters.push_back('p');letters.push_back('q');letters.push_back('r');
            letters.push_back('s');letters.push_back('t');letters.push_back('u');
            letters.push_back('v');letters.push_back('w');letters.push_back('x');
            letters.push_back('y');letters.push_back('z');
            //Uppercase
            letters.push_back('A');letters.push_back('B');letters.push_back('C');
            letters.push_back('D');letters.push_back('E');letters.push_back('F');
            letters.push_back('G');letters.push_back('H');letters.push_back('I');
            letters.push_back('J');letters.push_back('K');letters.push_back('L');
            letters.push_back('M');letters.push_back('N');letters.push_back('O');
            letters.push_back('P');letters.push_back('Q');letters.push_back('R');
            letters.push_back('S');letters.push_back('T');letters.push_back('U');
            letters.push_back('V');letters.push_back('W');letters.push_back('X');
            letters.push_back('Y');letters.push_back('Z');
            
            if(find(letters.begin(), letters.end(), guess) != letters.end()) {
                return true;
            }
            
            return false;
        }
        
        /* Handles the guessing for the game. */
        void GuessLetter(char guess) {
                
            //If it is a letter
            if(IsLetter(guess)) {

                size_t found = MYSTERY_WORD.find(guess);

                //If it's a correct guess
                if(found != string::npos) {
                    //Give correct message
                    cout << "\n";
                    cout << "Correct!";
                    cout << "\n";

                    //Change user's word


                    //Add to the number right
                    right += GetOccurances(guess);

                    //Check for next move
                    if(right < maxRight) {
                        PrintUnderscores();
                        PrintInfo();
                        GuessAgain();
                    } else {
                        cout << "\n";
                        cout << "You guessed the word correctly! Word: " << MYSTERY_WORD;
                        cout << "\n";
                    }

                //A wrong guess
                } else {

                    //Give incorrect message
                    cout << "\n";
                    cout << "Incorrect!";
                    cout << "\n";

                    //Change user's word


                    //Add to the number wrong
                    wrong++;

                    //Check for next move
                    if(wrong < maxWrong) {
                        PrintUnderscores();
                        PrintInfo();
                        GuessAgain();
                    } else {
                        cout << "\n";
                        cout << "Sorry, you ran out of tries... The word was " << MYSTERY_WORD;
                        cout << "\n";
                    }
                }

            //If the guess is not a letter
            } else {
                cout << "\n";
                cout << "You must enter a letter.";
                cout << "\n";

                PrintUnderscores();
                PrintInfo();
                GuessAgain();
            }
        }
    
  

    
    
};


int main(int argc, char** argv) {
    cout << "Welcome! Are you ready to play Hangman in C++?\n\n";
    
    HangmanGame hg = HangmanGame();
    hg.BeginGame();
    
    
    return 0;
}

