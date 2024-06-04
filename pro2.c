/* 

Compilation: 
gcc lexer.c -o lexer
./lexer

Ensure input.txt contains the source code to tokenize.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 32

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_IDENTIFIER_LENGTH];
} Token;

const char *keywords[] = {"if", "else", "while", "return", "int", "float"};
const int num_keywords = 6;

int isKeyword(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void getNextToken(FILE *file, Token *token) {
    int ch;
    int i = 0;

    // Skip whitespace and comments
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) continue;
        if (ch == '/') {
            ch = fgetc(file);
            if (ch == '/') {
                while ((ch = fgetc(file)) != '\n' && ch != EOF);
            } else if (ch == '*') {
                while (1) {
                    ch = fgetc(file);
                    if (ch == EOF) break;
                    if (ch == '*') {
                        ch = fgetc(file);
                        if (ch == '/') break;
                    }
                }
            } else {
                ungetc(ch, file);
                ch = '/';
                break;
            }
        } else {
            break;
        }
    }

    if (ch == EOF) {
        token->type = TOKEN_UNKNOWN;
        return;
    }

    if (isalpha(ch)) {
        token->value[i++] = ch;
        while ((ch = fgetc(file)) != EOF && (isalnum(ch) || ch == '_')) {
            if (i < MAX_IDENTIFIER_LENGTH - 1) {
                token->value[i++] = ch;
            }
        }
        token->value[i] = '\0';
        if (isKeyword(token->value)) {
            token->type = TOKEN_KEYWORD;
        } else {
            token->type = TOKEN_IDENTIFIER;
        }
        if (ch != EOF) {
            ungetc(ch, file);
        }
    } else if (isdigit(ch)) {
        token->value[i++] = ch;
        while ((ch = fgetc(file)) != EOF && isdigit(ch)) {
            if (i < MAX_IDENTIFIER_LENGTH - 1) {
                token->value[i++] = ch;
            }
        }
        token->value[i] = '\0';
        token->type = TOKEN_NUMBER;
        if (ch != EOF) {
            ungetc(ch, file);
        }
    } else if (ispunct(ch)) {
        token->value[i++] = ch;
        token->value[i] = '\0';
        token->type = TOKEN_OPERATOR;
    } else {
        token->value[i++] = ch;
        token->value[i] = '\0';
        token->type = TOKEN_UNKNOWN;
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    Token token;
    while (1) {
        getNextToken(file, &token);
        if (token.type == TOKEN_UNKNOWN && token.value[0] == '\0') {
            break;
        }
        printf("Token: %s, Type: %d\n", token.value, token.type);
    }

    fclose(file);
    return 0;
}
