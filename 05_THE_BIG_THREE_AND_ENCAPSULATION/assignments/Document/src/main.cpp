#include "document.h"

int main()
{
    Document doc;
    doc.fromfile("test.txt");
    doc.print();
    std::cout << "Number of words: " << doc.countwords() << std::endl;
    std::cout << "Number of sentences: " << doc.countsentences() << std::endl;
    std::cout << "Most common word is: \"" << doc.mostcommonword() << "\"" << std::endl;
    doc.sort();
    doc.print();
    doc.tofile("output.txt");
    return 0;
}