/* cardMaker.h

Purpose: Has all function prototypes used in cardMaker.c
*/
#include <stdbool.h> //allows use of boolean

bool findNumber(int list[], int num);

int suitNumber(int cardNumber);

void printCard(int cardNumber, char ranks[],int col, char suits[][col]);

void printDeck(int DECK_SIZE,int deck[],
                      char ranks[], int SUIT_COLUMNS,
                      char suits[][SUIT_COLUMNS]);

void shuffledDeck(int deck[], int DECK_SIZE);

int validate(int cardsPerHand, int players, int DECK_SIZE);

void dealCardsOut(int deck[], int cardsPerHand, int players, char ranks[], int SUIT_COLUMNS, char suits[][SUIT_COLUMNS]);

