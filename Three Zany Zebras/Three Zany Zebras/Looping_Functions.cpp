// Student ID:20511457
//
// Looping_Functions.cpp
//
// Created by Anand Venkataraman on 8/9/19.
// Copyright © 2019 Anand Venkataraman. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// Miniquest 1: Guess it
bool play_game(int n) {
    cout << "Welcome to my number guessing game" << endl << endl;
    for (int i = 1; i <= 6; i++) {
        cout << "Enter your guess: " << endl;;
        string input;
        getline(cin, input);
        istringstream iss(input);
        int guess;
        if (!(iss >> guess)) {
            guess = 0;
        }
        cout << "You entered: " << guess << endl;
        if (guess == n) {
            cout << "You found it in " << i << " guess(es)." << endl ;
            return true;
        }
    }
    cout << endl << "I'm sorry. You didn't find my number." << endl;
    cout << "It was " << n << endl;
    return false;
}


// Miniquest 2: Etox
double etox(double x, size_t n)
{
    if (n == 0) {
        return 0.0; // 当 n 为 0 时，直接返回 0
    }

    double sum = 1.0; // 初始项为 1

    for (size_t i = 1; i < n; i++) // 从 1 开始迭代，直到 i < n
    {
        double term = 1.0; // 初始化项为 1.0
        for (size_t j = 1; j <= i; j++) // 计算 x 的 i 次幂除以 i 的阶乘
        {
            term *= x / j;
        }
        sum += term; // 将项加到总和中
    }
    return sum;
}




// Miniquest 3: Char counts
size_t count_chars(string s, char c) {
    size_t count = 0;
    for (char& ch : s) {
        if (ch == c) {
            count++;
        }
    }
    return count;
}

// Miniquest 4: Greatest Common Divisor
size_t gcd(size_t a, size_t b) {
    while (b != 0) {
        size_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Miniquest 5: Terms of an AP
string get_ap_terms(int a, int d, size_t n) {
    stringstream ss;
    for (size_t i = 0; i < n; i++) {
        if (i > 0) {
            ss << ","; // 在项之间添加逗号
        }
        int currentTerm = a + static_cast<int>(i) * d; // 使用有符号整数计算当前项
        ss << currentTerm;
    }
    return ss.str();
}


// Miniquest 6: Terms of a GP
string get_gp_terms(double a, double r, size_t n) {
    string result = to_string(a);
    for (size_t i = 1; i < n; i++) {
        result += ",";
        result += to_string(a * pow(r, i));
    }
    return result;
}

// Miniquest 7: Fibonacci
double get_nth_fibonacci_number(size_t n) {
    double a = 1.0, b = 1.0;
    for (size_t i = 3; i <= n; i++) {
        double c = a + b;
        a = b;
        b = c;
    }
    return b;
}
