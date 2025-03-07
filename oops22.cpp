#include <iostream>
using namespace std;
class SwapNumbers {
private:
    int a, b, c;
public:

    void getInput() {

        cout << "Enter three numbers: ";

        cin >> a >> b >> c;

    }

    void display() {

        cout << "Numbers: " << a << " " << b << " " << c << endl;

    }
    // Function to swap numbers cyclically (call by reference)

    void swapCyclic(int &x, int &y, int &z) {

        int temp = x;

        x = z;

        z = y;

        y = temp;

    }

    // Function to call swap function on object variables

    void performSwap() {

        swapCyclic(a, b, c);

    }

};



int main() {

    SwapNumbers obj;



    // Taking input from user

    obj.getInput();



    cout << "\nBefore swapping:" << endl;

    obj.display();



    // Perform cyclic swap

    obj.performSwap();



    cout << "\nAfter swapping:" << endl;

    obj.display();

    return 0;

}