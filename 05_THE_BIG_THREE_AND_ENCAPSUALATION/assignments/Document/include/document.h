#include "sentences.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
class Document
{
public:
    Document(){}; // default constructor
    Document(const Document &other);
    Document &operator=(const Document &other);
    ~Document(){};
    void fromfile(string filename);
    void tofile(string filename);
    void print();
    void sort();

    int countwords();
    int countsentences();

    string mostcommonword();

private:
    vector<Sentence> sentences;
    int numwords;
    int numsentences;
    map<string, int> countOfWords;
};
void Document::fromfile(string filename)
{
    // Read document as string and split by delimiters (period, question mark, exclamation point)
    ifstream file(filename);
    string line;
    string delimiter_ls = ".?!";
    char delimiter = delimiter_ls[0];
    string token;
    size_t pos = 0;
    while (getline(file, line))
    {
        // find closet delimiter
        for (int i = 0; i < delimiter_ls.size(); i++)
        {
            if (line.find(delimiter_ls[i]) < line.find(delimiter))
            {
                delimiter = delimiter_ls[i];
            }
        }
        pos = line.find(delimiter);
        while (pos != string::npos)
        {
            pos++;
            token = line.substr(0, pos);
            Sentence s(token);
            sentences.push_back(s);
            line.erase(0, pos + 1);

            vector<string> words = s.getwords();
            // add word count to total word count
            int count = 0;
            for (int i = 0; i < words.size(); i++)
            {
                countOfWords[words[i]]++;
                // cout << words[i] << countOfWords[words[i]] << endl;
            }
            // find closet delimiter
            for (int i = 0; i < delimiter_ls.size(); i++)
            {
                if (line.find(delimiter_ls[i]) < line.find(delimiter))
                {
                    delimiter = delimiter_ls[i];
                }
            }
            pos = line.find(delimiter);
        }
    }
}
string Document::mostcommonword()
{
    // get value from countOfWords
    // return key with highest value
    string mostCommonWord;
    int highestCount = 0;
    for (auto it = countOfWords.begin(); it != countOfWords.end(); ++it)
    {
        // cout << it->first << " => " << it->second << '\n';
        if (it->second > highestCount)
        {
            highestCount = it->second;
            mostCommonWord = it->first;
        }
    }
    return mostCommonWord;
}
void Document::tofile(string filename)
{
    ofstream file(filename);
    for (int i = 0; i < sentences.size(); i++)
    {
        file << sentences[i].getstring();
    }
    file.close();
}
int Document::countwords()
{
    numwords = 0;
    for (int i = 0; i < sentences.size(); i++)
    {
        numwords += sentences[i].getnumwords();
    }
    return numwords;
}

int Document::countsentences()
{
    numsentences = sentences.size();
    return numsentences;
}
void Document::print()
{
    for (int i = 0; i < sentences.size(); i++)
    {
        cout << sentences[i].getstring() << endl;
    }
}
void Document::sort()
{
    for (int i = 0; i < sentences.size(); i++)
    {
        sentences[i].sort();
    }
}