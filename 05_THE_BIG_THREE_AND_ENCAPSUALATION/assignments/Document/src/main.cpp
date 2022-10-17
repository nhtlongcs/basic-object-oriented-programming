#include "document.h"

int main()
{
    Document doc;
    doc.fromfile("test.txt");
    doc.print();
    std::cout << doc.countwords() << std::endl;
    std::cout << doc.countsentences() << std::endl;
    std::cout << doc.mostcommonword() << std::endl;
    doc.sort();
    doc.print();
    doc.tofile("output.txt");
    return 0;
}