#include "integer.h"
#include "rational.h"
#include <iostream>

using namespace std;

const string IDX = "Test Case ";
const string NAME = ": ";
const string LINE = "--------------------------------------------------";

int main()
{

    int test;
    cin >> test;

    if (test == 1)
    {
        string name = "Part I - Testing getstrlen";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "1234";
        cout << "string length of " << intA << ": " << getstrlen(intA) << endl;
    }
    else if (test == 2)
    {
        string name = "Part I - Testing getstrlen";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "-74891741412";
        cout << "string length of " << intA << ": " << getstrlen(intA) << endl;
    }
    else if (test == 3)
    {
        string name = "Part I - Testing isZero";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "0";
        cout << intA << " equals to zero: " << boolalpha << isZero(intA) << endl;
    }
    else if (test == 4)
    {
        string name = "Part I - Testing isZero";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "41124";
        cout << intA << " equals to zero: " << boolalpha << isZero(intA) << endl;
    }
    else if (test == 5)
    {
        string name = "Part I - Testing isEqualString";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "0";
        const char *intB = "0";
        cout << intA << " equals to " << intB << ": " << boolalpha << isEqualStringInt(intA, intB) << endl;
    }
    else if (test == 6)
    {
        string name = "Part I - Testing isEqualString";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "896787";
        const char *intB = "123";
        cout << intA << " equals to " << intB << ": " << boolalpha << isEqualStringInt(intA, intB) << endl;
    }
    else if (test == 7)
    {
        string name = "Part I - Testing flipSignStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "123";
        const char *res = flipSignStringInt(intA);
        cout << intA << " after flipping sign: " << res << endl;
        delete[] res;
    }
    else if (test == 8)
    {
        string name = "Part I - Testing flipSignStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "-49128491249";
        const char *res = flipSignStringInt(intA);
        cout << intA << " after flipping sign: " << res << endl;
        delete[] res;
    }
    else if (test == 9)
    {
        string name = "Part I - Testing isLargerThanStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "12345";
        const char *intB = "12340";
        cout << intA << " is larger than " << intB << ": " << boolalpha << isLargerThanStringInt(intA, intB) << endl;
    }
    else if (test == 10)
    {
        string name = "Part I - Testing isLargerThanStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "71289471298471";
        const char *intB = "71289471298471";
        cout << intA << " is larger than " << intB << ": " << boolalpha << isLargerThanStringInt(intA, intB) << endl;
    }
    else if (test == 11)
    {
        string name = "Part I - Testing mulPowerOfTenStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "84671284";
        int exp = 12;
        const char *res = mulPowerOfTenStringInt(intA, exp);
        cout << intA << " * 10^" << exp << " = " << res << endl;
        delete[] res;
    }
    else if (test == 12)
    {
        string name = "Part I - Testing mulPowerOfTenStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "138716441";
        int exp = -2;
        const char *res = mulPowerOfTenStringInt(intA, exp);
        cout << intA << " * 10^" << exp << " = " << res << endl;
        delete[] res;
    }
    else if (test == 13)
    {
        string name = "Part I - Testing mulPowerOfTenStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "938172984178";
        int exp = 0;
        const char *res = mulPowerOfTenStringInt(intA, exp);
        cout << intA << " * 10^" << exp << " = " << res << endl;
        delete[] res;
    }
    else if (test == 14)
    {
        string name = "Part I - Testing addStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "123";
        const char *intB = "1234";
        const char *res = addStringInt(intA, intB);
        cout << intA << " + " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 15)
    {
        string name = "Part I - Testing addStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "123";
        const char *intB = "-1234";
        const char *res = addStringInt(intA, intB);
        cout << intA << " + " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 16)
    {
        string name = "Part I - Testing addStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "184798147981748912";
        const char *intB = "2412048129048012241892";
        const char *res = addStringInt(intA, intB);
        cout << intA << " + " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 17)
    {
        string name = "Part I - Testing subStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "123";
        const char *intB = "1234";
        const char *res = subStringInt(intA, intB);
        cout << intA << " - " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 18)
    {
        string name = "Part I - Testing subStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "9999";
        const char *intB = "1000";
        const char *res = subStringInt(intA, intB);
        cout << intA << " - " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 19)
    {
        string name = "Part I - Testing subStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "2412048129048012241892";
        const char *intB = "-184798147981748912";
        const char *res = subStringInt(intA, intB);
        cout << intA << " - " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 20)
    {
        string name = "Part I - Testing mulByDigitStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "12345";
        int multiplier = 2;
        const char *res = mulByDigitStringInt(intA, multiplier);
        cout << intA << " * " << multiplier << " = " << res << endl;
        delete[] res;
    }
    else if (test == 21)
    {
        string name = "Part I - Testing mulByDigitStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "61284712894794179481412812648197419847891411314124";
        int multiplier = 9;
        const char *res = mulByDigitStringInt(intA, multiplier);
        cout << intA << " * " << multiplier << " = " << res << endl;
        delete[] res;
    }
    else if (test == 22)
    {
        string name = "Part I - Testing mulStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "1234";
        const char *intB = "456";
        const char *res = mulStringInt(intA, intB);
        cout << intA << " * " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 23)
    {
        string name = "Part I - Testing mulStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "974189479";
        const char *intB = "-131241244";
        const char *res = mulStringInt(intA, intB);
        cout << intA << " * " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 24)
    {
        string name = "Part I - Testing divStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "1234";
        const char *intB = "617";
        const char *res = divStringInt(intA, intB);
        cout << intA << " / " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 25)
    {
        string name = "Part I - Testing divStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "25235252352";
        const char *intB = "-324235";
        const char *res = divStringInt(intA, intB);
        cout << intA << " / " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 26)
    {
        string name = "Part I - Testing divStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "894719871985701891192623636344989825728952184895";
        const char *intB = "212749812429857998";
        const char *res = divStringInt(intA, intB);
        cout << intA << " / " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 27)
    {
        string name = "Part I - Testing modStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "1234";
        const char *intB = "617";
        const char *res = modStringInt(intA, intB);
        cout << intA << " % " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 28)
    {
        string name = "Part I - Testing modStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "4917841";
        const char *intB = "179188917984";
        const char *res = modStringInt(intA, intB);
        cout << intA << " % " << intB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 29)
    {
        string name = "Part I - Testing gcdStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "2310";
        const char *intB = "924";
        const char *res = gcdStringInt(intA, intB);
        cout << "gcd(" << intA << ", " << intB << ")" << " = " << res << endl;
        delete[] res;
    }
    else if (test == 30)
    {
        string name = "Part I - Testing gcdStringInt";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *intA = "15939802829686364351";
        const char *intB = "48365645091201461328";
        const char *res = gcdStringInt(intA, intB);
        cout << "gcd(" << intA << ", " << intB << ")" << " = " << res << endl;
        delete[] res;
    }
    else if (test == 31)
    {
        string name = "Part II - Testing stringIntsToRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *numerator = "9041";
        const char *denominator = "17";
        const char *res = stringIntsToRation(numerator, denominator);
        cout << "numerator = " << numerator << endl;
        cout << "denominator = " << denominator << endl;
        cout << "resulting rational: " << res << endl;
        delete[] res;
    }
    else if (test == 32)
    {
        string name = "Part II - Testing stringIntsToRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *numerator = "-41848";
        const char *denominator = "41849128094";
        const char *res = stringIntsToRation(numerator, denominator);
        cout << "numerator = " << numerator << endl;
        cout << "denominator = " << denominator << endl;
        cout << "resulting rational: " << res << endl;
        delete[] res;
    }
    else if (test == 33)
    {
        string name = "Part II - Testing stringRationToInts";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "89/11";
        char *numerator;
        char *denominator;
        stringRationToInts(rationA, numerator, denominator);
        cout << "rational = " << rationA << endl;
        cout << "resulting numerator: " << numerator << endl;
        cout << "resulting denominator: " << denominator << endl;
        delete[] numerator;
        delete[] denominator;
    }
    else if (test == 34)
    {
        string name = "Part II - Testing stringRationToInts";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "-91748127498/4718947891748911";
        char *numerator;
        char *denominator;
        stringRationToInts(rationA, numerator, denominator);
        cout << "rational = " << rationA << endl;
        cout << "resulting numerator: " << numerator << endl;
        cout << "resulting denominator: " << denominator << endl;
        delete[] numerator;
        delete[] denominator;
    }
    else if (test == 35)
    {
        string name = "Part II - Testing addStringRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "123";
        const char *rationB = "1234";
        const char *res = addStringRation(rationA, rationB);
        cout << rationA << " + " << rationB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 36)
    {
        string name = "Part II - Testing addStringRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "53/466";
        const char *rationB = "291/98";
        const char *res = addStringRation(rationA, rationB);
        cout << rationA << " + " << rationB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 37)
    {
        string name = "Part II - Testing subStringRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "123";
        const char *rationB = "1234";
        const char *res = subStringRation(rationA, rationB);
        cout << rationA << " - " << rationB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 38)
    {
        string name = "Part II - Testing subStringRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "53/466";
        const char *rationB = "291/98";
        const char *res = subStringRation(rationA, rationB);
        cout << rationA << " - " << rationB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 39)
    {
        string name = "Part II - Testing mulStringRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "1234";
        const char *rationB = "456";
        const char *res = mulStringRation(rationA, rationB);
        cout << rationA << " * " << rationB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 40)
    {
        string name = "Part II - Testing mulStringRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "53/466";
        const char *rationB = "-292/97";
        const char *res = mulStringRation(rationA, rationB);
        cout << rationA << " * " << rationB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 41)
    {
        string name = "Part II - Testing divStringRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "1212";
        const char *rationB = "101";
        const char *res = divStringRation(rationA, rationB);
        cout << rationA << " / " << rationB << " = " << res << endl;
        delete[] res;
    }
    else if (test == 42)
    {
        string name = "Part II - Testing divStringRation";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        const char *rationA = "53/466";
        const char *rationB = "-292/97";
        const char *res = divStringRation(rationA, rationB);
        cout << rationA << " / " << rationB << " = " << res << endl;
        delete[] res;
    }
}