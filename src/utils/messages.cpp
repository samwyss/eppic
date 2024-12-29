#include "messages.hpp"

void error_msg(const string& msg)
{
    cerr << RED << "[ERROR]" << STANDARD << ": " << msg << "\n";
}

void warning_msg(const string& msg)
{
    cout << YELLOW << "[WARNING]" << STANDARD << ": " << msg << "\n";
}

void info_msg(const string& msg)
{
    cout << GREEN << "[INFO]" << STANDARD << ": " << msg << "\n";
}

void log_msg(const string& msg)
{
    cout << BLUE << "[LOG]" << STANDARD << ": " << msg << "\n";
}