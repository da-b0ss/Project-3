// Project 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Function to split a string into tokens based on a delimiter
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    // Open the CSV file for reading
    std::ifstream file("assets/food.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    std::string line;
    std::string inputString;
    std::cout << "Enter input string: ";
    std::getline(std::cin, inputString);

    // Search through the first column for the input string
    bool found = false;
    while (std::getline(file, line)) {
        
        /*
        std::vector<std::string> tokens = split(line, ',');
        if (tokens[0] == inputString) {
            found = true;
            std::cout << "Input string found in CSV file." << std::endl;
            break;
        }*/
    }

    if (!found) {
        std::cout << "Input string not found in CSV file." << std::endl;
    }

    file.close();
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
