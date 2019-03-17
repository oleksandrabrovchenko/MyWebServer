using namespace std;

enum CardValue {v6, v7};
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
    Card* m_pCardsArray[32];
    char buffer[2000];

public:  //начало списка публичных 
     Pack();  //конструктор, имя идентично имени класса, возвращаемое значение не задавать, только в public
     ~Pack();

     Card* get();
     void Dump();
     void shuffle(); 

     const char* getAsString();
};
