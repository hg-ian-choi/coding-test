#include <string.h>

void swap(char* left, char* right) {
    char temp;
    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    int length = strlen(s);
    char* start = s;

    for (int i = 0; i <= length; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            swap(start, &s[i - 1]);
            start = &s[i + 1];
        }
    }

    return s;
}

// Solution
void reverseWord(char* start, char* end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

char* solution(char* s) {
    int length = strlen(s);
    char* start = s;

    for (int i = 0; i <= length; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverseWord(start, &s[i - 1]);
            start = &s[i + 1];
        }
    }

    return s;
}
