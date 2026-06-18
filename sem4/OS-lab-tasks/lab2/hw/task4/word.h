#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class WordCount
{
    private:
        int numWords = 0;
        string buff;
    public:
        WordCount(const string& filename);
        int getNumWords() const;
};