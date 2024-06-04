#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    // File path
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return 1;
    }

    int lines = 0, tabs = 0, spaces = 0, words = 0, characters = 0;
    char ch;
    bool inWord = false;

    while (file.get(ch)) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (ch == '\t') {
            tabs++;
        }
        if (ch == ' ') {
            spaces++;
        }
        if (isspace(ch)) {
            if (inWord) {
                words++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }

    if (inWord) {
        words++;
    }

    cout << "Number of lines: " << lines << endl;
    cout << "Number of tabs: " << tabs << endl;
    cout << "Number of spaces: " << spaces << endl;
    cout << "Number of words: " << words << endl;
    cout << "Number of characters: " << characters << endl;

    file.close();
    return 0;
}
