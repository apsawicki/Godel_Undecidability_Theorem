#include <iostream>
using namespace std;


int oddFunc(int &num, int &integer)
{
    num = (3*num) + 1;

    integer = integer + 1;

    return num;
}


int evenFunc(int &num, int &integer)
{
    num = num/2;

    integer = integer + 1;

    return num;
}


int checkNum(int &num, int &integer)
{
    if (num % 2 == 0)
    {
        num = evenFunc(num, integer);
    }
    else
    {
        num = oddFunc(num, integer);
    }

    return num;
}


int main()
{
    int num = 0, originalNum = 0, integer = 0;


    cout << "gimme num: ";
    cin >> num;
    originalNum = num;

    while (num != 1)
    {
        num = checkNum(num, integer);
    }


    cout << "f^" << integer << " (" << originalNum << ") = 1" << endl;

    system("pause");
    return 0;
}
