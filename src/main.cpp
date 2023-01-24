#include <iostream>
#include "./utils/decorators.cpp"
#include "./utils/operators.cpp"
#include "./utils/cards.cpp"
using namespace std;

int main(){
    // Initialize Value
    int menuOption = 0;
    int arrCardsNum[4];
    string arrCardsStr[4];
    bool gameValid = true;
    char optionValid;

    // Splash Screen
    printAscii();
    printCardsClosed();

    // Menu
    while (gameValid){
        cout << "Selamat datang di 24 Card Solver!\n\n";
        cout << "======================\n"
                "         MENU         \n"
                "======================\n";
        cout << "1. Pilih Kartu Sendiri \n"
                "2. Random aja!\n"
                "3. Keluar\n";
        
        do {
            cout << "\nPilih menu: ";
            cin >> menuOption;
            if (!cin) { // cin is not in a good state
                cerr << "Inputnya bukan angka! :(\n";
                menuOption = 3;}
   
        } while (menuOption < 1 || menuOption > 3);

        // Pemilihan menu
        switch (menuOption){
        case 1:
            // Input cards
            cin.ignore();
            inputCards(arrCardsNum);
            // Show cards
            for (int i = 0; i< 4; i++){
                arrCardsStr[i] = numToCards(arrCardsNum[i]);
            }
            cout << "Berikut kartu yang kamu pilih!\n";
            printCards(arrCardsStr[0],arrCardsStr[1],arrCardsStr[2],arrCardsStr[3]);
            cout << "\n";
            // Solve
            solvCards(arrCardsNum);
            // Round 2?
            cout << "\nIngin bermain lagi [y/n]? ";
            cin >> optionValid;
            if (optionValid != 'y'){gameValid = false;}
            else {gameValid = true;};
            break;

        case 2:
            // Cards
            randCards(arrCardsNum);
            // Show cards
            for (int i = 0; i< 4; i++){
                arrCardsStr[i] = numToCards(arrCardsNum[i]);
            }
            cout << "Berikut kartu yang kamu pilih!\n";
            printCards(arrCardsStr[0],arrCardsStr[1],arrCardsStr[2],arrCardsStr[3]);
            cout << "\n";
            // Solve
            solvCards(arrCardsNum);
            // Round 2?
            cout << "\nIngin bermain lagi [y/n]? ";
            cin >> optionValid;
            if (optionValid != 'y'){gameValid = false;}
            else {gameValid = true;};
            break;
        case 3:
            gameValid = false;
            break;
        }
    }
    cout << "\nTerimakasih telah bermain!\n";
    return 0;
}