#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <limits>
using namespace std;

/*
  Simple helper: make a string lowercase.
  I do this so "Apples" and "apples" count as the same item.
*/
string ToLower(string s) {
    for (char& c : s) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }
    return s;
}

/*
  CLASS: GroceryTracker
  - loads items from the text file
  - counts how many times each item shows up (map)
  - can print all items, print a histogram, and write a backup file
*/
class GroceryTracker {
private:
    map<string, int> counts;   // item -> how many times

public:
    // Load items from file. Returns true if it worked.
    bool Load(const string& fileName) {
        ifstream in(fileName);
        if (!in.is_open()) {
            return false; // file not found or can't be opened
        }

        // Read word-by-word (works even if there are spaces/newlines)
        string word;
        while (in >> word) {
            word = ToLower(word);
            if (!word.empty()) {
                counts[word]++;
            }
        }
        return true;
    }

    // Write backup data like "apples 5" to frequency.dat
    bool WriteBackup(const string& outName = "frequency.dat") const {
        ofstream out(outName);
        if (!out.is_open()) {
            return false; // couldn't create/write the file
        }
        for (const auto& kv : counts) {
            out << kv.first << " " << kv.second << "\n";
        }
        return true;
    }

    // Get count for one item (0 if not found)
    int GetCount(const string& rawItem) const {
        string key = ToLower(rawItem);
        auto it = counts.find(key);
        if (it == counts.end()) return 0;
        return it->second;
    }

    // Print every item and its count
    void PrintAll() const {
        if (counts.empty()) {
            cout << "No data loaded.\n";
            return;
        }
        for (const auto& kv : counts) {
            cout << kv.first << " " << kv.second << "\n";
        }
    }

    // Print histogram using asterisks
    void PrintHistogram() const {
        if (counts.empty()) {
            cout << "No data loaded.\n";
            return;
        }
        for (const auto& kv : counts) {
            cout << kv.first << " ";
            // print as many * as the count
            for (int i = 0; i < kv.second; ++i) {
                cout << '*';
            }
            cout << "\n";
        }
    }
};

// Small helper so bad input (like letters) doesn’t crash the menu
int ReadMenuChoice(int minVal, int maxVal) {
    int v;
    while (true) {
        if (cin >> v && v >= minVal && v <= maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
            return v;
        }
        cout << "Please enter a number " << minVal << "-" << maxVal << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    // Keep your same path (put the file in a "data" folder next to the .exe)
    const string INPUT_FILE = "data/CS210_Project_Three_Input_File.txt";

    GroceryTracker gt;

    // Load the data once
    if (!gt.Load(INPUT_FILE)) {
        cout << "Could not open: " << INPUT_FILE << "\n";
        cout << "Tip: In Visual Studio, set the TXT file's 'Copy to Output Directory' to 'Copy if newer'.\n";
        cout << "Press Enter to exit...";
        cin.get();
        return 1;
    }

    // Write the backup file at start (frequency.dat)
    if (!gt.WriteBackup("frequency.dat")) {
        cout << "Warning: couldn't write frequency.dat (not a show-stopper).\n";
    }

    // Simple menu loop
    while (true) {
        cout << "\n=== Corner Grocer ===\n";
        cout << "1) Look up one item\n";
        cout << "2) Print all items\n";
        cout << "3) Histogram\n";
        cout << "4) Exit\n";
        cout << "Choose 1-4: ";

        int choice = ReadMenuChoice(1, 4);

        if (choice == 1) {
            // Ask for an item and show its count
            cout << "Item name: ";
            string item;
            getline(cin, item); // read whole line in case of spaces
            int n = gt.GetCount(item);
            cout << ToLower(item) << " " << n << "\n";
        }
        else if (choice == 2) {
            // Print all items with counts
            gt.PrintAll();
        }
        else if (choice == 3) {
            // Print the asterisk histogram
            gt.PrintHistogram();
        }
        else { // 4
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
