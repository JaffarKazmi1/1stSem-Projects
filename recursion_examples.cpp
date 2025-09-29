#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Factorial using recursion
long long factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

// 2. Fibonacci sequence using recursion
long long fibonacci(int n) {
    // Base cases
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. Sum of digits using recursion
int sumOfDigits(int n) {
    // Base case
    if (n == 0) {
        return 0;
    }
    // Recursive case
    return (n % 10) + sumOfDigits(n / 10);
}

// 4. Power function using recursion
double power(double base, int exponent) {
    // Base case
    if (exponent == 0) {
        return 1;
    }
    if (exponent < 0) {
        return 1.0 / power(base, -exponent);
    }
    // Recursive case
    return base * power(base, exponent - 1);
}

// 5. Greatest Common Divisor (GCD) using recursion
int gcd(int a, int b) {
    // Base case
    if (b == 0) {
        return a;
    }
    // Recursive case
    return gcd(b, a % b);
}

// 6. Binary search using recursion
int binarySearch(vector<int>& arr, int target, int left, int right) {
    // Base case - element not found
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    // Base case - element found
    if (arr[mid] == target) {
        return mid;
    }
    
    // Recursive cases
    if (arr[mid] > target) {
        return binarySearch(arr, target, left, mid - 1);
    } else {
        return binarySearch(arr, target, mid + 1, right);
    }
}

// 7. Tower of Hanoi using recursion
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    
    // Recursive cases
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the largest disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// 8. Check if string is palindrome using recursion
bool isPalindrome(const string& str, int start, int end) {
    // Base case
    if (start >= end) {
        return true;
    }
    
    // Check if characters match and recurse
    if (str[start] != str[end]) {
        return false;
    }
    
    return isPalindrome(str, start + 1, end - 1);
}

// 9. Print array elements using recursion
void printArray(vector<int>& arr, int index) {
    // Base case
    if (index >= arr.size()) {
        return;
    }
    
    // Print current element and recurse
    cout << arr[index] << " ";
    printArray(arr, index + 1);
}

// 10. Reverse a string using recursion
string reverseString(const string& str, int index) {
    // Base case
    if (index >= str.length()) {
        return "";
    }
    
    // Recursive case
    return reverseString(str, index + 1) + str[index];
}

int main() {
    cout << "=== C++ Recursion Examples ===" << endl << endl;
    
    // 1. Factorial
    cout << "1. Factorial:" << endl;
    int num = 5;
    cout << "Factorial of " << num << " = " << factorial(num) << endl << endl;
    
    // 2. Fibonacci
    cout << "2. Fibonacci:" << endl;
    cout << "First 10 Fibonacci numbers: ";
    for (int i = 0; i < 10; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl << endl;
    
    // 3. Sum of digits
    cout << "3. Sum of Digits:" << endl;
    int number = 12345;
    cout << "Sum of digits of " << number << " = " << sumOfDigits(number) << endl << endl;
    
    // 4. Power function
    cout << "4. Power Function:" << endl;
    double base = 2.5;
    int exp = 3;
    cout << base << " raised to power " << exp << " = " << power(base, exp) << endl << endl;
    
    // 5. GCD
    cout << "5. Greatest Common Divisor:" << endl;
    int a = 48, b = 18;
    cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl << endl;
    
    // 6. Binary Search
    cout << "6. Binary Search:" << endl;
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 9;
    cout << "Array: ";
    printArray(arr, 0);
    cout << endl;
    int result = binarySearch(arr, target, 0, arr.size() - 1);
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found" << endl;
    }
    cout << endl;
    
    // 7. Tower of Hanoi
    cout << "7. Tower of Hanoi (3 disks):" << endl;
    towerOfHanoi(3, 'A', 'C', 'B');
    cout << endl;
    
    // 8. Palindrome check
    cout << "8. Palindrome Check:" << endl;
    string testStr = "racecar";
    cout << "Is '" << testStr << "' a palindrome? " 
         << (isPalindrome(testStr, 0, testStr.length() - 1) ? "Yes" : "No") << endl;
    testStr = "hello";
    cout << "Is '" << testStr << "' a palindrome? " 
         << (isPalindrome(testStr, 0, testStr.length() - 1) ? "Yes" : "No") << endl << endl;
    
    // 9. Reverse string
    cout << "9. Reverse String:" << endl;
    string original = "Hello World";
    cout << "Original: " << original << endl;
    cout << "Reversed: " << reverseString(original, 0) << endl << endl;
    
    return 0;
}