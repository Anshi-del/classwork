
#include <iostream>
#include <limits> 
using namespace std;


bool isPrime(int num) {
    if (num < 2) return false; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false; 
    }
    return true; 
}


int getValidInteger() {
    int num;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;

        // Check if input is valid
        if (cin.fail()) { 
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input! Please enter an integer.\n";
        } else {
            return num; 
        }
    }
}

int main() {
    
    int num = getValidInteger();

    
    if (isPrime(num))
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    return 0;
}