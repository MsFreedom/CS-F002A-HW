// Student ID: 20511457
// Eliza.cpp
// 2a.Lab-05-Eliza
//
//
// Student ID: 12345678
// TODO - Replace the number above with your actual Student ID
// Eliza.cpp
// 2a.Lab-05-Eliza
//
//
#include "Eliza.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

// lispify 函数
string lispify(string s) {
    string result;
    for (char c : s) {
        if (c == 's') {
            result += "th";
        } else if (c == 'S') {
            result += "Th";
        } else {
            result += c;
        }
    }
    return result;
}

// rotate_vowels 函数
string rotate_vowels(string& s) {
    static const string vowels = "aeiouAEIOU";
    static const string rotated = "eiouaEIOUA";
    for (char& c : s) {
        size_t pos = vowels.find(c);
        if (pos != string::npos) {
            c = rotated[pos];
        }
    }
    return s;
}

// enter 函数
void enter() {
    cout << "What?\n";
    while (true) {
        string userInput;
        getline(cin, userInput);

        if (userInput.empty()) {
            cout << "What?\n";
            continue;
        }

        cout << "    " << userInput << "\n\n";

        if (userInput.find('!') != string::npos) {
            cout << "OMG! You don't say!! " << userInput << "!!!!!\n";
            continue;
        }

        if (userInput.find("why") != string::npos || userInput.find("what") != string::npos) {
            cout << "I'm sorry, I don't like questions that contain what or why.\n";
            continue;
        }

        if (userInput.find('s') != string::npos || userInput.find('S') != string::npos) {
            cout << "Interethting. When did you thtop thtopping your thibilanth?\n";
            cout << lispify(userInput) << "! Sheesh! Now what?\n";
            continue;
        }

        if (userInput == "bye" || userInput == "Bye" || userInput == "quit" || userInput == "Quit") {
            cout << "Ok Bye. Nice being a force of change in your life.\n";
            break;
        }

        int randomValue = rand() % 10;
        if (randomValue >= 8) {
            cout << "Huh? Why do you say: " << userInput << "?\n";
        } else {
            cout << rotate_vowels(userInput) << "?\n";
        }
    }
}