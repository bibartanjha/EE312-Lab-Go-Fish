#include <iostream>
#include <cstdlib>
#include <string>
#include "card.h"
#include "deck.h"

//default deck constructor
Deck::Deck()
{
    myIndex = 0;


    int myCardsIndex = 0;

    for (int i = 0; i < 13; i ++)
    {
        myCards [myCardsIndex] = Card ((i+1), Card::spades);
        myCardsIndex ++;
        myCards [myCardsIndex] = Card ((i +1), Card::hearts);
        myCardsIndex++;
        myCards [myCardsIndex] = Card ((i + 1), Card::diamonds);
        myCardsIndex++;
        myCards [myCardsIndex] = Card ((i + 1), Card:: clubs);
        myCardsIndex++;

    }

}

//pre-condition: no parameters passed in, myCards array is unshuffled
//post-condition: each card in myCards array is likely in a different position than it was before
void Deck::shuffle()
{
    int totalCards = size();

    if(totalCards == 0 || totalCards == 1)
    {
        return;
    }

    srand((unsigned)time(0));

    int shuffleLoop = 0;
    for(shuffleLoop = 0; shuffleLoop < totalCards; shuffleLoop++)
    {
        int rand1 = 0;
        int rand2 = 0;

        while(rand1 == rand2)
        {
            rand1 = rand() % totalCards;
            rand2 = rand() % totalCards;
        }
        Card temp = myCards[rand1];
        myCards[rand1] = myCards[rand2];
        myCards[rand2] = temp;
    }



}

//pre-condition: no input parameter
//post-condition: card at myIndex index of myCards is returned, myIndex incremented
Card Deck::dealCard()
{
    if(myIndex < 52){

        Card currentCard = myCards[myIndex];
        myIndex++;
        return currentCard;

    }

}

//pre-condition: no input parameter
//post-condition: returns number of cards left in deck
int Deck::size() const
{
    return SIZE - myIndex;
}

