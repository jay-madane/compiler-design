# Compiler Design Practical Programs

This repository contains the lab codes for practical implementations of various concepts from compiler design.

### 1. Write a program to count number of lines, tabs, spaces, words, characters from a given text file.

input.txt :
```
This is a sample text file.
It contains multiple lines
and    tabs.
```

output:
```
Number of lines: 3
Number of tabs: 1
Number of spaces: 10
Number of words: 9
Number of characters: 59
```

### 2. Implement the Lexical analyzer for the a language. The lexical analyzer should ignore redundant spaces, tabs and new lines. It should also ignore comments. Although the syntax specification states that identifiers can be arbitrarily long, you may restrict the length to some reasonable value.

Refer code for example.

### 3. Write a lex program to count number of characters, words and lines in a given input text file. Create an output text file that consists of the content of the input file as well as line numbers.

input.txt :
```
Hello, this is a sample text.
It contains multiple lines.
This is the third line.
```

output.txt :
```
1: Hello, this is a sample text.
2: It contains multiple lines.
3: This is the third line.
Number of characters: 73
Number of words: 13
Number of lines: 3
```

### 4. Write LEX specifications and necessary C code that reads English words from a text file and calculates the count of words that starts with a vowel. The program appends the current value of the counter to every occurrences of such word. The program should also compute total numbers of words read.

input.txt :
```
An apple a day keeps the doctor away.
Everyone should have access to education.
```

output.txt :
```
An1 apple2 a3 day keeps the doctor away.
Everyone4 should have access5 to education.
Total number of words: 13
Number of words starting with a vowel: 5
```

### 5. Write LEX specifications and necessary C code that reads English words from a text file and replaces every occurrence of the sub string ‘abc’ with ‘ABC’. The program should also compute number of characters, words and lines read. It should not consider and count any line(s) that begin with a symbol “#”.

input.txt :
```
# This line should be ignored
abcdef
This is a test abc line.
abc abc abc
```

output.txt :
```
ABCdef
This is a test ABC line.
ABC ABC ABC
Total number of characters: 46
Total number of words: 9
Total number of lines: 3
```

### 6. Write a program for code optimization.

Code for demonstrating optimizations like constant folding, dead code elimination and strength reduction.

### 7. Write a program for code generation.

Example Output:
Code for the arithmetic expression a = b + c * d

```
#include <iostream>
int main() {
    int a, b, c, d;
    std::cout << "Enter values for b, c, d: ";
    std::cin >> b >> c >> d;
    a = b + c * d;
    std::cout << "Result: " << a;
    return 0;
}
```
