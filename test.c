#include <stdio.h>
#include <string.h>

int main() {
    char minhaString[] = "Esta é uma string de exemplo.";
    char arraySubstrings[][10] = {"exemplo-9", "string", "outra"};

    for (int i = 0; i < sizeof(arraySubstrings) / sizeof(arraySubstrings[0]); i++) {
        if (strstr(minhaString, arraySubstrings[i]) != NULL) {
            printf("A substring '%s' foi encontrada na string.\n", arraySubstrings[i]);
        } else {
            printf("A substring '%s' não foi encontrada na string.\n", arraySubstrings[i]);
        }
    }

    return 0;
}
