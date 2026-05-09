#include <iostream>
#include <cstring>
using namespace std;

// Function to compute LPS array
void computeLPS(const char* pattern, int m, int* lps) {
    int length = 0; // length of previous longest prefix suffix
    lps[0] = 0;     // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; // fall back
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMPSearch(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m]; // LPS array
    computeLPS(pattern, m, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // look for next match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    const char* text = "ABABDABACDABABCABAB";
    const char* pattern = "ABABCABAB";

    KMPSearch(text, pattern);

    return 0;
}
