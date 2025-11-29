#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList l;

    // Insert data
    l.insertFirst(1, "Mahmoud");
    l.insertEnd(2, "Khaled");
    l.insertAfter(3, "Nada");

    // Display data
    cout << "Initial list:" << endl;
    l.Dispaly();

    // Reverse the current data
    l.reverse();
    cout << "===========================" << endl;
    l.Dispaly();

    // is sorted
    cout << "\nIs list sorted? " << (l.Sorted() ? "Yes" : "No") << endl;


    l.selectionSort();
    cout << "\nAfter selectionSort:" << endl;
    l.Dispaly();

    // Get middle Employee
    cout << "\nMiddle Employee ID: " << l.getMiddle() << endl;

    // search
    int searchId = 102;
    cout << "\nSearching for ID " << searchId << ": "
         << (l.search(searchId) ? "Found" : "Not Found") << endl;

    return 0;
}
