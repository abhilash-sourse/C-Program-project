#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int is_palindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric chars if any (optional)
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;

        if (tolower(str[left]) != tolower(str[right]))
            return 0; // Not palindrome

        left++;
        right--;
    }
    return 1; // Palindrome
}

int main() {
    char input[MAX_LEN];
    char choice;

    printf("Palindrome Checker\n");

    do {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline if present
        input[strcspn(input, "\n")] = 0;

        if (is_palindrome(input)) {
            printf("\"%s\" is a palindrome.\n", input);
        } else {
            printf("\"%s\" is not a palindrome.\n", input);
        }

        printf("Check another string? (y/n): ");
        choice = getchar();
        while (getchar() != '\n'); // clear input buffer
    } while (choice == 'y' || choice == 'Y');

    printf("Exiting Palindrome Checker.\n");
    return 0;
}