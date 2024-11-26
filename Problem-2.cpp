/*
  Problem 2: "Library Book Borrowing Analysis"
  - Accepts a list of borrowed books wirrowed th the format: "Book Title - Days Borrowed".
  - Calculates the most and least borrowed book based on the number of days.
  - Calculates the average number of days books were borrowed.
  - Finds the unique titles of all borrowed books. ?????
  - Sorts the books by the number of days borrowed in descending order.
  
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<string, int> record;
    string book;
    char dash, check;
    int days;

    cout << "Enter borrowed books format: \"Book Title - Days Borrowed\":  ";
    do {
        cin >> book >> dash >> days;
        record.insert({book, days});
        cout << "Do you want to enter another record (Y/N):  ";
        cin >> check;
    } while (check == 'y' || check == 'Y');

    auto mostBook = record.begin();
    auto leastBook = record.begin();
    int sum = 0;

    for (auto it = record.begin(); it != record.end(); ++it) {
        if (it->second > mostBook->second) mostBook = it;
        if (it->second < leastBook->second) leastBook = it;
        sum += it->second;
    }

    cout << endl;
    cout << "Least: " << leastBook->first << " - " << leastBook->second << " days" << endl;
    cout << "Most: " << mostBook->first << " - " << mostBook->second << " days" << endl;
    cout << "Average days: " << sum / record.size() << endl;

    cout << "============" << endl;

    // Store records in a vector for sorting
    vector<pair<string, int>> sortedRecords(record.begin(), record.end());

    // Sort by days borrowed in descending order
    sort(sortedRecords.begin(), sortedRecords.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    cout << "Sorted Books by Days Borrowed:" << endl;
    for (const auto& ptr : sortedRecords) {
        cout << ptr.first << " - " << ptr.second << " days" << endl;
    }

    return 0;
}