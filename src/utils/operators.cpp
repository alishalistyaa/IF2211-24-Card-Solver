#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <set>
using namespace std;

// WRITE TO FILE
void writeSolutions(set <string> StrRes, string filename){
    // Buka file 
    ofstream fw("./test/"+filename +".txt");
    if (fw.is_open()){
        auto it = StrRes.begin();
        while (it != StrRes.end()){
            fw << (*it) << "\n";
            it++;
        }
        fw.close();
    }
    else { cout << "Ada kesalahan pembukaan file!";}
}

// Solve Operators
double solvOps(char ops, double a, double b){
    if (ops == '/' && b == 0){
        return 0;
    } else if (ops == '/'){
        return a / b;
    } else if (ops == '+'){
        return a + b;
    } else if (ops == '-'){
        return a - b;
    } else if (ops == '*'){
        return a * b;
    } else {
        return 0;
    }
}

int solvCards(int ArrCards[4]){
    // Initialize solutions
    int solutions = 0;
    char optionSave;
    // Initialize number arrays
    double Num1[4];
    double Num2[3];
    double Num3[2];
    double res[1];
    // Initialize string arrays
    string Str1[4];
    string Str2[3];
    string Str3[2];
    string Str4[1];
    // Initialize set results
    set <string> StrRes;
    // Initialize operators
    char ops[4] = {'/', '*', '-', '+'};

    // Initialize number
    for (int i=0; i<4; i++){
        Num1[i] = ArrCards[i];
    }

    // Initializing Strings
    Str1[0] = to_string(ArrCards[0]);
    Str1[1] = to_string(ArrCards[1]);
    Str1[2] = to_string(ArrCards[2]);
    Str1[3] = to_string(ArrCards[3]);
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

        // Looping operators
    for(int a=0; a<4; a++){
        for(int b=0; b<4; b++){
            for(int c=0; c<4; c++){

                    // Solve iterasi pertama
                        for (int i=0; i<4; i++){
                            for(int j=0; j<4; j++){
                                for(int k=0; k<4; k++){
                                    for(int l=0; l<4; l++){
                                        if((i != j) && (i != k) && (i != l) && (j != k) && (j != l) && (k != l)){
                                            // cout << Num1[0] << Num1[1] << Num1[2] << Num1[3];
                                            // Generalized Solution
                                            // Masukkan number ke array
                                            double res1 = solvOps(ops[a], Num1[i], Num1[j]);
                                            Num2[0] = res1;
                                            Num2[1] = Num1[k];
                                            Num2[2] = Num1[l];
                                            // Masukkan char ke array string
                                            Str2[0] = "(" + Str1[i] + " " + ops[a] + " " + Str1[j] + ")";
                                            Str2[1] = Str1[k];
                                            Str2[2] = Str1[l];
                                            
                                            // Solve iterasi kedua
                                            for(int h=0; h<3; h++){
                                                for(int g=0; g<3; g++){
                                                    for(int f=0; f<3; f++){
                                                        if((g != h) && (g != f) && (h != f)){

                                                            // Menghitung
                                                            double res2 = solvOps(ops[b], Num2[h], Num2[g]);
                                                            Num3[0] = res2;
                                                            Num3[1] = Num2[f];
                                                            // Masukkan char ke array string
                                                            Str3[0] = "(" + Str2[h] + " " + ops[b] + " " + Str2[g] + ")";
                                                            Str3[1] = Str2[f];

                                                            // Solve iterasi ketiga
                                                            for (int y=0; y<2; y++){
                                                                for(int x=0; x<2; x++){
                                                                    if((y != x)){
                                                                        // Solve results
                                                                        res[0] = solvOps(ops[c], Num3[y], Num3[x]);
                                                                        // Masukkan char ke array string
                                                                        Str4[0] = Str3[y] + " " + ops[c] + " " + Str3[x];
                                                                        // cout << Str4[0] << "\n";

                                                                        if (res[0] <= 24.1 && res[0] >= 23.9){
                                                                            StrRes.insert(Str4[0]);
                                                                        }
                                                                    }
                                                                }   
                                                            } 
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
            }
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Terdapat: " << StrRes.size() << " solusi\n";
    auto it = StrRes.begin();
    while (it != StrRes.end()){
        cout << (*it) << "\n";
        // cout << (solutions) << "\n";
        it++;
    }
    
    double time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    cout << "Time elapsed: " << time_elapsed / 1000000000 << " s" << std::endl;

    // Save
            cout << "\nSimpan [y/n]? ";
            cin >> optionSave;
            if (optionSave == 'y'){
                string filename;
                cin.ignore();
                cout << "Masukkan nama file: ";
                getline(cin, filename);
                writeSolutions(StrRes, filename);}
            else {cout << "Ok! Tidak menyimpan\n";}

    return 0;
}