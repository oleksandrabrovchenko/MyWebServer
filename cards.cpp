#include <stdio.h>
#include <string.h>
#include <iostream>

#include "cards.h"

using namespace std;

const char* SuitMass [] = {"\"spade\"", "\"cross\"", "\"diamonds\"", "\"hearts\""};
const char* ValueMass [] = {"\"7\"", "\"8\"", "\"9\"","\"10\"","\"jack\"","\"lady\"","\"king\"","\"ace\""};

Card::Card(CardValue card_value, CardSuit card_suit)
{
    value = card_value;
    suit = card_suit;
} 

void Card::Dump()
{
    cout << "    { \"value\": " << ValueMass [value]  << ", \"suit\": " << SuitMass [suit]  << " }";
}

const char* Card::getAsString()
{
    sprintf (buffer, "    { \"value\": %s, \"suit\": %s  }", ValueMass [value], SuitMass [suit]);
    return &buffer[0];
}

ostream &operator<<(ostream &os, Card const &card) 
{ 
    return os << "{ \"value\": " << ValueMass [card.value]  << ", \"suit\": " << SuitMass [card.suit]  << " }";
   //   {"value": "card.value", "suit": "card.suit"} 
}

Pack::Pack()  //конструктор, имя идентично имени класса, возвращаемое значение не задавать, только в public
{
    for (int val=0; val<8; val=val+1)
    {
	Card* c;
	c = new Card((CardValue)val, spade);
	my_deque.push_back(c);
	c = new Card((CardValue)val, cross);
	my_deque.push_back(c);
	c = new Card((CardValue)val, diamonds);
	my_deque.push_back(c);
	c = new Card((CardValue)val, hearts);
	my_deque.push_back(c);
    }
}

// Destructor. We need to delete created cards when the pack is being destroyed.
Pack::~Pack()
{
    for (int i=0; i<my_deque.size(); i++)
    {
	Card* card = my_deque[i];
	delete card;
    }
}

Card* Pack::get()
{ 
	printf ("Cards are %d\n", my_deque.size());
	Card* card = my_deque.front();
	my_deque.pop_back();
	return card;
}

void Pack::shuffle()
{
    srand( time(0) );

    for (int val=0; val<50; val=val+1)
    {
	int x1, x2;
	x1 = rand() % 32;
	x2 = rand() % 32;
	Card* card = my_deque[x1];
	my_deque[x1] = my_deque[x2];
	my_deque[x2] = card;
    }
}


void Pack::Dump()
{
    cout << "{ \"Pack\": [" << endl;

    for (int i=0; i<my_deque.size(); i++)
    {
	Card* card = my_deque[i];
	card->Dump();
        if (i!=31) cout << ",";
	cout << endl;
    }

    cout << "  ]" << endl << "}" << endl;
}

const char* Pack::getAsString()
{
    char *pBuffer = &buffer[0];

    strncpy(pBuffer,  "{ \"Pack\": [\n", 12);
    pBuffer += 12;

    for (int i=0; i<my_deque.size(); i++)
    {
	Card* card = my_deque[i];
	strcpy(pBuffer, card->getAsString());
	pBuffer += strlen(card->getAsString());
        if (i != 31) *pBuffer++ = ',';
	*pBuffer++ = '\n';
    }

    strcpy(pBuffer, "  ]\n}\n");

    return &buffer[0];
}
