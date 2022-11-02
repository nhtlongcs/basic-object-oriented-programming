categories_file = 'categories.txt'
products_file = 'products.txt'

import re

if __name__ == "__main__":
    with open(categories_file, 'r') as f:
        lines = f.readlines()
        for line in lines:
            # parse line format with regex
            # Category: ID=1, Name=Laptop
            ret = re.match(r'Category: ID=(\d+), Name=(\w+)', line)
            print(ret.groups())
            # Product: ID=15, Name=Dell XPS 9560, Price=40.000.000, CategoryID=1
            # Product: ID=20, Name=Keychron K6, Price=1.200.000, CategoryID=2

    with open(products_file, 'r') as f:
        lines = f.readlines()
        for line in lines:
            print(line)
            # parse line format with regex
            # Product: ID=15, Name=Dell XPS 9560, Price=40000.000, CategoryID=1
            # Product: ID=20, Name=Keychron K6, Price=1200000, CategoryID=2
            ret = re.match(r'Product: ID=(\d+), Name=([^,]*), Price=((0|[1-9][0-9]{0,2})(.\d{3})*(\.\d{3})), CategoryID=(\d+)', line)
            print(ret.groups())