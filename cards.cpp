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

string Card::getAsString()
{
    string  strCard;
    strCard += "    { \"value\": " + ValueMass [value]  + ", \"suit\": " + SuitMass [suit]  + " }";
    return strCard;
}

ostream &operator<<(ostream &os, Card const &card) 
{ 
    return os << "{ \"value\": " << ValueMass [card.value]  << ", \"suit\": " << SuitMass [card.suit]  << " }";
   //   {"value": "card.value", "suit": "card.suit"} 
}

Pack::Pack()  //конструктор, имя идентично имени класса, возвращаемое значение не задавать, только в public
     {
          count = 32; //создание 32 карт

	  for (int val=0; val<8; val=val+1)
	  {
		Card* c = new Card((CardValue)val, spade);
		my_deque.push_front(c);
		c = new Card((CardValue)val, cross);
		my_deque.push_front(c);
                c = new Card((CardValue)val, diamonds);
		my_deque.push_front(c);
                c = new Card((CardValue)val, hearts);
		my_deque.push_front(c);
	  }

//          Card* a1 = new Card(v6, spade);
//	  Card* a2 = new Card(v7, cross);
//	  printf ("We have cards %d\n", my_queue.size());
//          my_queue.push(a1);
//	  my_queue.push(a2);
	  // printf ("We have cards %d\n", my_deque.size());
	  my_deque.pop_back();
	  Card* b1 = my_deque.front();
	  my_deque.pop_back();
	 // printf ("We have cards %d\n", my_deque.size());
	 // cout << "We got card with value " << b1->value <<"and suit " << b1->suit << endl;
          // cout << "We got card  " << *b1 << endl;
	  //b1->Dump();
	  //printf ("\nWe got card with value %d and suit %d\n", b1->value, b1->suit);
     }

Card Pack::get()
{ 
	count = count - 1;
	printf ("Cards are %d\n", count);
}


void Pack::shuffle()
{
     for (int val=0; val<50; val=val+1)
     {
     int x1, x2;
     x1 = rand() % 32;
     x2 = rand() % 32;
     Card* card = my_deque[x1];
     my_deque[x1] = my_deque[x2];
     my_deque[x2] = card;
    // cout << "x1 = " << x1 << endl;
    // cout << "x2 = " << x2 << endl;
     }

}


void Pack::Dump()
{
    cout << "{ \"Pack\": [" << endl;

    for (int i=0; i<32; i++)
    {
	Card* card = my_deque[i];
	card->Dump();
        if (i!=31) cout << ",";
	cout << endl;
	//Card* c = new Card((CardValue)val, spade);
    }

    cout << "  ]" << endl << "}" << endl;
}

string Pack::getAsString()
{
    string strPack;

    // strPack = strPack + "string";
    strPack +=  "{ \"Pack\": [\n";

    for (int i=0; i<32; i++)
    {
	Card* card = my_deque[i];
	strPack += card->getAsString();
        if (i != 31) strPack += ",";
	strPack += "\n";
    }

    strPack += "  ]\n}\n";

     return strPack;
}
