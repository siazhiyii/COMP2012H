#include <iostream>
using namespace std;

#include "kiosk.h"

int main() {
    Kiosk* kiosk = createKiosk();

    addItem(kiosk, Item{"Guitar, Loneliness and Blue Planet", SONG, 10});
    addItem(kiosk, Item{"Never Gonna Give You Up", SONG, 20});
    addItem(kiosk, Item{"Yorunikakeru", SONG, 20});
    addItem(kiosk, Item{"Chipi Chipi Chapa Chapa", SONG, 5});

    addItem(kiosk, Item{"Pokemon", BOOK, 40});
    addItem(kiosk, Item{"Doraemon", BOOK, 40});
    addItem(kiosk, Item{"Avangers", BOOK, 72});
    addItem(kiosk, Item{"Oshi no Ko", BOOK, 55});

    addItem(kiosk, Item{"Hatsune Miku", FIGURE, 210});
    addItem(kiosk, Item{"Mickey Mouse", FIGURE, 150});
    addItem(kiosk, Item{"Luffy", FIGURE, 175});

    addItem(kiosk, Item{"Elden Ring", GAME, 320});
    addItem(kiosk, Item{"Minecraft", GAME, 210});
    addItem(kiosk, Item{"Genshin Impact", GAME, 40});

    cout << "The kiosk is currently selling:" << endl;
    printMenu(kiosk);

    sort(kiosk);
    cout << "The kiosk has re-ordered the items:" << endl;
    printMenu(kiosk);

    removeItem(kiosk, Item{"Never Gonna Give You Up", SONG, 20});
    removeItem(kiosk, Item{"Hatsune Miku", FIGURE, 210});
    removeItem(kiosk, Item{"Oshi no Ko", BOOK, 55});

    addItem(kiosk, Item{"Baba Is You", GAME, 40});
    addItem(kiosk, Item{"Tower of Flower", SONG, 25});
    addItem(kiosk, Item{"The Time I Got Reincarnated as a Slime", BOOK, 60});

    sort(kiosk);
    cout << "The kiosk has re-stocked:" << endl;
    printMenu(kiosk);

    deleteKiosk(kiosk);
}