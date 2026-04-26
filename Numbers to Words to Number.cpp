#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

class NumberWordConverter {
private:
    // Word to number mappings
    static const unordered_map<string, int> basicNumbers;
    static const unordered_map<string, long long> scales;
    
    // Number to word arrays
    static const vector<string> ones;
    static const vector<string> tens;
    static const vector<string> scaleWords;

    // Helper function to split and clean input
    vector<string> splitWords(const string& input) const {
        string cleanInput = input;
        transform(cleanInput.begin(), cleanInput.end(), cleanInput.begin(), ::tolower);
        
        // Remove punctuation and extra spaces
        cleanInput.erase(remove_if(cleanInput.begin(), cleanInput.end(), 
            [](char c) { return !isalnum(c) && !isspace(c); }), cleanInput.end());
        
        stringstream ss(cleanInput);
        string word;
        vector<string> words;
        
        while (ss >> word) {
            if (!word.empty()) words.push_back(word);
        }
        return words;
    }

    // Convert three digits to words
    string threeDigitToWords(int num) const {
        if (num == 0) return "";
        
        string result;
        
        // Handle hundreds
        if (num >= 100) {
            result += ones[num / 100] + " Hundred";
            num %= 100;
            if (num > 0) result += " ";
        }
        
        // Handle tens and ones
        if (num >= 20) {
            result += tens[num / 10];
            if (num % 10 > 0) result += " " + ones[num % 10];
        } else if (num > 0) {
            result += ones[num];
        }
        
        return result;
    }

public:
    // Convert words to number
    long long wordsToNumber(const string& input) const {
        if (input.empty()) return 0;
        
        vector<string> words = splitWords(input);
        if (words.empty()) return 0;
        
        long long total = 0;
        long long current = 0;
        long long lastUnit = 0;
        
        for (const string& word : words) {
            if (basicNumbers.count(word)) {
                int val = basicNumbers.at(word);
                
                if (val == 100) {
                    if (lastUnit == 0) lastUnit = 1;
                    current = current - lastUnit + (lastUnit * 100);
                    lastUnit = 0;
                } else {
                    current += val;
                    lastUnit = val;
                }
            }
            else if (scales.count(word)) {
                if (current == 0) current = 1;
                total += current * scales.at(word);
                current = 0;
                lastUnit = 0;
            }
            else {
                cout << "  Unknown word: '" << word << "' (ignored)\n";
            }
        }
        
        return total + current;
    }

    // Convert number to words
    string numberToWords(long long num) const {
        if (num == 0) return "Zero";
        if (num < 0) return "Negative " + numberToWords(-num);
        
        vector<string> parts;
        int scaleIndex = 0;
        
        while (num > 0) {
            int chunk = num % 1000;
            if (chunk != 0) {
                string chunkWords = threeDigitToWords(chunk);
                if (scaleIndex > 0 && scaleIndex < scaleWords.size()) {
                    chunkWords += " " + scaleWords[scaleIndex];
                }
                parts.insert(parts.begin(), chunkWords);
            }
            num /= 1000;
            scaleIndex++;
        }
        
        string result;
        for (size_t i = 0; i < parts.size(); ++i) {
            if (i > 0) result += " ";
            result += parts[i];
        }
        
        return result;
    }

    // Validate number input
    bool isValidNumber(long long num) const {
        return num >= 0 && num <= 999999999999999LL; // Up to 999 trillion
    }

    // Display supported range
    void showSupportedRange() const {
        cout << " Supported features:\n";
        cout << "   Numbers: 0 to 999,999,999,999,999\n";
        cout << "   Words: Basic numbers, hundred, thousand, million, billion\n";
        cout << "   Special: Handles 'lakh' (100,000) and 'crore' (10,000,000)\n\n";
    }
};

// Static member definitions
const unordered_map<string, int> NumberWordConverter::basicNumbers = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
    {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
    {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
    {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
    {"eighty", 80}, {"ninety", 90}, {"hundred", 100}
};

const unordered_map<string, long long> NumberWordConverter::scales = {
    {"thousand", 1000}, {"lakh", 100000}, {"million", 1000000},
    {"crore", 10000000}, {"billion", 1000000000}
};

const vector<string> NumberWordConverter::ones = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen"
};

const vector<string> NumberWordConverter::tens = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

const vector<string> NumberWordConverter::scaleWords = {
    "", "Thousand", "Million", "Billion", "Trillion"
};

// Utility functions
void printHeader() {
    cout << "\n" << string(50, '=') << "\n";
    cout << " NUMBER to WORDS to NUMBER CONVERTER \n";
    cout << string(50, '=') << "\n\n";
}

void printMenu() {
    cout << " Choose an operation:\n";
    cout << "   1.  Number to Words\n";
    cout << "   2.  Words to Number\n";
    cout << "   3.  Show supported range\n";
    cout << "   4.  Exit\n";
    cout << "\n Enter your choice (1-4): ";
}

long long getNumberInput() {
    long long number;
    while (true) {
        cout << "\n Enter a number: ";
        if (cin >> number) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        } else {
            cout << " Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string getWordsInput() {
    string input;
    cout << "\n Enter number in words: ";
    getline(cin, input);
    return input;
}

bool askToContinue() {
    char choice;
    cout << "Do you want to continue with more calculations? (Y/N): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return (choice == 'Y' || choice == 'y');
}

int main() {
    NumberWordConverter converter;
    int choice;
    
    printHeader();
    converter.showSupportedRange();
    
    while (true) {
        printMenu();
        
        if (!(cin >> choice)) {
            cout << " Invalid input! Please enter a number.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: {
                long long number = getNumberInput();
                if (converter.isValidNumber(number)) {
                    string words = converter.numberToWords(number);
                    cout << "Result: " << words << "\n\n";
                } else {
                    cout << " Number out of supported range!\n\n";
                }
                if (!askToContinue()) {
                    cout << "\n Thank you for using the converter!\n";
                    return 0;
                }
                break;
            }
            
            case 2: {
                string input = getWordsInput();
                if (!input.empty()) {
                    long long result = converter.wordsToNumber(input);
                    cout << "Result: " << result << "\n\n";
                } else {
                    cout << " Empty input!\n\n";
                }
                if (!askToContinue()) {
                    cout << "\n Thank you for using the converter!\n";
                    return 0;
                }
                break;
            }
            
            case 3: {
                converter.showSupportedRange();
                break;
            }
            
            case 4: {
                cout << "\n Thank you for using the converter!\n\n\n";
                return 0;
            }
            
            default: {
                cout << " Invalid choice! Please select 1-4.\n\n";
                break;
            }
        }
    }
    
    return 0;
}