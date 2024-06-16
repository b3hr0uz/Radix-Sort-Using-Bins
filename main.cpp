//
//  main.cpp
//  Radix-Sort-Using-Bins
//
//  Created by Behrouz Barati B on 6/15/24.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Function to pad names with spaces to make them equal length
void padNames(vector<string> &names) {
    size_t maxLength = 0;
    // Find the maximum length of the names
    for (const auto &name : names) {
        if (name.length() > maxLength) {
            maxLength = name.length();
        }
    }
    // Pad each name with spaces
    for (auto &name : names) {
        while (name.length() < maxLength) {
            name += ' ';
        }
    }
}

// Function to perform radix sort on names in descending order
void radixSort(vector<string> &names) {
    int radix = 27; // A-Z + space
    int maxLength = int(names[0].length());
    
    // Perform a pass for each character position, starting from the end
    for (int pos = maxLength - 1; pos >= 0; pos--) {
        vector<queue<string>> bins(radix);

        // Place each name into the appropriate bin
        for (const auto &name : names) {
            char ch = name[pos];
            int binIndex = (ch == ' ') ? 0 : (ch - 'A' + 1);
            bins[binIndex].push(name);
        }

        // Collect names from bins in reverse order to sort in descending order
        int index = 0;
        for (int i = radix - 1; i >= 0; i--) {
            while (!bins[i].empty()) {
                names[index++] = bins[i].front();
                bins[i].pop();
            }
        }

        // Display partially sorted names after each pass
        cout << "After pass " << maxLength - pos << ":" << endl;
        for (const auto &name : names) {
            cout << name << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<string> names = {
        "OLIVIA", "EMMA", "AMELIA", "CHARLOTTE", "AVA",
        "SOPHIA", "MIA", "ISABELLA", "EVELYN", "LUNA",
        "LIAM", "NOAH", "OLIVER", "JAMES", "ELIJAH",
        "HENRY", "WILLIAM", "LUCAS", "BENJAMIN", "THEODORE"
    };

    // Pad names with spaces
    padNames(names);

    // Display original names
    cout << "Original names:" << endl;
    for (const auto &name : names) {
        cout << name << endl;
    }
    cout << endl;

    // Perform radix sort
    radixSort(names);

    // Display fully sorted names
    cout << "Fully sorted names:" << endl;
    for (const auto &name : names) {
        cout << name << endl;
    }
    cout << endl;

    return 0;
}
