#include <iostream>
#include "bigdecimalint.h"
#include <string>
using namespace std;

int main()
{
    bigdecimalint num1("777777777777777777777777777777");
    bigdecimalint num2("222222222222222222222222222222");
    bigdecimalint num3 = num2 + num1;

    bigdecimalint num4 = num2 - num1;

    cout << "num1 = " << num1 << "\n"<< endl;
    cout << "num2 = " << num2 << "\n"<< endl;

    cout << "(num2 + num1) = " << num3 << "\n"<< endl;
    cout << "(num2 - num1) = " << num4 << "\n"<< endl;

    bigdecimalint num5("666666666666666666666666666666");
    bigdecimalint num6("-222222222222222222222222222222");

    bigdecimalint num7 = num5 + num6;
    bigdecimalint num8 = num5 - num6;

    cout << "num5 = " << num5 << "\n"<< endl;
    cout << "num6 = " << num6 << "\n"<< endl;

    cout << "(num5 + num6) = " << num7  << "\n"<< endl;
    cout << "(num5 - num6) = " << num8 << endl;
    return 0;
}
