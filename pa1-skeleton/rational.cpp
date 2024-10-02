#include "rational.h"


// ============== Start your code from here ==================

int makeInt(const char charValue)
{
    return charValue - '0';
}

char makeChar(const int intValue)
{
    return intValue + '0';
}

char *makeRational(const char *stringUp, const char *stringDown)
{
    if (stringDown[0] == '1' && stringDown[1] == '\0')
    {
        char *result = new char[getstrlen(stringUp) + 1];
        for (int i = 0; stringUp[i] != '\0'; i++)
        {
            result[i] = stringUp[i];
        }
        result[getstrlen(stringUp)] = '\0';
        return result;
    }
    int length = getstrlen(stringUp) + getstrlen(stringDown) + 2;
    char *concatedS = new char[length];

    if (stringUp[0] == '-' && stringDown[0] != '-')
    {
        delete[] concatedS;
        char *flippedUp = flipSignStringInt(stringUp);
        char *rational = makeRational(flippedUp, stringDown);
        delete[] flippedUp;
        char *result = flipSignStringInt(rational);
        delete[] rational;
        return result;
    }
    if (stringDown[0] == '-' && stringUp[0] != '-')
    {
        delete[] concatedS;
        char *flippedDown = flipSignStringInt(stringDown);
        char *rational = makeRational(stringUp, flippedDown);
        delete[] flippedDown;
        char *result = flipSignStringInt(rational);
        delete[] rational;
        return result;
    }
    if (stringUp[0] == '-' && stringDown[0] == '-')
    {
        delete[] concatedS;
        char *flippedUp = flipSignStringInt(stringUp);
        char *flippedDown = flipSignStringInt(stringDown);
        char *rational = makeRational(flippedUp, flippedDown);
        delete[] flippedUp;
        delete[] flippedDown;
        return rational;
    }

    for (int i = 0; stringUp[i] != '\0'; i++)
    {
        concatedS[i] = stringUp[i];
    }

    concatedS[getstrlen(stringUp)] = '/';

    for (int i = 0; stringDown[i] != '\0'; i++)
    {
        concatedS[getstrlen(stringUp) + 1 + i] = stringDown[i];
    }

    concatedS[length - 1] = '\0';

    return concatedS;
}

char *stringIntsToRation(const char *numerator, const char *denominator)
{
    if (isZero(denominator))
    {
        return nullptr;
    }

    char *gcd = gcdStringInt(numerator, denominator);
    char *numTemp = divStringInt(numerator, gcd);
    char *denTemp = divStringInt(denominator, gcd);

    delete[] gcd;

    char *result = makeRational(numTemp, denTemp);
    delete[] numTemp;
    delete[] denTemp;

    return result;
}

void stringRationToInts(const char *rationA, char *&numerator, char *&denominator)
{
    if (isZero(rationA))
    {
        numerator = new char[2];
        numerator[0] = '0';
        numerator[1] = '\0';
        denominator = new char[2];
        denominator[0] = '1';
        denominator[1] = '\0';
        return;
    }

    int length = getstrlen(rationA);
    int slashPosition = -1;

    for (int i = 0; i < length; i++)
    {
        if (rationA[i] == '/')
        {
            slashPosition = i;
            break;
        }
    }

    if (slashPosition == -1)
    {
        numerator = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            numerator[i] = rationA[i];
        }
        numerator[length] = '\0';
        denominator = new char[2];
        denominator[0] = '1';
        denominator[1] = '\0';
        return;
    }

    numerator = new char[slashPosition + 1];
    denominator = new char[length - slashPosition];

    for (int i = 0; i < slashPosition; i++)
    {
        numerator[i] = rationA[i];
    }
    numerator[slashPosition] = '\0';

    for (int i = 0; i < length - slashPosition - 1; i++)
    {
        denominator[i] = rationA[slashPosition + 1 + i];
    }
    denominator[length - slashPosition - 1] = '\0';

    return;
}

char *addStringRation(const char *rationA, const char *rationB)
{
    char *Anum, *Bnum, *Aden, *Bden;

    stringRationToInts(rationA, Anum, Aden);
    stringRationToInts(rationB, Bnum, Bden);

    char *Tden = mulStringInt(Aden, Bden);
    char *NAnum = mulStringInt(Anum, Bden);
    char *NBnum = mulStringInt(Bnum, Aden);
    char *Tnum = addStringInt(NAnum, NBnum);

    char *result = stringIntsToRation(Tnum, Tden);

    delete[] Anum;
    delete[] Bnum;
    delete[] Aden;
    delete[] Bden;
    delete[] NAnum;
    delete[] NBnum;
    delete[] Tnum;
    delete[] Tden;

    return result;
}

char *subStringRation(const char *rationA, const char *rationB)
{
    char *Anum, *Bnum, *Aden, *Bden;

    stringRationToInts(rationA, Anum, Aden);
    stringRationToInts(rationB, Bnum, Bden);

    char *Tden = mulStringInt(Aden, Bden);
    char *NAnum = mulStringInt(Anum, Bden);
    char *NBnum = mulStringInt(Bnum, Aden);
    char *Tnum = subStringInt(NAnum, NBnum);

    char *result = stringIntsToRation(Tnum, Tden);

    delete[] Anum;
    delete[] Bnum;
    delete[] Aden;
    delete[] Bden;
    delete[] NAnum;
    delete[] NBnum;
    delete[] Tnum;
    delete[] Tden;

    return result;
}

char *mulStringRation(const char *rationA, const char *rationB)
{
    char *Anum, *Bnum, *Aden, *Bden;

    stringRationToInts(rationA, Anum, Aden);
    stringRationToInts(rationB, Bnum, Bden);

    char *Tden = mulStringInt(Aden, Bden);
    char *Tnum = mulStringInt(Anum, Bnum);

    char *result = stringIntsToRation(Tnum, Tden);

    delete[] Anum;
    delete[] Bnum;
    delete[] Aden;
    delete[] Bden;
    delete[] Tnum;
    delete[] Tden;

    return result;
}

char *divStringRation(const char *rationA, const char *rationB)
{
    if (isZero(rationB))
    {
        return nullptr;
    }
    char *Anum, *Bnum, *Aden, *Bden;

    stringRationToInts(rationA, Anum, Aden);
    stringRationToInts(rationB, Bnum, Bden);

    char *Tden = mulStringInt(Aden, Bnum);
    char *Tnum = mulStringInt(Anum, Bden);

    char *result = stringIntsToRation(Tnum, Tden);

    delete[] Anum;
    delete[] Bnum;
    delete[] Aden;
    delete[] Bden;
    delete[] Tnum;
    delete[] Tden;

    return result;
}

char *stringDecimalToRation(const char *decimal)
{
    int dotIndex = -1;
    int len = getstrlen(decimal);

    for (int i = 0; i < len; i++)
    {
        if (decimal[i] == '.')
        {
            dotIndex = i;
            break;
        }
    }

    if (dotIndex == -1)
    {
        char *result = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            result[i] = decimal[i];
        }
        result[len] = '\0';
        return result;
    }

    bool isNegative = false;
    if (decimal[0] == '-')
    {
        isNegative = true;
        char *flippedDecimal = flipSignStringInt(decimal);
        char *result = stringDecimalToRation(flippedDecimal);
        delete[] flippedDecimal;
        char *finalResult = flipSignStringInt(result);
        delete[] result;
        return finalResult;
    }

    char *intPart = new char[dotIndex + 1];
    char *fracPart = new char[len - dotIndex];

    for (int i = 0; i < dotIndex; i++)
    {
        intPart[i] = decimal[i];
    }
    intPart[dotIndex] = '\0';
    int intPartLen = getstrlen(intPart);

    for (int i = 0; i < len - dotIndex - 1; i++)
    {
        fracPart[i] = decimal[dotIndex + 1 + i];
    }
    fracPart[len - dotIndex - 1] = '\0';
    int fracPartLen = getstrlen(fracPart);

    // get numerator
    char *powerToTen = mulPowerOfTenStringInt(intPart, fracPartLen);
    delete[] intPart;
    char *numerator = addStringInt(powerToTen, fracPart);
    delete[] powerToTen;
    delete[] fracPart;

    // get denominator
    char *denominator = mulPowerOfTenStringInt("1", fracPartLen);

    char *result = stringIntsToRation(numerator, denominator);
    delete[] numerator;
    delete[] denominator;

    return result;
}

char *stringRationToDecimal(const char *ration, int dp)
{
    int slashPosition = -1;
    int len = getstrlen(ration);

    for (int i = 0; i < len; i++)
    {
        if (ration[i] == '/')
        {
            slashPosition = i;
            break;
        }
    }

    if (slashPosition == -1)
    {
        char *result = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            result[i] = ration[i];
        }
        result[len] = '\0';
        return result;
    }

    char *numerator = new char[slashPosition + 1];
    char *denominator = new char[len - slashPosition];

    stringRationToInts(ration, numerator, denominator);

    char *newNum = mulPowerOfTenStringInt(numerator, dp);
    delete[] numerator;
    char *resultNON = divStringInt(newNum, denominator);
    delete[] newNum;
    delete[] denominator;

    int length = getstrlen(resultNON);

    char *result = new char[length + 2];

    if (length <= dp)
    {
        result[0] = '0';
        result[1] = '.';
        for (int i = 0; i < dp - length; i++)
        {
            result[i + 2] = '0';
        }
        for (int i = 0; i < length; i++)
        {
            result[dp - length + 2 + i] = resultNON[i];
        }
        result[dp + 2] = '\0';
    }
    else
    {
        for (int i = 0; i < length - dp; i++)
        {
            result[i] = resultNON[i];
        }
        result[length - dp] = '.';

        for (int i = 0; i < dp; i++)
        {
            result[length - dp + i + 1] = resultNON[length - dp + i];
        }
        result[length + 1] = '\0';
    }

    delete[] resultNON;

    return result;
}