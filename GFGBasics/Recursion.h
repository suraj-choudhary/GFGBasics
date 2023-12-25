//
//  DynamicProgramming.h
//  GFGBasics
//
//  Created by suraj kumar on 22/12/23.
//

#ifndef DynamicProgramming_h
#define DynamicProgramming_h
#include "string.h"

using namespace std;

#endif /* DynamicProgramming_h */

// MARK: Factorial:-----------------

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

// MARK: Fibonacci---------

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
// MARK: Check if array is sorted or not---------


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


// MARK: Print 1....N Recursively Way--------------
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

// MARK: Power function:-----------


/// Description
/// - Parameters:
///   - a: a description
///   - n: n description
int power(int a, int n) {
    //base case
    
    if(n == 0) {
        return 1;
    }
    return a * power(a, n - 1);
}

/// Description
/// - Parameters:
///   - a: a description
///   - n: n description
int fastPower(int a, int n) {
    if(n == 0) {
        return 1;
    }
    int subprob = fastPower(a, n / 2);
    int subProbSq = subprob * subprob;
    if(n & 1) {
        return a * subprob;
    }
    
    return subProbSq;
}

// MARK: Tiling problem----
/*
 Given  a 4 * n board and tiles of size 4 * 1, count the number of ways
 to tile the given baord using the 4 * 1
 A tile can either be placed horizontally i,e as  1 * 4 or tile or vertically i.e
 as 4 * 1
 */


/*
 f(n) = f(n - 1) + f(n - 4)
 */


/// Description
/// - Parameter N: N description
int Tiling(int N) {
    if(N < 3) {
        return N;
    }
    int ans = Tiling(N - 1) + Tiling(N - 4);
    return ans;
}


/// Description
/// - Parameters:
///   - S: S description
///   - k: k description
void perm(char S[], int k) {
    static int A[10] = {0};
    static char res[10];
    int i;
    
    if(S[k] == '\0') {
        res[k] = '\0';
        printf("%s ", res);
    } else {
        for(i = 0; S[i] != '\0'; i++) {
            if(A[i] == 0) {
                res[k] = S[i];
                A[i] = 1;
                perm(S, k + 1);
                A[i] = 0;
            }
        }
    }
}

void allPermutation() {
    char str[] = "ABC";
    int k = 0;
    perm(str, k);
}
// MARK: Count Binary String----

/*
 Count the Number of Binary String with no consecutive once that can be formed using binary
 string of lenght N.
 */

void countStrings(int n, string out1, int last_digit) {
    
    if (n == 0)
    {
        cout << out1 << endl;
        return;
    }
    
    countStrings(n - 1, out1 + "0", 0);
    if (last_digit == 0) {
        countStrings(n - 1, out1 + "1", 1);
    }
}

void print() {
    countStrings(2, "", 0);

}


/// Description
/// - Parameter n: n description
string BinaryString(int n) {
    if (n == 0) {
        return "0";
    }
    string str = "";
    while (n > 0) {
        str = char('0' + n % 2) + str;
        n = n / 2;
    }
    return str;
}


/// Description
/// - Parameters:
///   - str: str description
///   - size: size description
void noconsecutive(string str, int k) {
    static int A[10] = {0};
    static char res[10];
    
    if(str[k] == '\0') {
        res[k] = '\0';
        printf("%s ", res);
    } else {
        for(int i = 0; str[i] != '\0'; i++) {
            if(A[i] == 0) {
                res[k] = str[i];
                A[i] = 1;
                noconsecutive(str, k + 1);
                A[i] = 0;
            }
        }
    }
    
}
