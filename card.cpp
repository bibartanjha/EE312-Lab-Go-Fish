#include <iostream>
#include <string>
#include <cstdlib>

#include "card.h"


using namespace std;

//default card constructor
Card::Card()
{
    myRank = 'A';
    mySuit = spades;

}

//card constructor
Card::Card(int rank, Suit s)
{
    myRank = rank;
    mySuit = s;
}

//return string that represents card rank and suit
string Card::toString() const
{
    return rankString(myRank) + suitString(mySuit);
}

//returns true is card has same suit as card c
bool Card::sameSuitAs(const Card &c) const
{
    return(suitString(mySuit) == suitString(c.mySuit));
}

//returns rank of card
int Card::getRank() const
{
    return myRank;
}

//returns string representing suit of card
string Card::suitString(Card::Suit s) const
{
    string ans = "";
    if(s == spades){
        ans = "s";
    }
    if(s == hearts){
        ans = "h";
    }
    if(s == diamonds){
        ans = "d";
    }
    if(s == clubs){
        ans = "c";
    }
    return ans;
}

//returns string representing rank of card
string Card::rankString(int r) const
{
    string ans = "";
    if(r == 1){
        ans = "A";
    }
    if(r == 2){
        ans = "2";
    }
    if(r == 3){
        ans = "3";
    }
    if(r == 4){
        ans = "4";
    }
    if(r == 5){
        ans = "5";
    }
    if(r == 6){
        ans = "6";
    }
    if(r == 7){
        ans = "7";
    }
    if(r == 8){
        ans = "8";
    }
    if(r == 9){
        ans = "9";
    }
    if(r == 10){
        ans = "10";
    }
    if(r == 11){
        ans = "J";
    }
    if(r == 12){
        ans = "Q";
    }
    if(r == 13){
        ans = "K";
    }
    return ans;
}

//returns true if card has same rank as rhs card
bool Card::operator==(const Card &rhs) const
{
    return((getRank() == rhs.getRank()));
}

//returns true if card does not have same rank as rhs card
bool Card::operator!=(const Card &rhs) const
{
    return((getRank() != rhs.getRank()));

}

ostream& operator << (ostream& out, const Card& c)
{
    out << c.toString() << endl;
}

