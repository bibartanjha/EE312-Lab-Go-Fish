#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

#include "deck.h"
#include "card.h"
#include "player.h"


using namespace std;

//default player constructor
Player::Player ()
{
    myName = "";
}

//pre-condition: input parameter = new Card c to add to player's hand
//post-condition: Card c added to player's hand (myHand)
void Player::addCard(Card c)
{
    myHand.push_back(c);
}

//pre-condition: input parameters = two Cards with same rank
//post-condition: Cards c1 and c2 added to book (myBook)
void Player::bookCards(Card c1, Card c2)
{
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//pre-condition: input parameters = pointers to two cards
//post-condition: returns true if myHand contains a pair. pointers (the input parameters) now point to the two cards that are a pair 
bool Player::checkHandForBook(Card &c1, Card &c2)
{
    vector<Card>::iterator iter;
    vector<Card>::iterator iter2;
    for (iter = myHand.begin(); iter != myHand.end(); iter ++)
    {
        for (iter2 = iter + 1; iter2 != myHand.end(); iter2 ++)
        {
            if (*(iter) == *(iter2))
            {
                c1 = (*iter);
                c2 = (*iter2);
                return true;

            }
        }
    }

    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//pre-condition: Card c 
//post-condition: returns true if myHand contains Card of same rank as Card c
bool Player::rankInHand(Card c) const
{
    vector<Card>::const_iterator iter;
    for (iter = myHand.begin(); iter != myHand.end(); iter ++)
    {
        if (*iter == c)
            return true;
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
//post-condition: returns random Card from myHand
Card Player::chooseCardFromHand() const
{
    int size = getHandSize ();
    int randomCard = rand() % size;
    vector<Card>::const_iterator iter = myHand.begin();

    for (int i = 0; i < randomCard; i ++)
    {
        iter ++;
    }

    return (*iter);

}

//Does the player have the card c in her hand?
//pre-condition: Card c
//post-condition: returns true if myHand contains card of same rank as Card c
bool Player::cardInHand(Card c) const
{
    vector<Card>::const_iterator iter;
    for (iter = myHand.begin(); iter != myHand.end(); iter ++)
    {
        if ((*iter) == c)
            return true;
    }

    return false;

}

//Remove the card c from the hand and return it to the caller
//pre-condition: input parameter = Card c
//post-condition: first card in myHand that has same rank as Card c is removed from myHand and is returned
Card Player::removeCardFromHand(Card c)
{
    vector<Card>::iterator iter;
    for (iter = myHand.begin(); iter != myHand.end(); iter ++)
    {
        if ((*iter) == c) {
            Card temp = *iter;
            myHand.erase(iter);
            return temp;
        }
    }
}

//post-condition: string representing all cards in myHand is returned
string Player::showHand() const
{
    string totalHand = "";
    vector<Card>::const_iterator iter;
    for (iter = myHand.begin (); iter != myHand.end(); iter ++)
    {
        totalHand = totalHand + (*iter).toString() + " ";
    }

    return totalHand;
}

//post-condition: string representing all cards in myBook is returned
string Player::showBooks() const
{
    string totalBook = "";
    vector<Card>::const_iterator iter;
    for (iter = myBook.begin (); iter != myBook.end(); iter ++)
    {
        totalBook = totalBook + (*iter).toString() + " ";
    }

    return totalBook;
}

//post-condition: number of cards in myHand is returned
int Player::getHandSize() const
{
    int size = 0;
    vector<Card>::const_iterator iter;
    for (iter = myHand.begin(); iter != myHand.end(); iter ++)
    {
        size ++;
    }
    return size;
}

//post-condition: number of cards in myBook is returned
int Player::getBookSize() const
{
    int size = 0;
    vector<Card>::const_iterator iter;
    for (iter = myBook.begin(); iter != myBook.end(); iter ++)
    {
        size ++;
    }
    return size;
}


