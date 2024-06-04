/*

Run these commands:

flex word_count.l
gcc lex.yy.c -o word_count -lfl
./word_count input.txt output.txt

*/


%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int vowel_word_count = 0;
int total_word_count = 0;
FILE *outfile;
char buffer[1024];
%}

%%
[aA]([a-zA-Z]*) { handle_vowel_word(yytext); }
[eE]([a-zA-Z]*) { handle_vowel_word(yytext); }
[iI]([a-zA-Z]*) { handle_vowel_word(yytext); }
[oO]([a-zA-Z]*) { handle_vowel_word(yytext); }
[uU]([a-zA-Z]*) { handle_vowel_word(yytext); }
[A-Za-z]+ { total_word_count++; strcpy(buffer, yytext); fprintf(outfile, "%s", buffer); }
[^A-Za-z]+ { fprintf(outfile, "%s", yytext); }
%%

void handle_vowel_word(char *word) {
    total_word_count++;
    vowel_word_count++;
    snprintf(buffer, sizeof(buffer), "%s%d", word, vowel_word_count);
    fprintf(outfile, "%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if (!infile) {
        perror("Unable to open input file");
        return 1;
    }

    outfile = fopen(argv[2], "w");
    if (!outfile) {
        perror("Unable to open output file");
        fclose(infile);
        return 1;
    }

    yyin = infile;
    yylex();

    fprintf(outfile, "\nTotal number of words: %d\n", total_word_count);
    fprintf(outfile, "Number of words starting with a vowel: %d\n", vowel_word_count);

    fclose(infile);
    fclose(outfile);
    
    return 0;
}
