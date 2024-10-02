#ifndef STRING_INTEGER_H
#define STRING_INTEGER_H

// returns string length (not including '\0')
int getstrlen(const char* str);


// returns whether intA == 0 in bool
bool isZero(const char* intA);


// returns (intA == intB) in bool
bool isEqualStringInt(const char* intA, const char* intB);


// returns (-intA) by returning a dynamically allocated char array pointer
char* flipSignStringInt(const char* intA);


// returns (intA > intB) in bool
bool isLargerThanStringInt(const char* intA, const char* intB);


// returns (intA * 10^exp) by returning a dynamically allocated char array pointer
char* mulPowerOfTenStringInt(const char* intA, int exp);


// returns (intA + intB) by returning a dynamically allocated char array pointer
char* addStringInt(const char* intA, const char* intB);


// returns (intA - intB) by returning a dynamically allocated char array pointer
char* subStringInt(const char* intA, const char* intB);


// returns (intA * multiplier) by returning a dynamically allocated char array pointer
char* mulByDigitStringInt(const char* intA, int multiplier);


// returns (intA * intB) by returning a dynamically allocated char array pointer
char* mulStringInt(const char* intA, const char* intB);


// returns (intA / intB) by returning a dynamically allocated char array pointer
char* divStringInt(const char* intA, const char* intB);


// returns (intA % intB) by returning a dynamically allocated char array pointer
char* modStringInt(const char* intA, const char* intB);


// returns gcd(intA, intB) by returning a dynamically allocated char array pointer
char* gcdStringInt(const char* intA, const char* intB);


#endif