#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Rule
{
public:
    virtual string Rename(string origin) = 0;
};

class ReplaceSpecialCharsRule : public Rule
{
public:
    vector<string> _specialChars;
    string replacement;

public:
    vector<string> &specialChars()
    {
        return _specialChars;
    }
    void setReplacement(string replacement)
    {
        this->replacement = replacement;
    }
    string Rename(string origin)
    {
        for (int i = 0; i < _specialChars.size(); i++)
        {
            int pos = origin.find(_specialChars[i]);
            while (pos != string::npos)
            {
                origin.replace(pos, _specialChars[i].length(), replacement);
                pos = origin.find(_specialChars[i]);
            }
        }
        return origin;
    }
};

class OneSpaceRule : public Rule
{
public:
    string Rename(string origin)
    {
        int pos = origin.find("  ");
        while (pos != string::npos)
        {
            origin.replace(pos, 2, " ");
            pos = origin.find("  ");
        }
        return origin;
    }
};

class AddPrefixRule : public Rule
{
private:
    string prefix;

public:
    void setPrefix(string prefix)
    {
        this->prefix = prefix;
    }
    string Rename(string origin)
    {
        return prefix + " " + origin;
    }
};

int main()
{
    string origin = "Ivan-----Glutonovik---Isenka.pdf";
    ReplaceSpecialCharsRule rule1;
    rule1.specialChars().push_back("-"); // vector<string>
    rule1.setReplacement(" ");           // string
    string newName1 = rule1.Rename(origin);
    cout << newName1 << endl; // "Ivan     Glutonovik   Isenka.pdf"

    OneSpaceRule rule2;
    string newName2 = rule2.Rename(newName1);
    cout << newName2 << endl; // "Ivan Glutonovik Isenka.pdf"

    AddPrefixRule rule3;
    rule3.setPrefix("CV");
    string newName3 = rule3.Rename(newName2);
    cout << newName3 << endl; // "CV Ivan Glutonovik Isenka.pdf"
}