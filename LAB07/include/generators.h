#ifndef GENERATORS_H
#define GENERATORS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <regex>
#include <filesystem>
#include "logger.h"
#include "error.h"
#include "product.h"
using namespace std;

class IdGenerator
{
private:
    string db_folder;
    int id = 0;
public:
    IdGenerator(string folder)
    {
        this->db_folder = folder;
        for (const auto &entry : std::filesystem::directory_iterator(db_folder))
        {
            string filepath = entry.path();
            if (filepath.find(".txt") != string::npos) this->id++;
        }
    }
    int next(){
        return this->id++;
    }
};

class ProductGenerator {
public:
    vector<string> manufacturers{"Apple", "Samsung", "Xiaomi", "Huawei", "Oppo", "Vivo", "Realme", "Nokia", "Sony", "LG", "HTC", "Motorola", "Blackberry", "Asus", "Lenovo", "Google", "Microsoft", "OnePlus", "ZTE", "Honor", "Meizu", "Xolo", "Micromax", "Gionee", "Vodafone", "Panasonic", "Lava", "Coolpad", "Karbonn", "Spice", "Intex", "YU", "LeEco", "InFocus", "Xiaomi", "Gionee", "Vivo", "Oppo", "Asus", "Lenovo", "Google", "Microsoft", "OnePlus", "ZTE", "Honor", "Meizu", "Xolo", "Micromax", "Gionee", "Vodafone", "Panasonic", "Lava", "Coolpad", "Karbonn", "Spice", "Intex", "YU", "LeEco", "InFocus", "Xiaomi", "Gionee", "Vivo", "Oppo", "Asus", "Lenovo", "Google", "Microsoft", "OnePlus", "ZTE", "Honor", "Meizu", "Xolo", "Micromax", "Gionee", "Vodafone", "Panasonic", "Lava", "Coolpad", "Karbonn", "Spice", "Intex", "YU", "LeEco", "InFocus", "Xiaomi", "Gionee", "Vivo", "Oppo", "Asus", "Lenovo", "Google", "Microsoft", "OnePlus", "ZTE", "Honor", "Meizu", "Xolo", "Micromax", "Gionee", "Vodafone", "Panasonic", "Lava", "Coolpad", "Karbonn", "Spice", "Intex", "YU", "LeEco", "InFocus", "Xiaomi", "Gionee", "Vivo", "Oppo", "Asus", "Lenovo", "Google", "Microsoft", "OnePlus", "ZTE"};
    vector<string> version{"Duo", "Pro", "Max", "Lite", "Mini", "Prime", "Plus", "Note", "Edge"};
    vector<string> devices{"Screen", "Phone", "Tablet", "Watch", "Laptop", "Desktop", "Camera", "Speaker", "Headphone", "Keyboard", "Mouse", "Printer", "Router", "Modem", "TV", "Monitor", "Projector", "Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV", "Smart Monitor", "Smart Projector", "Smart Game Console", "Smart Home", "Smart Watch", "Smart Phone", "Smart Speaker", "Smart Camera", "Smart TV"};
    tuple<int, int, int> idx = make_tuple(0, 0, 0);
    int offset = 0;

public:
    ProductGenerator(){
        srand(time(NULL));
        random_shuffle(manufacturers.begin(), manufacturers.end());
        random_shuffle(version.begin(), version.end());
        random_shuffle(devices.begin(), devices.end());
    };
    ProductGenerator(int offset) : ProductGenerator(){
        this->offset = offset;
    };
    void inc(){
        int i = get<0>(idx);
        int j = get<1>(idx);
        int k = get<2>(idx);
        if (k < devices.size() - 1){
            k++;
        } else if (j < version.size() - 1){
            j++;
            k = 0;
        } else if (i < manufacturers.size() - 1){
            i++;
            j = 0;
            k = 0;
        } else {
            i = 0;
            j = 0;
            k = 0;
        }
        idx = make_tuple(i, j, k);
    }
    Product next(){
        inc();
        string m = manufacturers[get<0>(idx)];
        string v = version[get<1>(idx)];
        string d = devices[get<2>(idx)];
        string name = m + " " + v + " " + d;
        Price p = Price((rand() % 1000)*5000);
        int id = offset + get<2>(idx) + get<1>(idx)*devices.size() + get<0>(idx)*devices.size()*version.size();
        return Product(id, name, p);
    }
};

#endif