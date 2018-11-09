// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);


// PROTOTYPES for functions used by this demonstration program:
int main( )
{
    ofstream myFile("gofish_results.txt");

    if(myFile.is_open()) {

        //initializing
        int numCards = 7;

        Player p1("Joe");
        Player p2("Jane");

        Deck d;  //create a deck of cards
        d.shuffle();

        dealHand(d, p1, numCards);
        dealHand(d, p2, numCards);
	
	myFile << "Before game starts: " << endl; //showing what cards each player has before game starts
        myFile << p1.getName() <<" has : " << p1.showHand() << endl;
        myFile << p2.getName() <<" has : " << p2.showHand() << endl << endl;

        //gamePlay:
        bool gameOver = false;
        bool tieGame = false;
        Player *currentPlayer = &p1; //pointer to player whose turn it currently is. this will switch every time the player turn switched
        Player *otherPlayer = &p2; //pointer to player whose turn it currently isn't
        Player *winner;


        while (gameOver == false) {

            //first, check to see if game is over
            if ((*currentPlayer).getBookSize() + (*otherPlayer).getBookSize() == 52) {
                gameOver = true;
                if ((*currentPlayer).getBookSize() > (*otherPlayer).getBookSize())
                    winner = currentPlayer;
                else if ((*currentPlayer).getBookSize() < (*otherPlayer).getBookSize())
                    winner = otherPlayer;
                else {
                    tieGame = true;
                }

            } 
            //if game isn't over:
            else {

                //check to see if any pairs
                Card book1;
                Card book2;
                while ((*currentPlayer).checkHandForBook(book1, book2)) {
                    (*currentPlayer).removeCardFromHand(book1);
                    // cout << (*currentPlayer).getName() <<" has : " << (*currentPlayer).showHand() << endl;
                    (*currentPlayer).removeCardFromHand(book2);
                    // cout << (*currentPlayer).getName() <<" has : " << (*currentPlayer).showHand() << endl;
                    (*currentPlayer).bookCards(book1, book2);
                }

                while ((*otherPlayer).checkHandForBook(book1, book2)) {
                    (*otherPlayer).removeCardFromHand(book1);
                    // cout << (*currentPlayer).getName() <<" has : " << (*currentPlayer).showHand() << endl;
                    (*otherPlayer).removeCardFromHand(book2);
                    // cout << (*currentPlayer).getName() <<" has : " << (*currentPlayer).showHand() << endl;
                    (*otherPlayer).bookCards(book1, book2);
                }
                
                //prints out current state of game for each turn:
                myFile << (*currentPlayer).getName() << "'s turn " << endl;
                myFile << p1.getName() << " has : " << p1.showHand() << endl;
                myFile << p1.getName() << "'s book has: " << p1.showBooks() << endl;
                myFile << p2.getName() << " has : " << p2.showHand() << endl;
                myFile << p2.getName() << "'s book has: " << p2.showBooks() << endl;

                //if currentHand is empty, take card from deck and pass turn to next player
                if ((*currentPlayer).getHandSize() == 0 && d.size() != 0) {
                    Card newCard = d.dealCard();
                    (*currentPlayer).addCard(newCard);
                    myFile << (*currentPlayer).getName() << " draws " << newCard.toString() << " from the deck" << endl;

                    if ((currentPlayer) == &p1) {
                        currentPlayer = &p2;
                        otherPlayer = &p1;
                    } else if ((currentPlayer) == &p2) {
                        currentPlayer = &p1;
                        otherPlayer = &p2;
                    }
                } else if ((*currentPlayer).getHandSize() == 0 && d.size() == 0) {
                    myFile << "There are no more cards in the deck, and no more cards in the players' hands" << endl << endl;
                }
                //if currentHand is not empty:
                else {
                    Card currentCard = (*currentPlayer).chooseCardFromHand();
                    myFile << (*currentPlayer).getName() << " asks - Do you have a "
                         << currentCard.rankString(currentCard.getRank()) << "?" << endl;

                    //checks to see if other player has card of same rank

                    //if other player has card of same rank:
                    if ((*otherPlayer).rankInHand(currentCard)) {
                        myFile << (*otherPlayer).getName() << " says - Yes. I have a "
                             << currentCard.rankString(currentCard.getRank()) << "." << endl;

                        //Transfer all cards of that rank to other player
                        while ((*otherPlayer).cardInHand(currentCard)) {
                            Card transferCard = (*otherPlayer).removeCardFromHand(currentCard);
                            (*currentPlayer).addCard(transferCard);
                            myFile << (*currentPlayer).getName() << " books the "
                                 << transferCard.rankString(transferCard.getRank()) << "." << endl;
                        }

                    }

                        //if other player does not have card of same rank, then current payer draws a card and turn switches
                    else {
                        myFile << (*otherPlayer).getName() << " says - Go Fish" << endl;
                        Card goFishCard = d.dealCard();
                        (*currentPlayer).addCard(goFishCard);
                        myFile << (*currentPlayer).getName() << " draws " << goFishCard.toString() << endl;


                        if ((currentPlayer) == &p1) {
                            currentPlayer = &p2;
                            otherPlayer = &p1;
                        } else if ((currentPlayer) == &p2) {
                            currentPlayer = &p1;
                            otherPlayer = &p2;
                        }
                    }
                }


                myFile << endl << endl;


            }

        }

        myFile << "Game Over!" << endl;
	if (tieGame == true) {
            myFile << "Tie Game" << endl;
        } else {
            myFile << (*winner).getName() << " is the winner." << endl;
        }
        myFile.close();
    }

    return EXIT_SUCCESS;

}


//pre-condition: input parameters = Deck d, Player p, and number of cards to deal to player
//post-condition: numCards number of cards from Deck d are added to hand of Player p
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   
