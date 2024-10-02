#ifndef STRING_RATIONAL_H
#define STRING_RATIONAL_H

#include "integer.h"

// returns (intA / intB) in simplest rational form by returning a dynamically allocated char array pointer
char* stringIntsToRation(const char* numerator, const char* denominator);


// returns the numerator & denominator of a rational string
// by returning two dynamically allocated char array pointer of string integer by reference
void stringRationToInts(const char* rationA, char* &numerator, char* &denominator);


// returns (rationA + rationB) by returning a dynamically allocated char array pointer
char* addStringRation(const char* rationA, const char* rationB);


// returns (rationA - rationB) by returning a dynamically allocated char array pointer
char* subStringRation(const char* rationA, const char* rationB);


// returns (rationA * rationB) by returning a dynamically allocated char array pointer
char* mulStringRation(const char* rationA, const char* rationB);


// returns (rationA / rationB) by returning a dynamically allocated char array pointer
char* divStringRation(const char* rationA, const char* rationB);


// ============= Bonus from now on ================


// returns the simplest rational form of a decimal by returning a dynamically allocated char array pointer
char* stringDecimalToRation(const char* decimal);


// returns the decimal form of a rational number (rounded to nearest `dp` decimal places) by returning a dynamically allocated char array pointer
char* stringRationToDecimal(const char* ration, int dp);


#endif