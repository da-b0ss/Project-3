// Project 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include "FoodList.h"

// Function to split a string into tokens based on a delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    istringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
int main() {
    // Open the CSV file for reading
    ifstream file("assets/food.csv");
    if (!file.is_open()) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    string line;
    string inputString;
    cout << "Enter input string: ";
    getline(cin, inputString);
    map<string, int> nutrientKey;


    FoodList foodList = FoodList();

    // Creates Map of nutrient key from the first line in the csv file

    getline(file, line);
    vector<string> temp = split(line, ',');

    int i = 0;
    for (auto iter : temp) {
        nutrientKey[iter] = i;
        i++;
    }

    int index = 0;
    // Reads entire file
    while (getline(file, line)) {

        // Case 1: Line contains ""
        if (line.find("\"") != string::npos) {

            // Stores Food category, name, and id
            int parsePosition = line.find(",\"");
            foodList.foodList[index].category = line.substr(0, parsePosition);
            line = line.substr(parsePosition + 1);

            parsePosition = line.find("\",");
            foodList.foodList[index].name = line.substr(1, parsePosition - 1);
            line = line.substr(parsePosition + 2);

            parsePosition = line.find(",");
            foodList.foodList[index].id = stoi(line.substr(0, parsePosition));
            line = line.substr(parsePosition + 1);

            // Parses and stores the nutrients
            vector<string> nutrients = split(line, ',');

            int i = 0;
            for (auto iter : nutrients) {
                foodList.foodList[index].nutrients[i] = stod(iter);
                i++;
            }
        }
        // Case 2: Lines does not contain ""
        else {
            vector<string> parsedLine = split(line, ',');

            foodList.foodList[index].category = parsedLine[0];
            foodList.foodList[index].name = parsedLine[1];
            foodList.foodList[index].id = stoi(parsedLine[2]);

            for (int i = 0; i < parsedLine.size() - 3; i++) {
                foodList.foodList[index].nutrients[i] = stod(parsedLine[i+3]);
                i++;
            }
        }
        index++;        
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
