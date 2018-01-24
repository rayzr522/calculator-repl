#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "utils.cpp"

int main()
{
    std::string line;
    bool running = true;

    std::cout << "Do 'help' or '?' for a list of commands." << std::endl;

    // Basic REPL style.
    while (running)
    {
        std::cout << "> ";
        std::getline(std::cin, line);
        std::vector<std::string> words = split(line, ' ');

        if (words.size() < 1)
        {
            // Empty input, ignore.
            continue;
        }

        std::string label = words[0];
        std::vector<std::string> args(words.begin() + 1, words.end());

        if (label == "exit")
        {
            running = false;
            continue;
        }
        else if (label == "+")
        {
            int output = 0;
            auto add = [&output](const std::string &line) {
                output += std::stoi(line);
            };

            std::for_each(args.begin(), args.end(), add);

            std::cout << "= " << output << std::endl;
        }
        else if (label == "*")
        {
            int output = 1;
            auto multiply = [&output](const std::string &line) {
                output *= std::stoi(line);
            };

            std::for_each(args.begin(), args.end(), multiply);

            std::cout << "= " << output << std::endl;
        }
        else if (label == "^")
        {
            if (args.size() < 2)
            {
                std::cerr << "You must provide 2 arguments." << std::endl;
                continue;
            }

            int num = std::stoi(args[0]);
            int power = std::stoi(args[1]);

            std::cout << "= " << pow(num, power) << std::endl;
        }
        else if (label == "help" || label == "?")
        {
            std::cout << std::endl
                      << "Available commands:" << std::endl
                      << "+ <numbers...>     : Adds a list of numbers" << std::endl
                      << "* <numbers...>     : Multiplies a list of numbers" << std::endl
                      << "^ <number> <power> : Raises a number to a power" << std::endl
                      << "help | ?           : Shows this message" << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "I don't know how to handle '" << label << "'. Do 'help' or '?' for a list of commands." << std::endl;
        }
    }

    return 0;
}