#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <fstream>
#include <regex>
#include "logger.h"
using namespace std;
Logger *logger = &Logger::getInstance();
class Category
{
public:
    string name;
    int id;
    vector<int> productIds;

public:
    Category(){};
    Category(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
    void addProductId(int id)
    {
        productIds.push_back(id);
    }
};
class CategoryManager
{
private:
    map<int, Category> categories;

public:
    CategoryManager(){};
    CategoryManager(string filepath)
    {
        std::ifstream file(filepath);
        string category_pattern = "Category: ID=(\\d+), Name=(\\w+)";
        cout << logger->isDebug << endl;
        for (std::string line; std::getline(file, line);)
        {
            std::smatch match;
            bool found = std::regex_search(line, match, std::regex(category_pattern));

            logger->debug("Found: " + to_string(found));
            logger->debug(line);
            if (found)
            {
                int id = stoi(match[1]);
                string name = match[2];
                logger->debug("ID: " + to_string(id) + ", Name: " + name);
                Category category = Category(name, id);
                addCategory(category);
            }
        }
    }
    string toString()
    {
        string result = "";
        for (auto const &[key, val] : categories)
        {
            result += val.name + ", ";
        }

        return result;
    }
    void addCategory(Category category)
    {
        categories[category.id] = category;
    }
    Category *getCategory(int id)
    {
        return &categories[id];
    }
};
#endif