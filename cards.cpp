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

Pack::Pack()  //�����������, ��� ��������� ����� ������, ������������ �������� �� ��������, ������ � public
{
    int index=0;

    for (int val=0; val<8; val=val+1)
    {
	m_pCardsArray[index++] = new Card((CardValue)val, spade);
	m_pCardsArray[index++] = new Card((CardValue)val, spade);
	m_pCardsArray[index++] = new Card((CardValue)val, spade);
	m_pCardsArray[index++] = new Card((CardValue)val, spade);
    }
}

// Destructor. We need to delete created cards when the pack is being destroyed.
Pack::~Pack()
{
    for (int i=0; i<32; i++)
    {
	delete m_pCardsArray[i];
    }
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
