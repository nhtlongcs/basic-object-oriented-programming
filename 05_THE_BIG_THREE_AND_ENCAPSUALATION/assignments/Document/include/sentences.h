#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Sentence
{
public:
    Sentence(){};
    Sentence(string s);
    Sentence(const Sentence &other)
    {
        raw_string = other.raw_string;
        words = other.words;
        numwords = other.numwords;
    };
    ~Sentence(){};
    void print();
    vector<string> getwords();
    int getnumwords();
    string getstring();
    void sort();

private:
    string raw_string;
    vector<string> words;
    int numwords;
};
Sentence::Sentence(string s)
{
    string tmp_string = s;
    numwords = 0;
    // Split by punctuation
    string delimiters = " ,.?!";
    string token;
    size_t pos = 0;
    // std::cout << s << std::endl;
    for (auto c : delimiters)
        while ((pos = tmp_string.find(c)) != string::npos)
        {
            token = tmp_string.substr(0, pos);
            words.push_back(token);
            tmp_string.erase(0, pos + 1);
            numwords++;
            // std::cout << token << std::endl;
        }
    raw_string = s;

    // std::cout << s << std::endl;
    // std::cout << raw_string << std::endl;
}
vector<string> Sentence::getwords()
{
    return words;
}
int Sentence::getnumwords()
{
    return numwords;
}
string Sentence::getstring()
{
    return raw_string;
}
void Sentence::sort()
{
    // sort words in sentence alphabetically
    std::sort(words.begin(), words.end(), [](string a, string b)
              { return a < b; });
    // reassemble sentence
    raw_string = "";
    for (auto w : words)
        raw_string += w + " ";
}