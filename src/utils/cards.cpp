#include <iostream>
#include <cstring>
#include <set>
using namespace std;

bool splitCards(string str, char sep, string cardArr[4]){
    // Initialize
    int strLen = str.length();
    int j = 0;
    int count = 0;

    // Iterasi untuk split
    for(int i = 0; i < strLen+1; i++){
        if (count > 3){
            return false;
        }
        if (str[i] == sep || i == strLen){
            string substr = "";
            substr.append(str, j, i-j);
            cardArr[count] = substr;
            count ++;
            j = i + 1 ;
        }
    }
    return (count == 4);   
}

bool validateCards(string cardArr[4], int numArr[4]){
    // Initialize
    int strLen;

    for(int i=0; i<4; i++){
        // cout << cardArr[i][0] << "\n";
        // Validasi jika bukan Char
        strLen = cardArr[i].length();
        if (strLen > 1 && cardArr[i] != "10"){
            return false;
        }
        // Jika char
        if (cardArr[i] == "A"){
            numArr[i] = 1;
        } else if (cardArr[i] == "J"){
            numArr[i] = 11;
        } else if (cardArr[i] == "Q"){
            numArr[i] = 12;
        } else if (cardArr[i] == "K"){
            numArr[i] = 13;
        }
        // Jika number
        else if (cardArr[i] == "10"){
            numArr[i] = 10;
        } else if (cardArr[i][0] > 49 && cardArr[i][0] < 59){
            numArr[i] = cardArr[i][0] - 48;
        }
        // lainnya
        else {return false;}  
    }
    return true;
}

string numToCards(int numCard){
    if (numCard == 1){
        return "A";
    } else if(numCard == 11){
        return "J";
    } else if(numCard == 12){
        return "Q";
    } else if(numCard == 13){
        return "K";
    } else { return(to_string(numCard));}
}


// CARDS
void randCards(int ArrNum[4]){
    // Use current time as seed for random generator
    srand(time(0));
    int ub = 13;
    int lb = 1;
    for (int i = 0; i < 4; i++){
        ArrNum[i] = (rand() % (ub - lb + 1)) + lb;
    }
}

void inputCards(int ArrNum[4]){
    // Initialize
    string cardString;
    string ArrStr[4];
    bool cardValid;

    // Input Kartu
    do {
        // Masukkan inout
        cout << "\nMasukkan 4 kartu: ";     
        getline(cin, cardString);

        // Validasi Input
        cardValid = splitCards(cardString, ' ', ArrStr);
        if (cardValid){
            cardValid = validateCards(ArrStr, ArrNum);
        } 
        if (!cardValid) { cout << "Masukan salah! Coba lagi. \n";}
    } while (!cardValid);
}
