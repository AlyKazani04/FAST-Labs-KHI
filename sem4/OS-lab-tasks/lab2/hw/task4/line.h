#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LineCount
{
    private:
        int numLines = 0;
        string buff;
    public:
        LineCount(const string& filename);
        int getNumLines() const;
};