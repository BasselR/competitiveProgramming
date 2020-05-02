#include <iostream>
#include <vector>
// Switch DEBUG to false if you don't want to print the factors
#define DEBUG true

using namespace std;

vector <int> factors(int x) {
    // We will store all factors in `result`
    vector <int> result;
    int i = 1;
    // This will loop from 1 to int(sqrt(x))
    while(i*i <= x) {
        // Check if i divides x without leaving a remainder
        if(x % i == 0) {
            result.push_back(i);
            // Handle the case explained in the 4th
            if(x/i != i) {
                result.push_back(x/i);
            }
        }
        i++;
    }
    // Print in case of debug mode
    if(DEBUG) {
        for(int i=0; i<result.size(); i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
    }
    // Return the list of factors of x
    return result;
}

int main() {
    factors(1);
    // Output: 1
    factors(4);
    // Output: 1 4 2 
    factors(10);
    // Output: 1 10 2 5 
    factors(12); 
    // Output: 1 12 2 6 3 4 
    factors(16);
    // Output: 1 16 2 8 4 
    return 0;
}