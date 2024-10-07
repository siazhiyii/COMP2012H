#ifndef __KIOSK_H__
#define __KIOSK_H__

#include "datatype.h"

struct Kiosk;

Kiosk* createKiosk();
void deleteKiosk(Kiosk* kiosk);

void addItem(Kiosk* kiosk, const Item& item);
bool hasItem(const Kiosk* kiosk, const Item& item);
void removeItem(Kiosk* kiosk, const Item& item);

void sort(Kiosk* kiosk);
void printType(const Kiosk* kiosk, ItemType type);
void printMenu(const Kiosk* kiosk);

#endif // __KIOSK_H__