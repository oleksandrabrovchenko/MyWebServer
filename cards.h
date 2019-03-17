enum CardValue { v7, v8, v9, v10, jack, lady, king, ace };
enum CardSuit { spade, cross, diamonds, hearts };

class Card
{
    char buffer[1024];

public:
    CardValue value;
    CardSuit suit;

    Card(CardValue card_value, CardSuit card_suit);
    void Dump();
    const char* getAsString();
};

class Pack
{
    Card c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c31, c32;

    Card* m_pCardsArray[32] = { &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10, &c11, &c12, &c13, &c14, &c15, &c16, &c17, &c18, &c19, &c20, &c21, &c22, &c23, &c24, &c25, &c26, &c27, &c28, &c29, &c30, &c31, &c32 };
    char buffer[2000];

public:  //начало списка публичных 
     Pack();  //конструктор, имя идентично имени класса, возвращаемое значение не задавать, только в public

     Card* get();
     void Dump();
     void shuffle(); 

     const char* getAsString();
};
