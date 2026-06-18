#include "line.h"

LineCount::LineCount(const string& filename)
{
    ifstream file(filename);
    
    if(file.is_open())
    {
        while(getline(file, buff))
        {
            numLines++;
        }
    }

    file.close();
}

int LineCount::getNumLines() const
{
    return numLines;
}