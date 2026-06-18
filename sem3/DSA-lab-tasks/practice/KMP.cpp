#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Build the LPS (Longest Prefix Suffix) array
vector<int> buildLPS(const string& pattern)
{
    int n = pattern.size();
    vector<int> lps(n, 0);

    int len = 0; // length of current longest prefix suffix
    int i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
                // no increment of i here
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP search: returns all starting indices of matches
vector<int> KMP(const string& text, const string& pattern)
{
    vector<int> result;
    if (pattern.empty() || text.empty()) return result;

    vector<int> lps = buildLPS(pattern);
    int i = 0; // text index
    int j = 0; // pattern index

    while (i < text.size())
    {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern.size()) {
            result.push_back(i - j); // match found
            j = lps[j - 1];          // continue for next match
        }
        else if (i < text.size() && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return result;
}

// Example usage
int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    vector<int> matches = KMP(text, pattern);

    for (int idx : matches)
        cout << "Pattern found at index: " << idx << endl;

    return 0;
}
