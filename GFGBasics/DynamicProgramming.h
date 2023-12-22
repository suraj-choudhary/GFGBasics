//
//  DynamicProgramming.h
//  GFGBasics
//
//  Created by suraj kumar on 22/12/23.
//

#ifndef DynamicProgramming_h
#define DynamicProgramming_h


#endif /* DynamicProgramming_h */

// MARK: Factorial:

/*
 f(n) = n * f(n - 1)
 */

/// Description
/// - Parameter N: N description
int Factorial(int N) {
    if(N == 0) {
        return 1;
    }
    
    return N * Factorial(N - 1);
}

// MARK: Fibonacci

/*
 f(n) =  f(n - 1) + f(n - 2)
 */


/// Description
/// - Parameter n: n description
int fib(int n) {
    
    if(n == 0 || n == 1) {
        return n;
    }
    int f1 = fib(n - 1);
    int f2 = fib(n - 2);
    int ans = f1 + f2;
    return ans;
    
}


// MARK: Check if array is sorted or not


/// Description
/// - Parameters:
///   - arr: arr description
///   - n: n description
bool isSorted(int arr[], int n) {
    //base case
    if(n == 1 || n== 0) {
        return true;
    }
    if(arr[0] < arr[1] && isSorted(arr + 1, n - 1)) {
        return true;
    }
    return false;
}


/// Description
/// - Parameters:
///   - arr: arr description
///   - i: i description
///   - n: n description
bool isSortedTwo(int arr[], int i, int n) {
    if(i == n - 1) {
        return true;
    }
    if(arr[i] < arr[i + 1] && isSortedTwo(arr, i + 1, n)) {
        return true;
    }
    return false;
}


// MARK: Print 1....N Recursively in
/*
 1. increasing order
 2.Decreasing order
 */


/// Description
/// - Parameter n: n description
void decreasing(int n) {
    if(n == 0) {
        return;
    }
    printf("%d ", n);
    decreasing(n - 1);
}


/// Description
/// - Parameter n: n description
void inccreasingOrder(int n) {
    if(n == 0) {
        return;
    }
    decreasing(n - 1);
    printf("%d ", n);
}

// MARK: Power function:


