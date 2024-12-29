#ifndef MESSAGES_MESSAGES_HPP
#define MESSAGES_MESSAGES_HPP

#include <iostream>

using namespace std;

/// defines the red color for terminal output
constexpr char RED[8] = "\033[31m";

/// defines the green color for terminal output
constexpr char GREEN[8] = "\033[32m";

/// defines the yellow color for terminal output
constexpr char YELLOW[8] = "\033[33m";

/// defines the blue color for terminal output
constexpr char BLUE[8] = "\033[34m";

/// defines the standard color for terminal output
constexpr char STANDARD[8] = "\033[0m";

/*!
 * formats and prints error messages to stderr
 * @param msg error message
 */
void error_msg(const string& msg);

/*!
 * formats and prints warning messages to stdout
 * @param msg warning message
 */
void warning_msg(const string& msg);

/*!
 * formats and prints info messages to stdout
 * @param msg info message
 */
void info_msg(const string& msg);

/*!
 * formats and prints logging messages to stdout
 * @param msg logging message
 */
void log_msg(const string& msg);

#endif //MESSAGES_MESSAGES_HPP
