/******
 * Reverses a string in place
 *
 */
#include <stdio.h>
#include <string.h>

void reverseStringInPlace(char s[]);

int main(void) {
    char input[1000];
    printf("Give me a string and I will reverse it in place: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = 0;

    reverseStringInPlace(input);

    printf("Reversed string: %s\n", input);

    return 0;
}

void reverseStringInPlace(char s[]) {
    for(int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char t = s[j];
        s[j] = s[i];
        s[i] = t;
    }
}
