/*

    Algorithm Complexity and Big O Notation
    ---------------------------------------
    In computer science, evaluating the efficiency of algorithms is crucial to
    understanding how they will perform as the size of the input grows. This evaluation
   can be done using **algorithmic complexity** or **time complexity**, which provides
   insight into the resources required (e.g., time or memory) to execute an algorithm.
   The most widely used method to express algorithmic complexity is **Big O Notation**.

    1. **Algorithmic Complexity** (Complexité algorithmique):
       It is a measure of the number of operations or steps an algorithm takes in
   relation to the input size (denoted as "n"). For example, how does an algorithm
   behave as 'n' increases from 10 to 1,000 or 1,000,000?

    2. **Big O Notation**:
       Big O notation is used to classify algorithms according to their worst-case time
   or space complexity. It describes the upper bound of an algorithm’s growth rate and
   provides a way to express how the runtime of an algorithm increases with the size of
   the input.

       **Common Big O Time Complexities**:
       -----------------------------------
       - **O(1)**: Constant time – the algorithm takes the same amount of time
   regardless of the input size.
       - **O(log n)**: Logarithmic time – the algorithm’s runtime grows logarithmically
   with the input size.
       - **O(n)**: Linear time – the runtime grows directly in proportion to the input
   size.
       - **O(n log n)**: Linearithmic time – a combination of linear and logarithmic
   growth, commonly seen in efficient sorting algorithms like Merge Sort or Heap Sort.
       - **O(n^2)**: Quadratic time – the runtime grows proportionally to the square of
   the input size, often seen in nested loops.
       - **O(2^n)**: Exponential time – the runtime doubles with each additional
   element in the input.
       - **O(n!)**: Factorial time – grows extremely fast, as the factorial of the
   input size. This is seen in algorithms that try every possible permutation (like the
   Traveling Salesman Problem using brute force).

    3. **Big O Example with a Simple Algorithm**:
       Below, we will look at two examples to better understand how different
   algorithms can have varying time complexities depending on their structure.

    We'll cover the following complexities: O(1), O(log n), O(n), O(n log n), O(n^2),
   O(2^n), and O(n!). Each of these complexities is shown with a simple, practical
   example, making it easier to observe how the time taken grows with increasing input
   size.

    To measure the runtime, we will use simple loops and operations to simulate the
   different complexities. You can change the input size (n) to observe how each
   algorithm scales with respect to n.
*/

#include <cmath>  // For log2() and pow()
#include <iostream>
#include <vector>
using namespace std;

// O(1): Constant time complexity
int constantOperation(const int arr[], int n) {
    // Always returns the first element, regardless of array size
    return arr[0];
}

// O(log n): Logarithmic time complexity (Binary Search)
int binarySearch(const int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // Target not found
}

// O(n): Linear time complexity (Linear Search)
int linearSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Target not found
}

// O(n log n): Linearithmic time complexity (Merge Sort)
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// O(n^2): Quadratic time complexity (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// O(2^n): Exponential time complexity (Fibonacci with recursion)
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// O(n!): Factorial time complexity (Permutations)
void generatePermutations(string str, int l, int r) {
    if (l == r) {
        cout << str << " ";
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            generatePermutations(str, l + 1, r);
            swap(str[l], str[i]);  // backtrack
        }
    }
}

int main() {
    int n = 5;  // You can change this to test larger sizes
    int arr[] = {10, 20, 30, 40, 50};
    int target = 30;

    // Example of O(1): Constant time
    cout << "O(1): Constant time -> First element: " << constantOperation(arr, n)
         << endl;

    // Example of O(log n): Binary Search
    cout << "O(log n): Binary Search -> Index of target: "
         << binarySearch(arr, n, target) << endl;

    // Example of O(n): Linear Search
    cout << "O(n): Linear Search -> Index of target: " << linearSearch(arr, n, target)
         << endl;

    // Example of O(n log n): Merge Sort
    vector<int> vec = {10, 20, 30, 40,
                       50};  // Using vector for easier manipulation in mergeSort
    mergeSort(vec, 0, vec.size() - 1);
    cout << "O(n log n): Merge Sort -> Sorted array: ";
    for (int x : vec)
        cout << x << " ";
    cout << endl;

    // Example of O(n^2): Bubble Sort
    bubbleSort(arr, n);
    cout << "O(n^2): Bubble Sort -> Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Example of O(2^n): Fibonacci (recursion)
    cout << "O(2^n): Fibonacci(5) -> Result: " << fibonacci(5) << endl;

    // Example of O(n!): Permutations
    cout << "O(n!): Permutations of 'ABC': ";
    string str = "ABC";
    generatePermutations(str, 0, str.length() - 1);
    cout << endl;

    return 0;
}

/*
    Output Example (for n = 5):
    ---------------------------
    O(1): Constant time -> First element: 10
    O(log n): Binary Search -> Index of target: 2
    O(n): Linear Search -> Index of target: 2
    O(n log n): Merge Sort -> Sorted array: 10 20 30 40 50
    O(n^2): Bubble Sort -> Sorted array: 10 20 30 40 50
    O(2^n): Fibonacci(5) -> Result: 5
    O(n!): Permutations of 'ABC': ABC ACB BAC BCA CAB CBA

    Explanation of each algorithm:
    ------------------------------
    1. **O(1)**: The constant operation returns the first element from the array,
   independent of the size.
    2. **O(log n)**: The binary search halves the array at every step, leading to
   logarithmic complexity.
    3. **O(n)**: Linear search iterates over the entire array, giving a linear time
   complexity.
    4. **O(n log n)**: Merge sort repeatedly splits the array and merges it, taking n
   log n time.
    5. **O(n^2)**: Bubble sort uses nested loops, hence the quadratic time complexity.
    6. **O(2^n)**: The recursive Fibonacci function calculates all possible branches,
   leading to exponential growth.
    7. **O(n!)**: Permutations generate all possible orderings of the string, with
   factorial complexity.
*/

/*
    Understanding Growth Rates:
       The reason Big O notation is crucial is because as input size increases, the
   difference between time complexities becomes more apparent. For example, an O(n^2)
   algorithm may be faster than an O(n) algorithm for small inputs, but as 'n' grows
   larger, the O(n) algorithm will outperform the O(n^2) one significantly.

    Below is a comparison of common time complexities for different input sizes:

    |  n  |  O(1)  |  O(log n)  |  O(n)  |  O(n log n)  |  O(n^2)  |  O(2^n)  |  O(n!)
    |
    |-----|--------|------------|--------|--------------|----------|----------|-------|
    | 10  |   1    |     3      |   10   |     30       |   100    |   1024   |  3.6M |
    | 20  |   1    |     4      |   20   |     86       |   400    |   1M     |  2.4B |
    | 30  |   1    |     5      |   30   |    148       |   900    |   1B |  2.65E32|

    Notice how quickly the O(n^2), O(2^n), and O(n!) complexities grow compared to
   others.
*/
