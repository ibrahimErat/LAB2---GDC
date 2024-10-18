#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

// Function to compute GCD using subtraction
long long int GCD_subtraction(long long int a, long long int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

// Function to compute GCD using modulo operation
long long int GCD_modulo(long long int a, long long int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to test the correctness of the GCD functions
void test_GCD() {
    // Test cases
    if (GCD_subtraction(10, 5) == 5 && GCD_subtraction(48, 18) == 6) {
        cout << "GCD_subtraction tests passed!" << endl;
    } else {
        cout << "GCD_subtraction tests failed!" << endl;
    }

    if (GCD_modulo(10, 5) == 5 && GCD_modulo(48, 18) == 6) {
        cout << "GCD_modulo tests passed!" << endl;
    } else {
        cout << "GCD_modulo tests failed!" << endl;
    }
}

// Function to measure execution time for both methods
void measure_execution_time() {
    long long int numbers[][2] = {{1000, 3}, {1000000, 3}, {10000000000, 3}};
    
    for (auto& pair : numbers) {
        long long int a = pair[0];
        long long int b = pair[1];
        
        // Measure time for GCD_subtraction
        auto start = high_resolution_clock::now();
        GCD_subtraction(a, b);
        auto stop = high_resolution_clock::now();
        auto duration_sub = duration_cast<microseconds>(stop - start);
        
        // Measure time for GCD_modulo
        start = high_resolution_clock::now();
        GCD_modulo(a, b);
        stop = high_resolution_clock::now();
        auto duration_mod = duration_cast<microseconds>(stop - start);
        
        // Print results
        cout << "For numbers " << a << " and " << b << ":" << endl;
        cout << "GCD_subtraction time: " << duration_sub.count() << " microseconds" << endl;
        cout << "GCD_modulo time: " << duration_mod.count() << " microseconds" << endl;
        cout << endl;
    }
}

int main() {
    
    test_GCD();
    
    
    measure_execution_time();

    return 0;
}
