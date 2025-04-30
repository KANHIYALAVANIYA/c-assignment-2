#include<stdio.h>
#include"stringtoolkit.h"

int main() {
    char str[200];

    // Uppercase
    printf("Enter a string to convert to UPPERCASE: ");
    fgets(str, sizeof(str), stdin);
    to_uppercase(str);
    printf("UPPERCASE: %s\n\n", str);

    // Lowercase
    printf("Enter a string to convert to lowercase: ");
    fgets(str, sizeof(str), stdin);
    toLowerCase(str);
    printf("lowercase: %s\n\n", str);

    // Count vowels
    printf("Enter a string to count vowels: ");
    fgets(str, sizeof(str), stdin);
    int vowels = countVowels(str);
    printf("Number of vowels: %d\n\n", vowels);

    // Reverse characters
    printf("Enter a string to reverse characters: ");
    fgets(str, sizeof(str), stdin);
    reverseString(str);
    printf("Reversed characters: %s\n\n", str);

    // Reverse word order
    printf("Enter a string to reverse word order: ");
    fgets(str, sizeof(str), stdin);
    reverseWords(str);
    printf("Reversed word order: %s\n\n", str);

    // Sort array of strings
    int n, i;
    char arr[100][100];

    printf("Enter number of strings to sort: ");
    scanf("%d", &n);
    getchar(); // Clear newline

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(arr[i], sizeof(arr[i]), stdin);
        removeNewline(arr[i]);
    }

    sortStrings(arr, n);

    printf("\nSorted strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}