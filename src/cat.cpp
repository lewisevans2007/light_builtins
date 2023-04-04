/* Light builtins's
 * cat - concatenate files and print on the standard output
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#define CYAN "\033[0;36m"
#define RESET "\033[0m"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    bool show_line_numbers = false;
    int file_offset = 1;
    if (argc >= 2 && std::string(argv[1]) == "-n") {
        show_line_numbers = true;
        file_offset = 2;
    }

    if (argc < file_offset + 1) {
        std::cerr << "Usage: " << argv[0] << " [-n] <file1> [<file2> ...]\n";
        return 1;
    }

    int line_number = 1;
    for (int i = file_offset; i < argc; ++i) {
        std::ifstream file(argv[i]);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << argv[i] << "\n";
            return 1;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (show_line_numbers) {
                std::cout << CYAN << line_number << RESET << "\t";
            }
            std::cout << line << "\n";
            line_number++;
        }
        file.close();
    }

    return 0;
}
