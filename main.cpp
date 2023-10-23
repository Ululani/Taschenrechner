#include <iostream>

using namespace std;

int main() {
    double zahl1, zahl2, ergebnis;
    char rechenzeichen;

    cout << "Gib eine Rechenaufgabe ein: ";
    cin >> zahl1 >> rechenzeichen >> zahl2;

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

    cout << zahl1 << rechenzeichen << zahl2 << " = " << ergebnis;
}