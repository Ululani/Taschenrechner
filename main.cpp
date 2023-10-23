#include <iostream>
#include <limits>

using namespace std;

int main() {
    while (true) {
        double zahl1 , zahl2 = 0, ergebnis = 0;
        char rechenzeichen;

        cout << "\n Gib eine Rechenaufgabe ein oder beende das Programm mit 'exit': ";
        cin >> zahl1 >> rechenzeichen >> zahl2;

        /* Beenden Überprüfen
        if (zahl1 == 'exit') {
            break;
        } */



        // ( Input prüft ob zahl) wenn nicht dann Fehlermeldung
        if (!(cin >> zahl1) || !(cin >> rechenzeichen) || !(cin >> zahl2)) {
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