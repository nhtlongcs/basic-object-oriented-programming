#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
using namespace std;
class IRule
{
public:
    virtual string rename(string filename) = 0;
    virtual ~IRule() = default;
};
class RemoveSpecialCharsRule : public IRule
{
public:
    string blacklist;
    RemoveSpecialCharsRule(string blacklist)
    {
        this->blacklist = blacklist;
    }
    string rename(string filename)
    {
        for (int i = 0; i < blacklist.length(); i++)
        {
            filename.erase(remove(filename.begin(), filename.end(), blacklist[i]), filename.end());
        }
        return filename;
    }
    ~RemoveSpecialCharsRule() = default;
};
class OneSpaceOnlyRule : public IRule
{
public:
    OneSpaceOnlyRule()
    {
    }
    string rename(string filename)
    {
        while (filename.find("  ") != string::npos)
        {
            filename.replace(filename.find("  "), 2, " ");
        }
        return filename;
    }
    ~OneSpaceOnlyRule() = default;
};
class AddCurrentMonthRule : public IRule
{
public:
    AddCurrentMonthRule()
    {
    }
    string rename(string filename)
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int month = 1 + ltm->tm_mon;
        string monthStr = to_string(month);
        if (month < 10)
        {
            monthStr = "0" + monthStr;
        }
        return monthStr + " " + filename;
    }
    ~AddCurrentMonthRule() = default;
};
class AddPrefixRule : public IRule
{

public:
    string prefix;
    AddPrefixRule(string prefix)
    {
        this->prefix = prefix;
    }
    string rename(string filename)
    {
        return prefix + " " + filename;
    }
    ~AddPrefixRule() = default;
};
class ReplaceRule : public IRule
{
public:
    string pattern;
    string to;
    ReplaceRule(string pattern, string to)
    {
        this->pattern = pattern;
        this->to = to;
    }
    string rename(string filename)
    {
        return regex_replace(filename, regex(pattern), to);
    }
    ~ReplaceRule() = default;
};

class IParsable
{
public:
    IParsable()
    {
        // logger->debug("IParsable::IParsable() is called");
    }
    virtual string parsedObjectName() = 0;
    virtual IRule *parse(string line) = 0;
    ~IParsable() = default;
};

class RemoveSpecialCharsParser : public IParsable
{
public:
    string parsedObjectName()
    {
        return "RemoveSpecialChars";
    }
    IRule *parse(string line)
    {
        string blacklist;
        regex pattern("blacklist=(.*)");
        smatch match;
        if (regex_search(line, match, pattern))
        {
            blacklist = match[1];
        }
        return new RemoveSpecialCharsRule(blacklist);
    }
    ~RemoveSpecialCharsParser() = default;
};
class OneSpaceOnlyParser : public IParsable
{
public:
    string parsedObjectName()
    {
        return "OneSpaceOnly";
    }
    IRule *parse(string line)
    {
        return new OneSpaceOnlyRule();
    }
    ~OneSpaceOnlyParser() = default;
};

class AddCurrentMonthParser : public IParsable
{
public:
    string parsedObjectName()
    {
        return "AddCurrentMonth";
    }
    IRule *parse(string line)
    {
        return new AddCurrentMonthRule();
    }
    ~AddCurrentMonthParser() = default;
};

class AddPrefixParser : public IParsable
{
public:
    string parsedObjectName()
    {
        return "AddPrefix";
    }
    IRule *parse(string prefix)
    {

        return new AddPrefixRule(prefix);
    }
    ~AddPrefixParser() = default;
};

class ReplaceParser : public IParsable
{
public:
    string parsedObjectName()
    {
        return "Replace";
    }
    IRule *parse(string line)
    {
        string pattern;
        string to;
        regex patternRegex("pattern=(.*)");
        regex toRegex("to=(.*)");
        smatch match;
        if (regex_search(line, match, patternRegex))
        {
            pattern = match[1];
        }
        if (regex_search(line, match, toRegex))
        {
            to = match[1];
        }
        return new ReplaceRule(pattern, to);
    }
    ~ReplaceParser() = default;
};

class ParserFactory
{
public:
    map<string, IParsable *> _container; // A container for all the dependencies injection
public:
    void registerWith(IParsable *parser)
    { // Do the injection here
        _container.insert(
            {parser->parsedObjectName(), parser});
    }

    IParsable *create(string type)
    {
        // logger->debug("ParserFactory::create() is called");
        // logger->debug("type = " + type);
        return _container[type]; // Ask container to resolve the needed type
    }
    ~ParserFactory()
    {
        for (auto it = _container.begin(); it != _container.end(); it++)
        {
            delete it->second;
        }
    }
};

int main()
{
    ParserFactory factory;
    factory.registerWith(new RemoveSpecialCharsParser());
    factory.registerWith(new OneSpaceOnlyParser());
    factory.registerWith(new AddCurrentMonthParser());
    factory.registerWith(new AddPrefixParser());
    factory.registerWith(new ReplaceParser());

    vector<string> hrRules = {
        "RemoveSpecialChars blacklist=-_+",
        "OneSpaceOnly",
        "AddCurrentMonth",
        "AddPrefix CV",
        "Replace pattern=773423, to=devops"};

    vector<string> filenames = {
        "+++Cao---Minh----Long 773423.pdf",
        "Tran    Huu  Nhan 773423.pdf",
        "Do-Diem-Minh 773423.pdf",
        "CAO.TRAN.LUC 773423.pdf",
        "Hoang___Tan___Minh 773423.pdf"};

    vector<IRule *> rules;

    // Recreated all the rules from preset file "hrRules.txt"
    for (auto line : hrRules)
    { // line = "RemoveSpecialChars blacklist=-_+"
        int splitPosition = line.find_first_of(" ");
        string type = line.substr(0, splitPosition); // type = "RemoveSpecialChars"
        IParsable *parser = factory.create(type);

        // data = "blacklist=-_+"
        string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
        IRule *rule = dynamic_cast<IRule *>(parser->parse(data));
        rules.push_back(rule);
    }

    // Apply all rename rules to each filename
    vector<string> renamedFiles;

    for (auto filename : filenames)
    {
        string newName = filename;

        for (auto rule : rules)
        {
            newName = rule->rename(newName);
        }

        renamedFiles.push_back(newName);
    }

    // Print out all renamed files
    for (int i = 0; i < filenames.size(); i++)
    {
        cout << filenames[i] << " => " << renamedFiles[i] << endl;
    }
}