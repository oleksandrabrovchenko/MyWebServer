#include <string>

using namespace std;

enum CardValue {v6, v7};
enum CardSuit { spade, cross, diamonds, hearts };

class Card
{
public:
    CardValue value;
    CardSuit suit;

    Card(CardValue card_value, CardSuit card_suit);
    void Dump();
    string getAsString();
};

class Pack 
{
    int count; 
    deque<Card*> my_deque;

public:  //������ ������ ��������� 
     Pack();  //�����������, ��� ��������� ����� ������, ������������ �������� �� ��������, ������ � public

     Card get();
     void Dump();
     void shuffle(); 

     string getAsString();
};
