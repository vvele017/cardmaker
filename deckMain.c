/*    Source code:  deckMain.c
           Author:  Vanessa Velez-Santos
       Student ID:  4129302  
       Assignment:  Program #3 Card Decks
   
            Course:  COP 4338 - Programming III  
           Section:  U03 
        Instructor:  William Feild  
          Due Date:  October 11, at the beginning of class
 
 	I hereby certify that this collective work is my own
 	and none of it is the work of any other person or entity.
 	______________________________________ [Signature]
   
         Language:  C
      Compile/Run:  
      With makefile:         Not completed              

      WITHOUT makefile use:  gcc deckMain.c cardMaker.c   
                             ./a.out 5 5
                             where 5 and 5 can be any integer to test
+-----------------------------------------------------------------------------  
  
  Description:  Program will show an ordered deck of 52 cards
                and then shuffle the deck randomly. Each run will
                show a new shuffled deck while the ordered one remains
                the same. 

                After printing out the decks, deal the shuffled deck out to
                the players and deal only the amount that is specified by the 
                command line input.

                There are 3 errors to check for when looking at command line
                1. The cards to deal out to each player has to be from 1 - 13
                2. The number of players to deal cards to has to be from 1 - 13
                3. The deck is only 52 cards. Cannot deal out more cards than what
                we have.

                Display all players and the cards they have been dealt from the top
                of the shuffled deck.

  Process:     Check for the command line input first.
               Do not run program if the input is not valid.

               If the input IS valid, proceed to print out the deck. 
               Deck is treated as an integer array containing number 1 to 52.
               Then, a function dedicated to printing corresponding Rank and Suit
               for each number is used to print a "card". 

               For example:
               1 is A Heart, 2 is A Diamond, 3 is A Club, 4 is A Spade, 5 is 2 Heart-

               The deck is then shuffled by randomly generating a number, and
               starting to swap numbers beginning from the END of the array until
               we reach index 0. 

               After the swapping is done, print the array again and call the 
               printCard function to display corresponding symbols.

               Print out the number of players and print out a card for each 
               player from the first index and forward of the shuffled array. 
               This happens until it displays all players specified by the command
               line input.  

   Required Features Not Included:  
                1. No makefile included
                2. Same array is used for deck instead of 
                having seperate arrays (no seperate entities)

    Known Bugs: None
*/
#include <stdio.h>
#include <stdlib.h>   //for atoi function to convert input from string to int
#include "cardMaker.h" //contains all shuffling and printing methods for cards

#define NO_ERROR 0
#define SUIT_SIZE 4    //total number of suits in a deck
#define SUIT_COLUMNS 12 //number of columns 
#define DECK_SIZE 52   //number of cards in the deck
#define ARG_SIZE 3 //size of argument needs to be 3 for 2 inputs

/*  Suit symbols
---------------------
UTF8 encoding used, based of source link code found online.
Source Link: https://stackoverflow.com/questions/
            27133508/how-to-print-spades-hearts-diamonds-etc-
            in-c-and-linux
*/
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

int main(int argc, char *argv[]) //for command line input
{
  if(argc == ARG_SIZE)//required 2 inputs for program
  {
    int numberOfCards = atoi(argv[1]);
    int numberOfHands = atoi(argv[2]);

    int inputValid = validate(numberOfCards,numberOfHands, DECK_SIZE); 
    if(inputValid != -1) //if the input is OK proceed with the program
    {   
      //deck of 52 cards by number
      int cards[] = { 1,  2, 3, 4, 5, 6, 7, 8, 9,10,
                      11,12,13,14,15,16,17,18,19,20, 
                      21,22,23,24,25,26,27,28,29,30,
                      31,32,33,34,35,36,37,38,39,40,
                      41,42,43,44,45,46,47,48,49,50, 
                      51,52 };

      //array to store symbols for suits
      char suits[SUIT_SIZE][SUIT_COLUMNS] = {{HEART},
                                            {DIAMOND},
                                            {CLUB},
                                            {SPADE} };
      //array to store rank characters
      char ranks[] = {'A','2','3','4','5','6',
                      '7','8','9','T','J','Q','K'};

      //function calls starts here
      printf("\n\n Original deck: \n");
      printDeck(DECK_SIZE, cards, ranks, SUIT_COLUMNS, suits);
      shuffledDeck(cards, DECK_SIZE);
      printf("\n\n Shuffled: \n");
      printDeck(DECK_SIZE, cards, ranks, SUIT_COLUMNS, suits);
      dealCardsOut(cards, numberOfCards, numberOfHands, ranks, SUIT_COLUMNS, suits);
      //function calls ends here
    }
  }
  else //incorrect number of arguments recieved
  {
    printf("\nExiting. Either no input or more than %d arguments recieved\n", ARG_SIZE - 1);
  }
  return NO_ERROR;
}



