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

class Product
{
public:
    int id;
    string name;
    Category *cat;
    int price;

public:
    Product(){};
    Product(int id, string name, Category *cat, int price)
    {
        this->id = id;
        this->name = name;
        this->cat = cat;
        this->price = price;
        this->cat->addProductId(id);
    }
    string toString()
    {
        return "ID: " + to_string(id) + ", Name: " + name + ", Category: " + cat->name + ", Price: " + to_string(price);
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
        string product_pattern = "Product: ID=(\\d+), Name=([^,]*), Price=(\\d+), CategoryID=(\\d+)";
        std::ifstream file(filepath);
        for (std::string line; std::getline(file, line);)
        {
            std::smatch match;
            logger->info(line);
            logger->debug("Found: " + to_string(std::regex_search(line, match, std::regex(product_pattern))));
            if (std::regex_search(line, match, std::regex(product_pattern)))
            {
                int id = stoi(match[1]);
                string name = match[2];
                int price = stoi(match[3]);
                int categoryId = stoi(match[4]);
                logger->debug("ID: " + to_string(id) + ", Name: " + name + ", Price: " + to_string(price) + ", Category name: " + cManager->getCategory(categoryId)->name);
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
            if (val.price >= from && val.price <= to)
            {
                result.push_back(val.id);
            }
        }
        return result;
    }
};
#endif