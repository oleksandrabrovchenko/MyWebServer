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

//конструктор, имя идентично имени класса, возвращаемое значение не задавать, только в public
Pack::Pack() : 
	c1 (v7, spade),
	c2 (v8, spade),
	c3 (v9, spade),
	c4 (v10, spade),
	c5 (jack, spade),
	c6 (lady, spade),
	c7 (king, spade),
	c8 (ace, spade),
	c9 (v7, cross),
	c10 (v8, cross),
	c11 (v9, cross),
	c12 (v10, cross),
	c13 (jack, cross),
	c14 (lady, cross),
	c15 (king, cross),
	c16 (ace, cross),
	c17 (v7, diamonds),
	c18 (v8, diamonds),
	c19 (v9, diamonds),
	c20 (v10, diamonds),
	c21 (jack, diamonds),
	c22 (lady, diamonds),
	c23 (king, diamonds),
	c24 (ace, diamonds),
	c25 (v7, hearts),
	c26 (v8, hearts),
	c27 (v9, hearts),
	c28 (v10, hearts),
	c29 (jack, hearts),
	c30 (lady, hearts),
	c31 (king, hearts),
	c32 (ace, hearts)
{
}

Card* Pack::get()
{ 
//	printf ("Cards are %d\n", size());
	// New implementation is needed
//	Card* card = front();
//	pop_back();
	return NULL;
}

void Pack::shuffle()
{
    srand( time(0) );

    for (int val=0; val<50; val=val+1)
    {
	int x1, x2;
	x1 = rand() % 32;
	x2 = rand() % 32;
	Card* card = m_pCardsArray[x1];
	m_pCardsArray[x1] = m_pCardsArray[x2];
	m_pCardsArray[x2] = card;
    }
}


void Pack::Dump()
{
    cout << "{ \"Pack\": [" << endl;

    for (int i=0; i<32; i++)
    {
	Card* card = m_pCardsArray[i];
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

    for (int i=0; i<32; i++)
    {
	Card* card = m_pCardsArray[i];
	strcpy(pBuffer, card->getAsString());
	pBuffer += strlen(card->getAsString());
        if (i != 31) *pBuffer++ = ',';
	*pBuffer++ = '\n';
    }

    strcpy(pBuffer, "  ]\n}\n");

    return &buffer[0];
}
