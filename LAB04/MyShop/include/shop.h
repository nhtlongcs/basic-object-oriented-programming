
#include <chrono>
#include <thread>
#include "category.h"
#include "product.h"
#include <regex>
class Shop
{
public:
    Shop();
    Shop(string categories_path, string products_path)
    {
        this->categories_path = categories_path;
        this->products_path = products_path;

        Logger *e = &Logger::getInstance();
        category_manager = CategoryManager(categories_path);
        product_manager = ProductManager(products_path, &category_manager);
    }
    void display()
    {
        cout << "Categories: " << category_manager.toString() << endl;
    }
    void findProductsByName()
    {
        string name;
        cout << "Please enter the name of the product you want to find: ";
        cin >> name;
        vector<int> result = product_manager.searchByName(name);
        cout << "Found " << result.size() << " products" << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << '[' << i << "] :" << product_manager.getProduct(result[i]).toString() << endl;
        }
    }

    void findProductsByPrice()
    {
        int minP, maxP;
        string minS, maxS;
        string pattern = "((0|[1-9][0-9]{0,2})(.\\d{3})*(\\.\\d{3}))";
        std::smatch match;
        cout << "Please enter the minimum price of the product you want to find: ";
        cin >> minS;
        if (std::regex_search(minS, match, std::regex(pattern)))
        {
            minP = stoi(std::regex_replace(match.str(1), std::regex("\\."), ""));
        }
        else
        {
            cout << "Invalid price" << endl;
            return;
        }

        cout << "Please enter the maximum price of the product you want to find: ";
        cin >> maxS;

        if (std::regex_search(maxS, match, std::regex(pattern)))
        {
            maxP = stoi(std::regex_replace(match.str(1), std::regex("\\."), ""));
        }
        else
        {
            cout << "Invalid price" << endl;
            return;
        }

        cout << "Searching for products within the price range of [" << minS << ", " << maxS << "]" << endl;
        vector<int> result = product_manager.searchInRange(minP, maxP);
        cout << "Found " << result.size() << " products" << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << '[' << i << "] :" << product_manager.getProduct(result[i]).toString() << endl;
        }
    }
    void menu()
    {
        // What do you want to do?
        // 1. Display all categories
        // 2. Find products by name
        // 3. Find products by price range

        // 0. Quit

        // Please enter your choice: _
        // clean console
        cout << "What do you want to do?" << endl;
        cout << "1. Display all categories" << endl;
        cout << "2. Find products by name" << endl;
        cout << "3. Find products by price range" << endl;
        cout << "0. Quit" << endl;
        cout << "Please enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            findProductsByName();
            break;
        case 3:
            findProductsByPrice();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    void run()
    {
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono;      // nanoseconds, system_clock, seconds

        while (true)
        {
            system("clear");
            menu();
            sleep_for(seconds(5));
        }
    }

private:
    string categories_path;
    string products_path;
    CategoryManager category_manager;
    ProductManager product_manager;
};