#include "letter.h"

LetterCount::LetterCount(const string& filename)
{
    ifstream file(filename);
    
    if(file.is_open())
    {
        while(getline(file, buff))
        {
            for(char c : buff)
            {
                if(isalnum(c))
                {
                    numLetters++;
                }
            }
        }

        file.close();
    }
    else
    {
        cerr << "Unable to open file!" << endl;
    }

}

int LetterCount::getNumLetters() const
{
    return numLetters;
}