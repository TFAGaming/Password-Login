#include <iostream>
#include <string>
using namespace std;

int attemptsChecker(int attempts, int max) {
    if (attempts == max) {
        return 1;
    } else return 0;
}

int main() {
    // The password:
    const string password = "abc123";

    string input = "";

    int attempts = 0;
    int timeout = 10;

    while (true) {
        if (timeout >= 40) {
            cout << "[!] Too much tries, this command prompt is now locked." << endl;

            system("pause");
            exit(1);
        };

        if (attemptsChecker(attempts, 3)) {
            cout << "[!] You have got a rate-limit for " << timeout << " seconds." << endl;

            _sleep(timeout * 1000); // ms

            attempts = 0;
            timeout += 10;
        };

        cout << "Enter password to access: " << endl << ">>> ";

        getline(cin, input);

        if (input == password) {
            cout << "Correct!" << endl;

            system("pause");
            exit(1);
        } else {
            cout << "Password incorrect." << endl;
            attempts++;
        };

    };

    return 0;
};
