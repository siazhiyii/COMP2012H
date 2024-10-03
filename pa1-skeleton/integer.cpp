#include "integer.h"

// ============== Start your code from here ==================
int getstrlen(const char *str)
{
    int strlen = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        strlen++;
    }
    return strlen;
}

bool isZero(const char *intA)
{
    return (intA[0] == '0' && intA[1] == '\0');
}

bool isEqualStringInt(const char *intA, const char *intB)
{
    for (int i = 0; intA[i] != '\0' || intB[i] != '\0'; i++)
    {
        if (intA[i] != intB[i])
        {
            return false;
        }
    }
    return true;
}

void removeZero2(char *stringWithZero)
{
    int zeroIndex = 0;
    int length = getstrlen(stringWithZero);

    while (stringWithZero[zeroIndex] == '0' && stringWithZero[zeroIndex + 1] != '\0')
    {
        zeroIndex++;
    }

    if (zeroIndex > 0)
    {
        for (int i = zeroIndex; stringWithZero[i] != '\0'; i++)
        {
            stringWithZero[i - zeroIndex] = stringWithZero[i];
        }
        stringWithZero[length - zeroIndex] = '\0';
    }
}

char *flipSignStringInt(const char *intA)
{
    int stringIntLen = getstrlen(intA);
    char *flippedStringInt = new char[stringIntLen + 2];
    if (isZero(intA))
    {
        flippedStringInt[0] = '0';
        flippedStringInt[1] = '\0';
        return flippedStringInt;
    }
    if (intA[0] == '-')
    {
        for (int i = 0; intA[i] != '\0'; i++)
        {
            flippedStringInt[i] = intA[i + 1];
        }
        flippedStringInt[stringIntLen - 1] = '\0';
    }
    else
    {
        flippedStringInt[0] = '-';
        for (int i = 0; intA[i] != '\0'; i++)
        {
            flippedStringInt[i + 1] = intA[i];
        }
        flippedStringInt[stringIntLen + 1] = '\0';
    }
    return flippedStringInt;
}

bool isLargerThanStringInt(const char *intA, const char *intB)
{
    // equal checks (if same = false)
    if (isEqualStringInt(intA, intB))
    {
        return false;
    }
    // negative checks ( -ve intA & +ve intB = false;;; vice versa)

    if (intA[0] == '-' && intB[0] != '-')
    {
        return false;
    }
    else if (intB[0] == '-' && intA[0] != '-')
    {
        return true;
    }
    // length check (if intA longer than intB  = true for both +ve but false for both -ve)
    if (getstrlen(intA) > getstrlen(intB))
    {
        if (intA[0] == '-')
        {
            return false;
        }
        return true;
    }
    if (getstrlen(intA) < getstrlen(intB))
    {
        if (intA[0] != '-')
        {
            return false;
        }
        return true;
    }
    // individual int check
    for (int i = 0; intA[i] != '\0' && intB[i] != '\0'; i++)
    {
        if (intA[i] > intB[i])
        {
            if (intA[0] == '-')
            {
                return false;
            }
            return true;
        }
        if (intA[i] < intB[i])
        {
            if (intA[0] != '-')
            {
                return false;
            }
            return true;
        }
    }
    return false;
}

char *mulPowerOfTenStringInt(const char *intA, int exp)
{
    int lengthA = getstrlen(intA);
    if (intA[0] == '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *result = flipSignStringInt(mulPowerOfTenStringInt(flippedIntA, exp));
        delete[] flippedIntA;
        return result;
    }
    if (exp < 0)
    {
        exp = -exp;
        if (lengthA <= exp) // handles case where -exp is more than what intA has
        {
            char *tenStringInt = new char[2];
            tenStringInt[0] = '0';
            tenStringInt[1] = '\0';
            return tenStringInt;
        }
        char *tenStringInt = new char[lengthA - exp + 1];
        for (int i = 0; i < lengthA - exp; i++)
        {
            tenStringInt[i] = intA[i];
        }
        tenStringInt[lengthA - exp] = '\0';
        return tenStringInt;
    }
    else if (exp > 0)
    {
        char *tenStringInt = new char[lengthA + exp + 1];
        for (int i = 0; i < lengthA; i++)
        {
            tenStringInt[i] = intA[i];
        }
        for (int i = lengthA; i < lengthA + exp; i++)
        {
            tenStringInt[i] = '0';
        }
        tenStringInt[lengthA + exp] = '\0';
        return tenStringInt;
    }
    char *tenStringInt = new char[lengthA + 1];
    for (int i = 0; i < lengthA; i++)
    {
        tenStringInt[i] = intA[i];
    }
    tenStringInt[lengthA] = '\0';
    return tenStringInt;
}

long long s2int(const char strValue)
{
    return strValue - '0';
}

long long stringToInt(const char *strValue)
{
    long long numValue = 0;
    bool isNeg = false;
    if (*strValue == '-')
    {
        isNeg = true;
        strValue++;
    }
    while (*strValue)
    {
        numValue = numValue * 10 + (*strValue - '0');
        strValue++;
    }
    return isNeg ? -numValue : numValue;
}

// char *intToCharArray(long long intValue)
// {
//     if (intValue == 0)
//     {
//         char *resultValue = new char[2];
//         resultValue[0] = '0';
//         resultValue[1] = '\0';
//         return resultValue;
//     }
//     bool isNegative = false;
//     if (intValue < 0)
//     {
//         isNegative = true;
//         intValue = -intValue;
//     }
//     int len = 0;
//     long long temp = intValue;
//     while (temp > 0)
//     {
//         temp /= 10;
//         len++;
//     }
//     char *arrayValue = new char[len + (isNegative ? 1 : 0) + 1];
//     arrayValue[len + (isNegative ? 1 : 0)] = '\0';
//     if (isNegative)
//     {
//         arrayValue[0] = '-';
//     }
//     for (int i = len - 1; i >= 0; i--)
//     {
//         arrayValue[i + (isNegative ? 1 : 0)] = (intValue % 10) + '0';
//         intValue /= 10;
//     }
//     return arrayValue;
// }

// char *reverseCharArray(const char *flippedArray)
// {
//     int len = getstrlen(flippedArray);
//     char *reversedChar = new char[len + 1];
//     for (int start = 0, end = len - 1; start < len; start++, end--)
//     {
//         reversedChar[start] = flippedArray[end];
//     }
//     reversedChar[len] = '\0';
//     return reversedChar;
// }

void reverseCharArray2(char *flippedArray)
{
    int len = getstrlen(flippedArray);
    for (int start = 0; start < (len / 2); start++)
    {
        char temp = flippedArray[start];
        flippedArray[start] = flippedArray[len - start - 1];
        flippedArray[len - start - 1] = temp;
    }
}

long long absolute(long long intValue)
{
    return ((intValue < 0) ? -intValue : intValue);
}

char *addStringInt(const char *intA, const char *intB)
{
    // long long valueA = stringToInt(intA);
    // long long valueB = stringToInt(intB);
    // long long answerResult = valueA + valueB;
    // return intToCharArray(answerResult);

    int lengthA = getstrlen(intA);
    int lengthB = getstrlen(intB);

    int carry = 0, iA = lengthA - 1, iB = lengthB - 1, lenNew = 0;
    if (intA[0] == '-' && intB[0] == '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *flippedIntB = flipSignStringInt(intB);
        char *addResult = addStringInt(flippedIntA, flippedIntB);
        delete[] flippedIntA;
        delete[] flippedIntB;
        char *result = flipSignStringInt(addResult);
        delete[] addResult;
        return result;
    }
    else if (intA[0] == '-' && intB[0] != '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *result = subStringInt(intB, flippedIntA);
        delete[] flippedIntA;
        return result;
    }
    else if (intA[0] != '-' && intB[0] == '-')
    {
        char *flippedIntB = flipSignStringInt(intB);
        char *result = subStringInt(intA, flippedIntB);
        delete[] flippedIntB;
        return result;
    }
    // else if (intA[0] == '-' || intB[0] == '-')
    // {
    //     subStringInt(intA, intB);
    // }

    char *answerResult = new char[(lengthA > lengthB) ? lengthA + 1 : lengthB + 1];

    for (int i = 0; i < lengthA; i++)
    {
        answerResult[i] = '0';
    }

    for (; iA >= 0 && iB >= 0; iA--, iB--, lenNew++)
    {
        answerResult[lenNew] = ((s2int(intA[iA]) + s2int(intB[iB]) + carry) % 10) + '0';
        carry = (s2int(intA[iA]) + s2int(intB[iB]) + carry) / 10;
    }

    if (lengthA > lengthB)
    {
        while (iA >= 0)
        {
            answerResult[lenNew] = ((s2int(intA[iA]) + carry) % 10) + '0';
            carry = (s2int(intA[iA]) + carry) / 10;
            lenNew++;
            iA--;
        }
    }
    else if (lengthB > lengthA)
    {
        while (iB >= 0)
        {
            answerResult[lenNew] = ((s2int(intB[iB]) + carry) % 10) + '0';
            carry = (s2int(intB[iB]) + carry) / 10;
            lenNew++;
            iB--;
        }
    }
    else
    {
        if (carry > 0)
        {
            answerResult[lenNew] = carry;
            lenNew++;
        }
    }

    answerResult[lenNew] = '\0';

    reverseCharArray2(answerResult);

    removeZero2(answerResult);

    return answerResult;
}

char *subStringInt(const char *intA, const char *intB)
{
    // long long valueA = stringToInt(intA);
    // long long valueB = stringToInt(intB);
    // long long answerResult = valueA - valueB;
    // return intToCharArray(answerResult);

    /*
    case 1: pos - pos == pos - pos
        if pos1 > pos2, proceed
        else if pos 2 > pos 1, swap position of both int and add '-'
    case 2: neg - pos == neg + neg
        give to addstringint (flipB)
    case 3: pos - neg == pos + pos
        give to addstringint (flipB)
    case 4: neg - neg == neg + pos == pos - pos when swap position
    */

    int lengthA = getstrlen(intA);
    int lengthB = getstrlen(intB);

    char *answerResult = new char[(lengthA > lengthB) ? (lengthA + 1) : (lengthB + 1)];

    if ((lengthA < lengthB) || ((lengthA == lengthB) && (intA[0] < intB[0])))
    {
        char *result = subStringInt(intB, intA);
        char *flippedResult = flipSignStringInt(result);
        delete[] result;
        delete[] answerResult;
        return flippedResult;
    }

    if (intA[0] == '-' && intB[0] != '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *addResult = addStringInt(flippedIntA, intB);
        delete[] flippedIntA;
        char *result = flipSignStringInt(addResult);
        delete[] addResult;
        delete[] answerResult;
        return result;
    }
    else if (intA[0] != '-' && intB[0] == '-')
    {
        char *flippedIntB = flipSignStringInt(intB);
        char *result = addStringInt(intA, flippedIntB);
        delete[] flippedIntB;
        delete[] answerResult;
        return result;
    }
    else if (intA[0] == '-' && intB[0] == '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *flippedIntB = flipSignStringInt(intB);
        char *result = subStringInt(flippedIntB, flippedIntA);
        delete[] flippedIntA;
        delete[] flippedIntB;
        delete[] answerResult;
        return result;
    }

    int carry = 0, iA = lengthA - 1, iB = lengthB - 1, lenNew = 0;

    for (; iA >= 0 && iB >= 0; iA--, iB--, lenNew++)
    {
        int value = (s2int(intA[iA]) - s2int(intB[iB]) - carry);
        answerResult[lenNew] = ((value < 0) ? value + 10 : value) + '0';
        carry = (value < 0) ? 1 : 0;
    }

    if (lengthA > lengthB)
    {
        while (iA >= 0)
        {
            int value = (s2int(intA[iA]) - carry);
            answerResult[lenNew] = ((value < 0) ? value + 10 : value) + '0';
            carry = (value < 0) ? 1 : 0;
            lenNew++;
            iA--;
        }
    }
    answerResult[lenNew] = '\0';

    reverseCharArray2(answerResult);

    removeZero2(answerResult);

    return answerResult;
}

char *mulByDigitStringInt(const char *intA, int multiplier)
{
    if (multiplier == 0)
    {
        char *resultArray = new char[2];
        resultArray[0] = '0';
        resultArray[1] = '\0';
        return resultArray;
    }

    int lengthA = getstrlen(intA);
    int maxLength = lengthA + 1;

    char *resultArray = new char[maxLength + 1];
    for (int i = 0; i < maxLength; i++)
    {
        resultArray[i] = '0';
    }
    resultArray[maxLength] = '\0';

    int carry = 0;
    for (int i = lengthA - 1; i >= 0; i--)
    {
        int product = (s2int(intA[i])) * multiplier + carry;
        resultArray[i + 1] = (product % 10) + '0';
        carry = product / 10;
    }
    resultArray[0] = carry + '0';

    removeZero2(resultArray);

    return resultArray;
}

char *mulStringInt(const char *intA, const char *intB)
{
    // long long valueA = stringToInt(intA);
    // long long valueB = stringToInt(intB);
    // long long answerResult = valueA * valueB;
    // return intToCharArray(answerResult);

    int lengthA = getstrlen(intA);
    int lengthB = getstrlen(intB);
    char *answerResult = new char[lengthA + lengthB + 1];

    if (intA[0] == '-' && intB[0] != '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *mulResult = mulStringInt(flippedIntA, intB);
        delete[] flippedIntA;
        char *result = flipSignStringInt(mulResult);
        delete[] mulResult;
        delete[] answerResult;
        return result;
    }
    else if (intA[0] != '-' && intB[0] == '-')
    {
        char *flippedIntB = flipSignStringInt(intB);
        char *mulResult = mulStringInt(intA, flippedIntB);
        delete[] flippedIntB;
        char *result = flipSignStringInt(mulResult);
        delete[] mulResult;
        delete[] answerResult;
        return result;
    }
    else if (intA[0] == '-' && intB[0] == '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *flippedIntB = flipSignStringInt(intB);
        char *result = mulStringInt(flippedIntA, flippedIntB);
        delete[] flippedIntA;
        delete[] flippedIntB;
        delete[] answerResult;
        return result;
    }

    for (int i = 0; i < lengthA + lengthB; i++)
    {
        answerResult[i] = '0';
    }

    for (int i = lengthA - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = lengthB - 1; j >= 0; j--)
        {
            int product = (s2int(intA[i])) * (s2int(intB[j])) + (s2int(answerResult[i + j + 1])) + carry;
            answerResult[i + j + 1] = (product % 10) + '0';
            carry = product / 10;
        }
        answerResult[i] += carry;
    }

    answerResult[lengthA + lengthB] = '\0';

    removeZero2(answerResult);

    return answerResult;
}

char *divStringInt(const char *intA, const char *intB)
{
    if (isZero(intB))
    {
        return nullptr;
    }

    char *quotientAnswer = new char[255];

    if (intA[0] == '-' && intB[0] != '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *divResult = divStringInt(flippedIntA, intB);
        delete[] flippedIntA;
        char *result = flipSignStringInt(divResult);
        delete[] divResult;
        delete[] quotientAnswer;
        return result;
    }
    else if (intA[0] != '-' && intB[0] == '-')
    {
        char *flippedIntB = flipSignStringInt(intB);
        char *divResult = divStringInt(intA, flippedIntB);
        delete[] flippedIntB;
        char *result = flipSignStringInt(divResult);
        delete[] divResult;
        delete[] quotientAnswer;
        return result;
    }
    else if (intA[0] == '-' && intB[0] == '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *flippedIntB = flipSignStringInt(intB);
        char *result = divStringInt(flippedIntA, flippedIntB);
        delete[] flippedIntA;
        delete[] flippedIntB;
        delete[] quotientAnswer;
        return result;
    }

    long long temp = 0, divisor = stringToInt(intB);
    int i = 0, answerPointer = 0;

    while (intA[i] != '\0')
    {
        temp = temp * 10 + (s2int(intA[i]));
        if (temp >= divisor)
        {
            quotientAnswer[answerPointer] = (temp / divisor) + '0';
            answerPointer++;
            temp = temp % divisor;
        }
        else if (answerPointer > 0)
        {
            quotientAnswer[answerPointer] = '0';
            answerPointer++;
        }
        i++;
    }
    quotientAnswer[answerPointer] = '\0';

    return quotientAnswer;
}

char *modStringInt(const char *intA, const char *intB)
{
    if (isZero(intB))
    {
        return nullptr;
    }
    // long long valueA = stringToInt(intA);
    // long long valueB = stringToInt(intB);
    // long long answerResult = valueA % valueB;
    // return intToCharArray(answerResult);

    char *divResult = divStringInt(intA, intB);
    char *mulResult = mulStringInt(divResult, intB);
    char *result = subStringInt(intA, mulResult);
    delete[] divResult;
    delete[] mulResult;
    return result;
}

char *gcdStringInt(const char *intA, const char *intB)
{
    char *valueA = new char[getstrlen(intA) + 1], *valueB = new char[getstrlen(intB) + 1];

    if (intA[0] == '-')
    {
        char *flippedIntA = flipSignStringInt(intA);
        char *result = gcdStringInt(flippedIntA, intB);
        delete[] flippedIntA;
        delete[] valueA;
        delete[] valueB;
        return result;
    }
    if (intB[0] == '-')
    {
        char *flippedIntB = flipSignStringInt(intB);
        char *result = gcdStringInt(intA, flippedIntB);
        delete[] flippedIntB;
        delete[] valueA;
        delete[] valueB;
        return result;
    }

    for (int i = 0; intA[i] != '\0'; i++)
    {
        valueA[i] = intA[i];
    }
    valueA[getstrlen(intA)] = '\0';

    for (int i = 0; intB[i] != '\0'; i++)
    {
        valueB[i] = intB[i];
    }
    valueB[getstrlen(intB)] = '\0';

    if (isEqualStringInt(intA, intB))
    {
        delete[] valueB;
        return valueA;
    }
    if (isZero(intA))
    {
        delete[] valueA;
        return valueB;
    }
    if (isZero(intB))
    {
        delete[] valueB;
        return valueA;
    }

    while (!isZero(valueB))
    {
        if (isLargerThanStringInt(valueA, valueB))
        {
            char *subResult = subStringInt(valueA, valueB);
            delete[] valueA;
            valueA = subResult;
        }
        else
        {
            char *subResult = subStringInt(valueB, valueA);
            delete[] valueB;
            valueB = subResult;
        }
    }

    delete[] valueB;
    return valueA;
}