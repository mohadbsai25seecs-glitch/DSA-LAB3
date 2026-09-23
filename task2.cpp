#include <iostream>
#include <string>
using namespace std;

class StringPool {
private:
    string* stringPool;   // array that holds the strings
    int currentSize;      // how many strings are in the pool right now
    int maxSize;           // max strings allowed

public:
    // Constructor 
    StringPool() {
        maxSize = 5;
        currentSize = 0;
        stringPool = new string[maxSize];   // create the array on the heap
    }

    // Destructor - runs when the StringPool is destroyed
    ~StringPool() {
        delete[] stringPool;   // free-ing the array 
    }

    // Add a string to the pool
    void addString(string str) {
        if (currentSize < maxSize) {
            stringPool[currentSize] = str;
            currentSize++;
            cout << "Added: " << str << endl;
        }
        else {
            cout << "Pool is full, cannot add: " << str << endl;
        }
    }

    // Remove a string WITHOUT freeing memory ( creates the leak)
    void remove_String(int index) {
        if (index < 0 || index >= currentSize) {
            cout << "Invalid index!" << endl;
            return;
        }
        string* leaked = new string(stringPool[index]);
        cout << "Removed: " << *leaked << " (not deleted yet - LEAK!)" << endl;

        // shift everything after it one step back to fill the gap
        for (int i = index; i < currentSize - 1; i++) {
            stringPool[i] = stringPool[i + 1];
        }
        currentSize--;
    }

    // Show what's currently in the pool
    void showPool() {
        cout << "\nPool has " << currentSize << " string(s):" << endl;
        for (int i = 0; i < currentSize; i++) {
            cout << "  " << stringPool[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    StringPool pool;

    // Step 1: hard codin the strings
    pool.addString("apple");
    pool.addString("banana");
    pool.addString("cherry");

    pool.showPool();

    // Step 2: remove a string without freeing memory (causes a leak)
    pool.remove_String(1);   // removes the string "banana"

    pool.showPool();
    cout << "Program finished." << endl;
    cin.get();
    return 0;
}