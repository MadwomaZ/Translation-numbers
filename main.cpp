#include <iostream>
#include <string>
#include <math.h>
#include <deque>
using namespace std;
bool isDigit(string str);
int *NumToDec(int * Num, unsigned int size, unsigned int base);
int DecToNum(int * Num, unsigned int size, unsigned int base);
int StringToInt(string str, int *newNum);
int print(deque <int> number, unsigned int base);

bool isDigit(string str)
{
    bool result;
    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            result = true;
        }
        else
            return false;
    }
    return result;
}

int main()
{
    string iNumber;

    cout << "Enter your number: ";
    cin >> iNumber;
    unsigned int size = iNumber.size();
    int * newNum = new int [size];
    StringToInt(iNumber, newNum);
    unsigned int sizeNum = StringToInt(iNumber, newNum);
    if(iNumber[0] == '0' && (iNumber[1] == 'x' || iNumber[1] == 'X'))
    {
        cout << "You have entered a number in HEXadecimal" << endl;
        NumToDec(newNum, sizeNum, 16);
        //int * itemDec = ;
        DecToNum(NumToDec(newNum, sizeNum, 16), sizeNum - 2, 8);
        //DecToNum(NumToDec(newNum, sizeNum, 16), sizeNum, 2);
    }
    else if (iNumber[0] == '0')
    {
        cout << "You have entered a number in OCTal" << endl;
        NumToDec(newNum, sizeNum, 8);
    }
    else if (iNumber[size - 1] == 'b' || iNumber[size - 1] == 'B')
    {
        cout << "You have entered a number in the BINary system" << endl;
        NumToDec(newNum, sizeNum, 2);
    }
    else if (isDigit(iNumber) || iNumber[size - 1] == 'd' || iNumber[size - 1] == 'D')
    {
        cout << "You have entered a number in the DECimal system" << endl;
        DecToNum(newNum, sizeNum, 16);
        DecToNum(newNum, sizeNum, 8);
        DecToNum(newNum, sizeNum, 2);
    }
    else
        cout << "It is not number. Please, try again!" << endl;
    delete[] newNum;
    return 0;
}

int StringToInt(string str, int * newNum)
{
    unsigned int sizeNewNum = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            newNum[i] = str[i] - '0';
            sizeNewNum++;
        }
        else if ((str[i] == 'a' || str[i] == 'A') && (str[1] == 'x'))
        {
            sizeNewNum++;
            newNum[i] = 10;
        }
        else if ((str[i] == 'b' || str[i] == 'B') && (str[1] == 'x'))
        {
            sizeNewNum++;
            newNum[i] = 11;
        }
        else if ((str[i] == 'c' || str[i] == 'C') && (str[1] == 'x'))
        {
            sizeNewNum++;
            newNum[i] = 12;
        }
        else if ((str[i] == 'd' || str[i] == 'D') && (str[1] == 'x'))
        {
            sizeNewNum++;
            newNum[i] = 13;
        }
        else if ((str[i] == 'e' || str[i] == 'E') && (str[1] == 'x'))
        {
            sizeNewNum++;
            newNum[i] = 14;
        }
        else if ((str[i] == 'f' || str[i] == 'F') && (str[1] == 'x'))
        {
            sizeNewNum++;
            newNum[i] = 15;
        }
        else if (str[1] == 'x')
        {
            sizeNewNum++;
            newNum[1] = 0;
        }
    }
    cout << sizeNewNum << endl;
    return sizeNewNum;
}
int * NumToDec(int * Num, unsigned int size, unsigned int base)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        result = result + (Num[i] * pow(base, (size - 1 - i)));
    }
    cout << "DEC: " << result << endl;
    int * pnt = &result;
    return pnt;
}
int DecToNum(int * Num, unsigned int size, unsigned int base)
{
    int result = 0;
    unsigned int number = 0;
    //int newNumber[size];
    deque <int> newNumber;
    int tmp = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        number += Num[i] * tmp;
        tmp *= 10;
        //cout << "i = " << i << " number = " << number << " + " << Num[i] << " * " << tmp << endl;
    }
    while (number != 0)
    {
        newNumber.push_front(number % base);
        number /= base;
    }
    print(newNumber, base);
    return result;
}
int print(deque <int> number, unsigned int base)
{
    switch (base) {
    case 2:
        cout << "BIN: ";
        for (unsigned int i = 0; i < number.size(); i++)
        {
            cout << number[i];
        }
        cout << endl;
        break;
    case 8:
        cout << "OCT: ";
        for (unsigned int i = 0; i < number.size(); i++)
        {
            cout << number[i];
        }
        cout << endl;
        break;
    case 16:
        cout << "HEX: ";
        for (unsigned int i = 0; i < number.size(); i++)
        {
            cout << number[i];
        }
        cout << endl;
        break;
    default:
        cout << "Oh! No!" << endl;
        break;
    }
    return 0;
}
