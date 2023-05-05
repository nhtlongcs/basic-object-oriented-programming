#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <filesystem>

#include <regex>
#include "logger.h"
#include "error.h"

class ProductDataset
{
// private:
public: // for testing
    map<int, Product> products;
    Logger *logger = &Logger::getInstance();

public:
    ProductDataset(){};
    ProductDataset(string folderpath, string fileExt)
    {   
        for (const auto &entry : std::filesystem::directory_iterator(folderpath))
        {
            string filepath = entry.path();
            if (filepath.find(fileExt) != string::npos)
            {
                readFile(filepath);
            }
        }
    }
    ProductDataset(vector<Product> products)
    {
        for (auto &p : products)
        {
            this->products[p.id] = p;
        }
    }
    void exportFiles(string folderpath){
        // mkdir if not exist
        if (!std::filesystem::exists(folderpath))
        {
            std::filesystem::create_directory(folderpath);
        }
        for (auto &p : products)
        {
            string filepath = folderpath + "/" + to_string(p.second.id) + ".txt";
            ofstream file(filepath);
            file << p.second.toExportString();
            file.close();
        }
    }
    void readFile(string filepath)
    {
        string product_pattern = "ID=(\\d+), Name=([^,]*), Price=(\\d+)";
        std::ifstream file(filepath);
        logger->debug("Filepath: " + filepath);
        for (std::string line; std::getline(file, line);)
        {
            std::smatch match;
            logger->debug(line);
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
                int iprice = stoi(sprice);
                Price price = Price(iprice);

                logger->debug("ID: " + to_string(id) + ", Name: " + name + ", Price: " + price.toString());
                Product product = Product(id, name, price);
                addProduct(product);
            }
        }
    }
    void addProduct(Product product)
    {
        this->products[product.id] = product;
    }
};

#endif