#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    char* token = strtok(input, " ");
    while (token != NULL) {
        if (isalpha(token[0]) || token[0] == '_') {
            const char* keywords[] = {"if", "else", "while", "for", "int", "float", "char", "return"};
            int isKeyword = 0;
            for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
                if (strcmp(token, keywords[i]) == 0) {
                    isKeyword = 1;
                    break;
                }
            }
            printf("'%s' is %s.\n", token, isKeyword ? "a keyword" : "an identifier");
        } else {
            printf("'%s' is not a valid token.\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}
