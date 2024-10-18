# LAB2---GDC

Key Points:

GCD Subtraction:
It subtracts the smaller number from the larger one repeatedly until the two numbers become equal.

GCD Modulo:
This method uses the modulo operator to reduce the numbers, and it's much faster, especially for large numbers.

Unit Testing:
The test_GCD function checks the correctness of both methods using a couple of known test cases.

Measuring Execution Time:
The measure_execution_time function uses the <chrono> library to measure how long each GCD calculation takes. The times are printed in microseconds for both the subtraction and modulo methods.
