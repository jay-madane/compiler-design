/*

Generate the C code from the Lex file:
flex pro3.l

Compile the generated C code:
gcc lex.yy.c -o pro3 -lfl

Run the compiled program, providing the input and output file names:
./pro3 input.txt output.txt

*/


%{
#include <stdio.h>
#include <stdlib.h>

int char_count = 0;
int word_count = 0;
int line_count = 0;
FILE *outfile;
%}

%%
\n       { line_count++; char_count++; fprintf(outfile, "%d: %s", line_count, yytext); }
[ \t]+   { char_count += yyleng; }
\w+      { word_count++; char_count += yyleng; }
.        { char_count++; }
%%

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *infile = fopen(argv[1], "r");
    if (!infile) {
        perror("Unable to open input file");
        exit(1);
    }

    outfile = fopen(argv[2], "w");
    if (!outfile) {
        perror("Unable to open output file");
        fclose(infile);
        exit(1);
    }

    yyin = infile;
    yylex();

    fprintf(outfile, "\nNumber of characters: %d\n", char_count);
    fprintf(outfile, "Number of words: %d\n", word_count);
    fprintf(outfile, "Number of lines: %d\n", line_count);

    fclose(infile);
    fclose(outfile);
    
    return 0;
}
