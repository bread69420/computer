#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NUM_OF_WORDS 100

bool processGuess(const char *theAnswer, const char *theGuess)
{
  // the clue
  char clue[7] = {'-', '-', '-', '-', '-', '-', '\0'};
  // a set of flags indicating if that letter in the answer is used as clue
  bool answerFlags[6] = {false, false, false, false, false, false};

  // first pass, look for exact matches
  for (int i = 0; i < 6; i++)
  {
    if (theGuess[i] == theAnswer[i])
    {
      clue[i] = 'G';
      answerFlags[i] = true;
    }
  }

  // second pass, look for there but elsewhere
  for (int i = 0; i < 6; i++)
  {
    if (clue[i] == '-')
    { // means no exact match from first pass
      for (int j = 0; j < 6; j++)
      {
        if (theGuess[i] == theAnswer[j] && !answerFlags[j])
        {
          // a match at another position and has not been used as clue
          clue[i] = 'Y';
          answerFlags[j] = true;
          break; // end this j-loop because we don't want multiple clues from the same letter
        }
      }
    }
  }

  printf("%s\n", clue);
  return strcmp(clue, "GGGGGG") == 0; // if match strcmp returns 0
}

int main()
{

  // load the words
  char **wordsList = calloc(MAX_NUM_OF_WORDS, sizeof(char *));
  int wordCount = 0;
  char *fiveLetterWord = malloc(6 * sizeof(char));
  FILE *eqnFile = fopen("words.txt", "r");
  while (fscanf(eqnFile, "%s", fiveLetterWord) != EOF && wordCount < MAX_NUM_OF_WORDS)
  {
    wordsList[wordCount] = fiveLetterWord;
    wordCount++;
    fiveLetterWord = malloc(6 * sizeof(char));
  }
  fclose(eqnFile);

  // start the game
  // pick a word randomly
  srand(time(NULL));
  char *answer = wordsList[rand() % wordCount];

  // do the game loop
  int num_of_guesses = 0;
  bool guessed_correctly = false;
  char *guess = malloc(6 * sizeof(char));

  while (num_of_guesses < 6 && !guessed_correctly)
  {
    // get guess from player
    if (num_of_guesses == 0)
    {
      printf("Welcome to Nerdle! This is a guessing game where you have to guess a random equation of 6 places to win. You have 6 tries.\n");
      printf("The equation board is:");
      printf("------");
      printf("How to play:\n");
      printf("1. Input an equation of 6 places (symbols included). For example, 5x2=10.\n");
      printf("- Note: If the RHS is a digit number, type 0 at its tenths place. For example, 4+4=08.\n");
      printf("- The computer will provide hints to the correct equation.\n");
      printf("Let's start! Guess an equation of 6 places (symbols included) and press enter: \n");
    }
    else if (num_of_guesses != 0)
    {
      printf("Wrong equation. Guess the equation again and press enter: \n");
    }
    else if (num_of_guesses != 0 && num_of_guesses == 4)
    {
      printf("Stuck? There is always a = in the equation. Now you have 5 slots to consider.");
      printf("Let's guess again: \n");
    }
    scanf("%s", guess);
    printf("You have guessed %s\n", guess);
    num_of_guesses += 1;

    // process guess
    guessed_correctly = processGuess(answer, guess);
  }

  // display end of game message
  if (guessed_correctly)
  {
    printf("Congratulations! You guessed the correct equation in %d times!\n", num_of_guesses);
  }
  else
  {
    printf("You have used up yours guesses. Game over! The correct equation is %s\n", answer);
  }

  for (int i = 0; i < wordCount; i++)
  {
    free(wordsList[i]);
  }
  free(wordsList);
  free(fiveLetterWord);
  free(guess);

  return 0;
}