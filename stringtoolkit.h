#include<stdio.h>

void to_uppercase(char *str){
    int i = 0;
    while (str[i] != '\0') {
        // Check if the character is lowercase alphabet
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');  // Convert to uppercase
        }
        i++;
    }
}

void toLowerCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        // Check if the character is uppercase alphabet
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');  // Convert to lowercase
        }
        i++;
    }
}
int countVowels(char *str) {
    int i = 0, count = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        // Convert uppercase to lowercase manually for simplicity
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A');
        }
        // Check if character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        i++;
    }
    return count;
}
void removeNewline(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
void reverseString(char *str) {
    int start = 0, end = 0;
    // Find the length of the string manually
    while (str[end] != '\0') {
        end++;
    }
    // Move back to the last valid character (excluding newline or '\0')
    end--;
    // If there's a newline character from fgets, exclude it
    if (str[end] == '\n') {
        str[end] = '\0';
        end--;
    }
    // Swap characters from both ends
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

// Function to compare two strings manually
int compareStrings(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Function to copy one string into another manually
void copyString(char *dest, char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
}

// Function to swap two strings in the array
void swapStrings(char str1[], char str2[]) {
    char temp[100];
    copyString(temp, str1);
    copyString(str1, str2);
    copyString(str2, temp);
}

// Function to sort array of strings alphabetically
void sortStrings(char arr[][100], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (compareStrings(arr[j], arr[j + 1]) > 0) {
                swapStrings(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to get length of string
int getLength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to reverse characters between two indices
void reverse(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

// Function to reverse the order of words in a string
void reverseWords(char *str) {
    int len = getLength(str);

    // Remove newline if present
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // Step 1: Reverse the whole string
    reverse(str, 0, len - 1);

    // Step 2: Reverse each word
    int start = 0, end = 0;
    while (str[end] != '\0') {
        if (str[end] == ' ') {
            reverse(str, start, end - 1);
            start = end + 1;
        }
        end++;
    }
    // Reverse the last word
    reverse(str, start, end - 1);
}