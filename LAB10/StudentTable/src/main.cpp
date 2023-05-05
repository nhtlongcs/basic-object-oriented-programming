#include <iostream>
#include <memory>
#include <vector>
#include "table.h"
#include "student.h"
#include "converter.h"
#include "logger.h"
using namespace std;
int main()
{
    // (&Logger::getInstance())->debug();
    vector<shared_ptr<Object>> data = {
        make_shared<Student>("Tran Huu Long", "0909888712", "227 Nguyen Van Cu P4 Q5"),
        make_shared<Student>("Cao Duc Tuan", "0773256712", "177 Nguyen Dinh Chieu Q3"),
        make_shared<Student>("Le Mai Loan", "0869327617", "17 Tran Phu Q2"),
        make_shared<Student>("Dinh Thi Ly", "0999876432", "35 Vo Thi Sau Q1"),
        make_shared<Student>("Nguyen Duc Vinh", "0999882725", "15 Vo Van Tan P11 Binh Thanh"),
    };
    vector<string> headers = {
        "Ho va ten", "SDT", "Dia chi"};
    vector<int> widths = {
        15, 11, 28};
    shared_ptr<IValueConverter> converter = make_shared<StudentToRowConverter>(widths);

    Table table(headers, widths, data, converter);
    table.display();
}
