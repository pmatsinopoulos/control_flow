/*****************
 * Write a function "expand(s1, s2)" that expands sequences like "a-z" to its equivalent "abc....xyz".
 * Also deals with "0-9" similarly.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_OF_CHARACTERS 100

void expand(const char s1[], char s2[]);

int main(void) {
    char input[MAX_NUMBER_OF_CHARACTERS];
    puts(
            "Give me a string and I will expand its sequences of 'a-z', '0-9' and similar.");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = 0;

    char output[MAX_NUMBER_OF_CHARACTERS];
    expand(input, output);

    printf("Output: %s\n", output);

    return 0;
}

void expand(const char s1[], char s2[]) {
    int s1Length = strlen(s1);
    for (int i = 0, j = 0; s1[i] != 0; i++) {
        if ((s1[i] == '-') &&
            (i + 1 < s1Length) &&
            (i - 1 >= 0) &&
            (isalpha(s1[i - 1]) && isalpha(s1[i + 1]) || isdigit(s1[i - 1]) && isdigit(s1[i + 1])) &&
            s1[i - 1] < s1[i + 1]) {
                // need to generate all the characters
                for (char c = s1[i - 1] + 1; c < s1[i + 1]; c++) {
                    s2[j] = c;
                    j++;
                }
        } else {
            s2[j] = s1[i];
            j++;
        }
    }
}
