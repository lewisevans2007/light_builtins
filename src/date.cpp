/* Light builtins's
 * date - display the current date and time
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 */

#include <ctime>
#include <iostream>
#include <string>

#include "config.h"

int main(int argc, char *argv[]) {
    /* Check if the user has provided the -v or --version flag to show the version */
    if (argc >= 2 &&
        (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        /* Print the version information */
        std::cout << "Light Builtins (C++) " << VERSION_MAJOR << "."
                  << VERSION_MINOR << "." << VERSION_PATCH << "-"
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    /* Get the current time */
    std::time_t now = std::time(nullptr);
    char date[100];
    /* Format the time string */
    std::strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Z %Y",
                  std::localtime(&now));
    /* Print the time string */
    std::cout << date << std::endl;
    return 0;
}