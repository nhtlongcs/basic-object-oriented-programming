# Lab 07 - Working with list of objects

# Requirements

- [ ]  Generate an integer n in the range of [5, 10]
- [ ]  Generate n products and print out the list to the screen. Each product should have an id (string), a name (string), and a price (int).
    
    The id should not be duplicated. You should use a class for generating product’s id. 
    
- [ ]  Save n products into n text files, each text file contains all the information of a product.

Theses text file should be put inside a folder named “**Product**”

- [ ]  Read back all your stored products from text files and print out the list to the console

For examples, if you generate 3 products, you should store them inside **3 different txt files** inside the folder **Product** using the suggested format like this:

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8c90f551-7c4c-4b22-b344-a38839a186ac/Untitled.png)

**1.txt**

```csharp
ID=1, Name=Macbook 16, Price=40000000
```

**2.txt**

```csharp
ID=2, Name=Dell XPS 9560, Price=35000000
```

**3.txt**

```csharp
ID=3, Name=Dell XPS 9560, Price=35000000
```

# Hints

```csharp
class Product {
private:
	string _id;
	string _name;
	int _price;
public:
	Product();
	Product(string, string, int);
	string toString();
};
```

```csharp
class ProductGenerator {
public:
	Product next();
};
```

```csharp
class ProductIdGenerator {
private:
	string _dbFolder = "";

public:
  ProductIdGenerator (string folder);
	string next();
};
```

```csharp
class ProductDataSet {
private:
	string _dbFolder = "";
  ProductIdGenerator* _idGen;
public:
	ProductDataSet(string folder);
	~ProductDataSet();
public:
	vector<Product> getAll();
  int add(const Product& p);
public:
	static Product parse(string data);
};
```

```csharp
class DataContext {
private:
	string _dbFolder = "Product";
	ProductDataSet* _products = NULL;
public:
	DataContext();
	~DataContext();
	vector<Product> getAllProducts();
public:
	ProductDataSet* products();
};
```

## How to generate the product name?

You could prepare a list of manufacturers (like Apple, Microsoft, Asus, Acer, HP..), a list of brand name like (Duo, Macbook, Victus, G15…) and a list of screen size (12.5”, 13”, 14”, 15”, 16”, 17”, 17.3”).

The product name will be a random combination of these three components.

## How to save a product into its database folder?

```csharp
int ProductDataSet::add(const Product& p) {
    if (!fs::exists(_dbFolder)) {
        fs::create_directory(_dbFolder);
    }

    stringstream builder;
    builder << _dbFolder << "\\" << p.id() << ".txt";
    string filename = builder.str();

    ofstream writer(filename, ios::out);
    writer << p.toString(); 
    writer.close();
    return 1;
}
```

## How to get all files from a folder?

```csharp
for (const auto& file : fs::directory_iterator(_dbFolder)) {
      cout << file.path().filename().string();
}
```

## How to convert back a product from text info?

```csharp
Product p = ProductDataSet::parse(buffer);
```

```csharp
class ProductDataSet {
...
public:
    ...
    Product parse(string data);
};
```

## Super demo for inspiring