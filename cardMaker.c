/* cardMaker.c
Purpose: Contains methods to print card symbols, 
        shuffle the deck, and deal the cards out to the
        players. Also validates command line input.
*/
#include <stdio.h>  //printf
#include <stdlib.h> //to use random generator
#include <time.h>  //for using time for the seed
#include "cardMaker.h" //contains prototypes 
//#include "cards.h" //contains function for printing card correspoinding to card NUMBER
#include <stdbool.h> //allows use of boolean

#define SIZE 13 //size of suit arrays; there are this many numbers with each suit
#define CARD '|' //symbol to print in between each card
#define FIRST_SPACE 6  
#define SECOND_SPACE 12
#define MAX 13  //for validation of command line input
#define MIN 1


/* Function: findNumber
   --------------------
 purpose:  To go through the array of numbers that pertain to a 
           suit and check if the given number passed in is located
           inside that array.

 parameters: The array of suits, and the number we are looking for

 returns: false if number not found in array,
          true if it is found */ 
bool findNumber(int list[], int num)
{
  bool found = false;
  int index = 0;

  for(index = 0; index < SIZE; index++)
  {
    if(list[index] == num)
    {
      found = true;
    }
  }
  return found;
}

/* Function: suitNumber
   --------------------
 purpose:  Used in the printCard function.
           To go through the array of numbers that pertain to a 
           suit and check if the given number passed in is located
           inside that array.

           Example: the diamondSuit array is passed in. 
          It contains all numbers from 1 to 52 that would have
          a Diamond suit to print next to it. If the number we
          passed in is found in the array, then print the 
          diamon suit symbol.

 parameters: The array of suits, and the number we are looking for

 returns: false if number not found in array,
          true if it is found */ 
int suitNumber(int cardNumber)
{
  enum suits { HEART = 0, DIAMOND = 1, CLUB = 2, SPADE = 3};
  int suitNum = HEART; //default is the heart suit 

  int diamondNumbers[] = {2,6,10,14,18,22,26,30,34,38,42,46,50};
  int clubNumbers[]    = {3,7,11,15,19,23,27,31,35,39,43,47,51};
  int spadeNumbers[]   = {4,8,12,16,20,24,28,32,36,40,44,48,52};

  if( findNumber(diamondNumbers,cardNumber) )
  {
    suitNum = DIAMOND; 
  }
  else if( findNumber(clubNumbers,cardNumber) )
  {
    suitNum = CLUB; 
  }
  else if( findNumber(spadeNumbers,cardNumber) )
  {
    suitNum = SPADE; 
  }
  
  return suitNum;
}

/* Function: printCard
   --------------------
 purpose:   Each card number has a corresponding rank.
            Checks the card number passed in and assigns
            a rank character to it and prints it out.

            Calls the suitNumber function to also print the 
            suit symbol.

            Example: The numbers 1 to 4 all have the same Rank,
            which is A. If the card number is in that range, print
            the rank A.

 parameters: A card number, the ranks array,
            column size for suits array, and the suits array

 returns: Nothing */ 
void printCard(int cardNumber, char ranks[],int col, char suits[][col])
{
  int rankNum = 0, suitNum = 0;

  if(cardNumber >=1 && cardNumber <= 4)
  {
    rankNum = 0;
  }
  else if(cardNumber >=5 && cardNumber <= 8)
  {
      rankNum = 1;
  }
  else if(cardNumber >= 9 && cardNumber <= 12)
  {
    rankNum = 2;
  }
  else if(cardNumber >= 13 && cardNumber <= 16)
  {
    rankNum = 3;
  }
  else if(cardNumber >= 17 && cardNumber <= 20)
  {
    rankNum = 4;
  }
  else if(cardNumber >= 21 && cardNumber <= 24)
  {
    rankNum = 5;
  }
  else if(cardNumber >= 25 && cardNumber <= 28)
  {
    rankNum = 6;
  }
  else if(cardNumber >= 29 && cardNumber <= 32)
  {
    rankNum = 7;
  }
  else if(cardNumber >= 33 && cardNumber <= 36)
  {
    rankNum = 8;
  }
  else if(cardNumber >= 37 && cardNumber <= 40)
  {
    rankNum = 9;
  }
  else if(cardNumber >= 41 && cardNumber <= 44)
  {
    rankNum = 10;
  }
  else if(cardNumber >= 45 && cardNumber <= 48)
  {
    rankNum = 11;
  }
  else if(cardNumber >= 49 && cardNumber <= 52)
  {
    rankNum = 12;
  }

  suitNum = suitNumber(cardNumber); //find the suit number too
  printf("%3.c%c.%s%c",CARD, ranks[rankNum], suits + suitNum,CARD); //display the resulting card
}

/* Function: printDeck
   --------------------
 purpose: Print the integer deck and print out the corresponding
          rank and suit for that number. 

          Calls the printCard method which is what associates
          the number with a particular card. For example,
          the number 1 is for the first card in an orderd deck, 
          4 of hearts, and number 52 is the last card, K Spade.

       -----------SPACING OF DECK---------
        Every 6 prints, new line
        Every 12 prints, 2 new lines 

 parameters: size of deck, deck of integers, rank characters,
             size of suit 2d array column, and suit 2d array

 returns: Nothing       */ 
void printDeck(int DECK_SIZE,int deck[],
                      char ranks[], int SUIT_COLUMNS,
                      char suits[][SUIT_COLUMNS])
{
  int colCount = 0,
      count    = 0; 

  for(count = 0; count < DECK_SIZE; count++)
  {
    printCard(deck[count],ranks,SUIT_COLUMNS,suits); //print the corresponding card to the number on the deck

    colCount++;
    if(colCount == FIRST_SPACE) 
    {
      printf("\n");
    }
    else if(colCount == SECOND_SPACE)
    {
      printf("\n\n");
      colCount= 0; //reset
    }
  }
}

/* Function: findNumber
   --------------------
 purpose:  To go through the array of numbers that pertain to a 
           suit and check if the given number passed in is located
           inside that array.

 parameters: The array of suits, and the number we are looking for

 returns: false if number not found in array,
          true if it is found */ 
void shuffledDeck(int deck[], int DECK_SIZE)
{
  srand ( time(0) ); //seed to make random every run
  int random = 0,//contains the randomly generated number
      temp = 0,  //temporarily holds value for swap
      index = 0; //iterating through the deck backwards

  for(index = (DECK_SIZE - 1); index >= 0; index--)
  {
    random = rand() % DECK_SIZE; //generate random int from 0 to deck size - 1

    //perform the swap
    temp = deck[index];
    deck[index] = deck[random];
    deck[random] = temp;
  }
}

/* Function: validate
   --------------------
 purpose:  Checks to see if the input for the cards per hand
           and players from command line is between the MIN 
           and MAX. Also checks to see if it is possible to
           deal out all 52 cards by doing the following formula:
                  cards per hand * number of players
           All 3 of these error checks must be OK before proceeding
           with the regular program.

 parameters: Command line input for card per hand,
             the amount of players,
             and the size of the deck.

 returns: -1 if the input is NOT valid, remains 1 if it is */ 
int validate(int cardsPerHand, int players, int DECK_SIZE)
{
  int isValid = 1,  //default is valid input unless changed
      cardsOut = 0; 

  cardsOut = cardsPerHand * players;

  printf("\n Cards per hand: %d", cardsPerHand);
  printf("\n Players       : %d", players);

  //the 3 types of errors: possible for all 3 to happen
  if( cardsPerHand < MIN || cardsPerHand > MAX) 
  {
    isValid = -1;
    printf(" \nPlease enter a number from %d to %d for the cards per hand \n",
           MIN, MAX);
  }
  if( players < MIN || players > MAX) 
  {
    isValid = -1;
    printf("\nPlease enter a number from %d to %d for the players\n",
           MIN, MAX);
  }
  if( cardsOut > DECK_SIZE)
  {
    isValid = -1;
    printf("\nLimited deck of 52 cards only. Try again\n");
  }

  return isValid;
}

/* Function: dealCardsOut
   --------------------
 purpose:    Prints out the players and gives them cards
             from a shuffled deck. 

             When printing out card, it calls the printCard
             function to print the corresponding rank and suit
             for the current card being dealt to the player.

 parameters: The deck, cards for each player's hand, number of
             players, the rank characters, the number of columns for
             the suit array, and the suits array

 returns: Nothing */ 
void dealCardsOut(int deck[], int cardsPerHand, int players,
                  char ranks[], int SUIT_COLUMNS,
                  char suits[][SUIT_COLUMNS])
{
  int cardCount = 0, //index for card that has been given out to a player
      playerCount = 0,//current player counter
      cardGiven = 0;  //amount of cards to be given to each player

  printf("\n\n \t\t Dealing out the cards! \n");
  printf(" \t ------------------------------------ \n");

  for(playerCount = 1; playerCount <= players; playerCount++)
  {
     printf("\n Player {%d}: ",playerCount);

     //give each player the amount of cards specified by cardsPerHand
     for(cardGiven = 0; cardGiven < cardsPerHand; cardGiven++)
     {
       printCard(deck[cardCount],ranks,SUIT_COLUMNS,suits); 
       cardCount++; //print the corresponding symbols of ranks and suits
     }
     printf("\n");
  }
}


