#include <iostream>
using namespace std;

#include "letter.h"
#include "word.h"
#include "line.h"

int main()
{
    LetterCount let("text.txt");
    LineCount li("text.txt");
    WordCount wo("text.txt");

    cout << "Line Count: " << li.getNumLines() << endl;
    cout << "Word Count: " << wo.getNumWords() << endl;
    cout << "Letter Count: " << let.getNumLetters() << endl;

    return 0;
}