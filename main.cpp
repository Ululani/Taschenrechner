#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

int main() {
    while (true) {
        double zahl1 = 0 , zahl2 = 0, ergebnis = 0;
        char rechenzeichen;

        cout << "\n Gib eine Rechenaufgabe ein oder beende das Programm mit 'exit': ";
        string eingabe;
        cin >> eingabe;

        // Beenden Überprüfen
        if (eingabe == "exit") {
            break;
        }

        // ( Input prüft ob zahl) wenn nicht dann Fehlermeldung
        istringstream eingabeStream(eingabe);
        if (!(eingabeStream >> zahl1 >> rechenzeichen >> zahl2)) {
            cout << "Ungültige Eingabe, bitte erneut eingeben.\n";
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
                ergebnis = zahl1 / zahl2;
                break;

            default:
                cout << "unbekanntes Rechenzeichen\n";
                return 1;
        }

        cout << zahl1 << " " << rechenzeichen << " " << zahl2 << " = " << ergebnis << " \n";
    }
}