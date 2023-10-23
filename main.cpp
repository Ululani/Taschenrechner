#include <iostream>
#include <limits>
#include <string>
#include <sstream>

unsigned int ggT(int zahl1, int zahl2);

using namespace std;

int main() {
    cout << R"(
       *****************************************************************************

       Taschenrechner mini Version

       *****************************************************************************
       Gib eine kleine Berechnungsoperation ein, wie zum Beispiel
       5 + 3
       4564 / 2

       Folgende Operationen sind machbar: +, -, *, /, g (ggT)
       *****************************************************************************

       )";

    while (true) {
        int zahl1 = 0, zahl2 = 0, ergebnis = 0;
        char rechenzeichen;

        // cout << "\nGib eine Rechenaufgabe ein oder beende das Programm mit 'exit':";
        cout << R"(
       ==============
       Deine Eingabe:
       )" << endl;

        string eingabe;
        cin >> eingabe;

        // Beenden Überprüfen
        if (eingabe == "exit") {
            break;
        }


        // ( Input prüft ob zahl) wenn nicht dann Fehlermeldung
        istringstream eingabeStream(eingabe);
        if (!(eingabeStream >> zahl1 >> rechenzeichen >> zahl2)) {
            cout << "Ungueltige Eingabe, bitte erneut eingeben.\n";
            cin.clear(); // wird verwendet um den Fehlerzustand zurückzusetzen
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // löscht jeglichen input der bei zahl1 war
            continue;
        }


        switch (rechenzeichen) {
            case '+':
                ergebnis = zahl1 + zahl2;
                break;
            case '-':
                ergebnis = zahl1 - zahl2;
                break;
            case '*':
                ergebnis = zahl1 * zahl2;
                break;
            case '/':
                if (zahl2 != 0) {
                    ergebnis = zahl1 / zahl2;
                } else {
                    cout << "Division durch Null ist nicht erlaubt";
                    continue;
                }
                break;

            case 'g':
                ergebnis = ggT(zahl1, zahl2);
               break;

            default:
                cout << "unbekanntes Rechenzeichen\n";
                return 1;
                }

                // Ausgabe des Ergebnisses
                cout << zahl1 << " " << rechenzeichen << " " << zahl2 << " = " << ergebnis << " \n";
        }
    }


// Definition der Funktion zum Berechnen des ggT (größten gemeinsamen Teilers)
unsigned int ggT(int zahl1, int zahl2) {
    if (zahl2 == 0) {
        return zahl1;
    }
    return ggT(zahl2, zahl1 % zahl2);
}