#ifndef ERROR_H
#define ERROR_H
#include <string>
enum ErrorCode
{
    OK,
    EmptyInput,
    InvalidFormat,
    FileNotFound,
};
// singleton error class to be used in the whole project
class Error
{
public:
    static Error &getInstance()
    {
        static Error instance;
        return instance;
    }
    void setErrorCode(ErrorCode errorCode)
    {
        this->errorCode = errorCode;
    }
    ErrorCode getErrorCode()
    {
        return errorCode;
    }
    std::string getErrorMessage()
    {
        switch (errorCode)
        {
        case ErrorCode::OK:
            return "OK";
        case ErrorCode::EmptyInput:
            return "Empty input";
        case ErrorCode::InvalidFormat:
            return "Invalid format";
        case ErrorCode::FileNotFound:
            return "File not found";
        default:
            return "Unknown error";
        }
    }

private:
    Error() {}
    Error(Error const &);
    void operator=(Error const &);
    ErrorCode errorCode;
};
#endif