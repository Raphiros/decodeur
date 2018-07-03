/*

This program was made for the computer badge of the Europe Scout.
Program finished on 03 July 2018.
Program created and edited by Raphael CHAROZE.

All rights reserved.

*/


// HEADERS

#include <iostream>
#include <fstream>
#include <map>
#include <string>

// NAMESPACES

using namespace std;

// initializing container for the morse code reference

map < string,string> code_morse;

int main() {

    // giving the computer the morse code reference to encode

    code_morse ["a"] = ".-";
    code_morse ["b"] = "-...";
    code_morse ["c"] = "-.-.";
    code_morse ["d"] = "-..";
    code_morse ["e"] = ".";
    code_morse ["f"] = "..-.";
    code_morse ["g"] = "--.";
    code_morse ["h"] = "....";
    code_morse ["i"] = "..";
    code_morse ["j"] = ".---";
    code_morse ["k"] = "-.-";
    code_morse ["l"] = ".-..";
    code_morse ["m"] = "--";
    code_morse ["n"] = "-.";
    code_morse ["o"] = "---";
    code_morse ["p"] = ".--.";
    code_morse ["q"] = "--.-";
    code_morse ["r"] = ".-.";
    code_morse ["s"] = "...";
    code_morse ["t"] = "-";
    code_morse ["u"] = "..-";
    code_morse ["v"] = "...-";
    code_morse ["w"] = ".--";
    code_morse ["x"] = "-..-";
    code_morse ["y"] = "-.--";
    code_morse ["z"] = "--..";
    code_morse ["0"] = "-----";
    code_morse ["1"] = ".----";
    code_morse ["2"] = "..---";
    code_morse ["3"] = "...--";
    code_morse ["4"] = "....-";
    code_morse ["5"] = ".....";
    code_morse ["6"] = "-....";
    code_morse ["7"] = "--...";
    code_morse ["8"] = "---..";
    code_morse ["9"] = "----.";
    code_morse [" "] = "/";

    // chosing text to encode and saving it in a file if file is open

    string texte;
    string nomficheracoder;

    cout << "comment voulez vous appeler votre fichier?";
    getline(cin,nomficheracoder);
    cout << endl << "Que voulez vous coder en morse?";
    getline(cin,texte);
    char texteatrad;

    string const cheminfichier(nomficheracoder);
    ofstream fichier (cheminfichier.c_str(),ios::app);

    if (fichier){

        fichier << texte <<endl;
        ifstream fichier2 (cheminfichier.c_str());

        while (fichier2.get(texteatrad)){

            string texteatradcopie;
            texteatrad = tolower(texteatrad);
            texteatradcopie = texteatrad;

            if (code_morse.count(texteatradcopie)== 1){
                fichier << code_morse[texteatradcopie] << " ";
            }
            else {
                   fichier << texteatradcopie << " ";
            }
        }
    }
    else {
        cerr << "ERROR : ouverture du fichier impossible" << endl;
    }
    return 0;
}
