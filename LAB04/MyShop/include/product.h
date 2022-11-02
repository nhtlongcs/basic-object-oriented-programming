#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <regex>
#include "logger.h"
#include "category.h"
using namespace std;

class Price
{
public:
    int value;
    string str;

public:
    Price() {}
    Price(int price, string price_str)
    {
        this->value = price;
        this->str = price_str;
    }
};
class Product
{
public:
    int id;
    string name;
    Category *cat;
    Price price;

public:
    Product(){};
    Product(int id, string name, Category *cat, Price price)
    {
        this->id = id;
        this->name = name;
        this->cat = cat;
        this->price = price;
        this->cat->addProductId(id);
    }
    string toString()
    {
        return "ID: " + to_string(id) + ", Name: " + name + ", Category: " + cat->name + ", Price: " + price.str + " d";
    }
};

class ProductManager
{
private:
    map<int, Product> products;

public:
    ProductManager(){};
    ProductManager(string filepath, CategoryManager *cManager)
    {
        string product_pattern = "Product: ID=(\\d+), Name=([^,]*), Price=((0|[1-9][0-9]{0,2})(.\\d{3})*(\\.\\d{3})), CategoryID=(\\d+)";
        std::ifstream file(filepath);
        for (std::string line; std::getline(file, line);)
        {
            std::smatch match;
            logger->info(line);
            logger->debug("Found: " + to_string(std::regex_search(line, match, std::regex(product_pattern))));
            if (std::regex_search(line, match, std::regex(product_pattern)))
            {
                // print all match
                for (int i = 0; i < match.size(); i++)
                {
                    logger->debug("Match " + to_string(i) + ": " + match.str(i));
                }
                int id = stoi(match[1]);
                string name = match[2];
                string sprice = match.str(3);
                int iprice = stoi(std::regex_replace(match.str(3), std::regex("\\."), ""));
                Price price = Price(iprice, sprice);

                int categoryId = stoi(match[7]);
                logger->debug("ID: " + to_string(id) + ", Name: " + name + ", Price: " + price.str + ", Category name: " + cManager->getCategory(categoryId)->name);
                Product product = Product(id, name, cManager->getCategory(categoryId), price);
                addProduct(product);
            }
        }
    }
    void addProduct(Product product)
    {
        products[product.id] = product;
    }
    Product getProduct(int id)
    {
        return products[id];
    }
    vector<int> searchByName(string subname)
    {
        vector<int> result;
        for (auto const &[key, val] : products)
        {
            if (val.name.find(subname) != std::string::npos)
            {
                result.push_back(val.id);
            }
        }
        return result;
    }

    vector<int> searchInRange(int from, int to)
    {
        vector<int> result;
        for (auto const &[key, val] : products)
        {
            if (val.price.value >= from && val.price.value <= to)
            {
                result.push_back(val.id);
            }
        }
        return result;
    }
};
#endif