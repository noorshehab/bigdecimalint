#define BIGDECIMALINT_H
#include <iostream>
#include <string>
using namespace std;

class bigdecimalint
{
public:
    string num;
    int sum, carry;

    bigdecimalint(string decstr);
    bigdecimalint(int decint);
    bigdecimalint();

    bigdecimalint operator+(bigdecimalint b);
    bigdecimalint operator-(bigdecimalint b);

    friend bool operator>(string a, string b);
    friend bool operator<(string a, string b);

    friend ostream& operator<< (ostream& output, bigdecimalint a);

    friend bool ckvalid(bigdecimalint &b);
    friend bool cksign(bigdecimalint &b);




    int size();

};
