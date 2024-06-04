/*

flex replace_abc.l
gcc lex.yy.c -o replace_abc -lfl
./replace_abc input.txt output.txt

*/


%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int char_count = 0;
int word_count = 0;
int line_count = 0;
int ignore_line = 0;
FILE *outfile;

void update_counts(char *str);
%}

%%
#.*        { ignore_line = 1; /* Ignore this line */ }
\n         { line_count++; ignore_line = 0; fprintf(outfile, "%s", yytext); }
[ \t\r]+   { if (!ignore_line) { char_count += yyleng; fprintf(outfile, "%s", yytext); } }
[a-zA-Z]+  { if (!ignore_line) { update_counts(yytext); } }
.          { if (!ignore_line) { char_count++; fprintf(outfile, "%c", yytext[0]); } }
%%

void update_counts(char *str) {
    int len = strlen(str);
    char_count += len;
    word_count++;
    
    char *pos = str;
    while ((pos = strstr(pos, "abc")) != NULL) {
        fwrite(str, pos - str, 1, outfile);
        fwrite("ABC", 3, 1, outfile);
        str = pos + 3;
        pos = str;
    }
    fprintf(outfile, "%s", str);
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

    fprintf(outfile, "\n\nTotal number of characters: %d\n", char_count);
    fprintf(outfile, "Total number of words: %d\n", word_count);
    fprintf(outfile, "Total number of lines: %d\n", line_count);

    fclose(infile);
    fclose(outfile);

    return 0;
}
