#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int prime = 101; // Prime number for hashing

// Function to calculate hash value for a substring
int calculateHash(const string& str, int len) {
    int hash = 0;
    for (int i = 0; i < len; ++i) {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

// Function to update hash value based on rolling hash
int recalculateHash(int oldHash, char oldChar, char newChar, int len) {
    int newHash = oldHash - oldChar;
    newHash /= prime;
    newHash += newChar * pow(prime, len - 1);
    return newHash;
}

// Function to check if substrings match
bool checkEqual(const string& str1, int start1, int end1, const string& str2, int start2, int end2) {
    if (end1 - start1 != end2 - start2)
        return false;
    while (start1 <= end1 && start2 <= end2) {
        if (str1[start1] != str2[start2])
            return false;
        ++start1;
        ++start2;
    }
    return true;
}

// Rabin-Karp string matching algorithm
void rabinKarpSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    int patternHash = calculateHash(pattern, m);
    int textHash = calculateHash(text, m);

    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == textHash && checkEqual(text, i, i + m - 1, pattern, 0, m - 1)) {
            cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m) {
            textHash = recalculateHash(textHash, text[i], text[i + m], m);
        }
    }
}

int main() {
    string text = "AABABAABA";
    string pattern = "AABA";
    rabinKarpSearch(text, pattern);
    return 0;
}