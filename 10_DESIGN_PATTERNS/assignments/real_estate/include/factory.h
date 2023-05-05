#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <utility>
#include <any>

#include "land.h"

using namespace std;
using UPTRB = std::unique_ptr<Land>;

template <class Child, typename... Args>
UPTRB createClass(Args... args) { return std::make_unique<Child>(args...); }

template <class Key, class Object>
class LandFactory
{
    std::map<Key, std::any> selector;

public:
    LandFactory() : selector() {}
    LandFactory(std::initializer_list<std::pair<const Key, std::any>> il) : selector(il) {}

    template <typename Function>
    void add(Key key, Function &&someFunction) { selector[key] = std::any(someFunction); };

    template <typename... Args>
    Object create(Key key, Args... args)
    {
        if (selector.find(key) != selector.end())
        {
            return std::any_cast<std::add_pointer_t<Object(Args...)>>(selector[key])(args...);
        }
        else
            return nullptr;
    }
};

// factory.add(1, createClass<RectLand, string, int, int, int>);
// factory.add(2, createClass<TrapezoidLand, string, int, int, int, int>);
// factory.create(1, id, pricePerUnit, width, length)
#endif