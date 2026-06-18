#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LetterCount
{
    private:
        int numLetters = 0;
        string buff;
    public:
        LetterCount(const string& filename);
        int getNumLetters() const;
};