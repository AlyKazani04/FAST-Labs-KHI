#include "word.h"

WordCount::WordCount(const string& filename)
{
    ifstream file(filename);
    
    if(file.is_open())
    {
        while(getline(file, buff))
        {
            bool isWord = false;

            for(char c : buff)
            {
                if(isalnum(c) && !isWord)
                {
                    isWord = true;
                    numWords++;
                }
                if(c == ' ' && isWord)
                {
                    
                    isWord = false;
                }
            }
        }
    }

    file.close();
}

int WordCount::getNumWords() const
{
    return numWords;
}