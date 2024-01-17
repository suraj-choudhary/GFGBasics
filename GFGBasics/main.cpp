//
//  main.cpp
//  GFGBasics
//
//  Created by suraj kumar on 09/12/23.
//

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include "Recursion.h"
#include "GFGQuestion.h"

using namespace::std;

// MARK: Binary Search
/*
 Input:
 N = 5
 arr[] = {1, 2, 3, 4, 5}
 K = 4
 Output: 3
 Explanation: 4 appears at index 3.
 */

/// This code is for searching the element using binary serach alogrith
/// - Parameters:
///   - arr: arr of element
///   - size: size of arr
///   - key: key which i want to search
void BinarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == key) {
            printf("%d ", mid);
            break;
        }
        if(arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Not found");
    return;
}

//MARK: Recursive Binary Search:

/// Recursive Binary Search
/// - Parameters:
///   - arr: arr description
///   - left: left description
///   - right: right description
///   - key: key description
int recusiveBinarSearch(int arr[], int left, int right, int key) {
    int mid = left + (right - 1) / 2;
    if(left <= right) {
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            recusiveBinarSearch(arr, mid + 1, right, key);
        } else {
            recusiveBinarSearch(arr, left, mid - 1, key);
        }
    }
    return -1;
}

/*
 int main() {
 int arr[] = {1, 2, 3, 4, 5};
 int size = sizeof(arr) / sizeof(arr[0]);
 int key = 0;
 printf("Enter the key you want to search:");
 scanf("%d", &key);
 BinarySearch(arr, size, key);
 }
 */



// MARK: Power of 2
/// 8  ->   8 / 2 = 4

bool isPowerOfTwo(int n) {
    if(n == 0) {
        return false;
    }
    while (n != 1) {
        if(n % 2 != 0) {
            return false;
        }
        n = n / 2;
    }
    return true;
}

/*
 int main() {
 bool sucess = isPowerOfTwo(8);
 
 std::string s = sucess == true ? "YES" : "No";
 printf("%s", s.c_str());
 }
 
 */

// MARK: Union of two arrays using two pointer

/*
 Input:
 5 3
 1 2 3 4 5
 1 2 3
 Output:
 5
 Explanation:
 1, 2, 3, 4 and 5 are the
 elements which comes in the union set
 of both arrays. So count is 5.
 */


/// Description
/// - Parameters:
///   - a: a description
///   - n: n description
///   - b: b description
///   - m: m description
int doUnion(int a[], int n, int b[], int m) {
    int arr[m + n];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            arr[k++] = a[i++];
        } else if (a[i] > b[j]) {
            arr[k++] = b[j++];
        } else {
            arr[k++] = a[i++];
            j++;
        }
    }
    while (i < n) {
        arr[k++] = a[i++];
    }
    while (j < m) {
        arr[k++] = b[j++];
    }
    for (int l = 0; l < k; l++) {
        printf("%d ", arr[l]);
    }
    return k;
}

/*
 int main() {
 int a[] = {1, 2, 3, 4, 5, 8};
 int b[] = {1, 2, 3};
 int n = sizeof(a) / sizeof(a[0]);
 int m = sizeof(b) / sizeof(b[0]);
 int count = doUnion(a, n, b, m);
 printf("\nCount: %d\n", count);
 return 0;
 }
 
 */
// MARK: Union of two arrays using sets

vector<int> Unionarray(int a[], int n, int b[], int m) {
    set<int>res;
    for(int i = 0; i < n; i++) {
        res.insert(a[i]);
    }
    for(int j = 0; j < m; j++) {
        res.insert(b[j]);
    }
    vector<int> vec(res.begin(), res.end());
    return vec;
}

/*
 int main() {
 int a[] = {1, 2, 3, 4, 5, 8};
 int b[] = {1, 2, 3};
 int n = sizeof(a) / sizeof(a[0]);
 int m = sizeof(b) / sizeof(b[0]);
 Unionarray(a, n, b, m);
 return 0;
 }
 */


//MARK: Reverse a String

/*
 Input:
 s = Geeks
 Output: skeeG
 */


/// Description
/// - Parameter str: str description
string reverseWord(string str) {
    int start = 0;
    int n = str.size();
    while (start < n / 2) {
        char temp = str[start];
        str[start] = str[n - 1 - start];
        str[n - 1 - start] = temp;
        start++;
    }
    return str;
}
/*
 
 int main() {
 string str = "Geeks";
 reverseWord(str);
 }
 
 */

// MARK: Check if two arrays are equal or not

/*
 N = 5
 A[] = {1,2,5,4,0}
 B[] = {2,4,5,0,1}
 Output: 1
 Explanation: Both the array can be
 rearranged to {0,1,2,4,5}
 */

void sorting(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
//sort(A.begin(), A.begin() + N);
bool check(int a[], int b[], int N) {
    sorting(a, N);
    sorting(b, N);
    
    int start = 0;
    
    for(int k = 0; k < N; k++) {
        if(a[k] != b[start]) {
            printf("false");
            return false;
        }
        start++;
    }
    printf("true");
    return 0;
}

/*
 int main() {
 int a[] = {1,2,6,4,0};
 int b[] = {2,4,5,0,1};
 check(a, b, 5);
 }
 
 */


// MARK: Check if two arrays are equal or not using Sorting

bool areEqual(int arr1[], int arr2[], int N, int M) {
    if(N != M) {
        return false;
    }
    unordered_map<int, int>mp;
    for(int i = 0; i < N; i++) {
        mp[arr1[i]]++;
    }
    
    return true;
}
/*
 int main() {
 int arr1[] = {3, 5, 2, 5, 2};
 int arr2[] = {2, 3, 5, 5, 2};
 int N = sizeof(arr1) / sizeof(arr1[0]);
 int M = sizeof(arr2) / sizeof(arr2[0]);
 
 }
 */



// MARK: Reverse array in groups

/*
 Input:
 N = 5, K = 3
 arr[] = {1,2,3,4,5}
 Output: 3 2 1 5 4
 Explanation: First group consists of elements
 1, 2, 3. Second group consists of 4,5.
 */


void Display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}


/// Description
/// - Parameters:
///   - arr: arr description
///   - size: size description
///   - k: k description
void reverseInGroups(int arr[], int size, int k) {
    
    for(int i = 0; i < size; i += k) {
        int left = i;
        int right;
        if(i + k - 1 < size - 1) {
            right = i + k - 1;
        } else {
            right = size - 1;
        }
        while (left < right) {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            left++;
            right--;
        }
    }
    Display(arr, size);
}

/*
 int main() {
 int arr[] = {1,2,3,4,5, 7, 8, 9};
 int size = sizeof(arr) / sizeof(arr[0]);
 int k = 3;
 reverseInGroups(arr, size, k);
 }
 */


/*
 Input:
 n = 4
 arr[] = {1,2,3,4}
 x = 3
 Output: 2
 Explanation: There is one test case
 with array as {1, 2, 3 4} and element
 to be searched as 3.  Since 3 is
 present at index 2, output is 2.
 
 */
int search(int arr[], int N, int X) {
    
    for(int i = 0; i < N; i++) {
        if(arr[i] == X) {
            return i;
        }
    }
    return -1;
}
/*
 int main() {
 int arr[] = {1,2,3,4};
 int size = sizeof(arr) / sizeof(arr[0]);
 int x = 3;
 search(arr, size, x);
 }
 
 */

/*
 Input:
 a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
 a2[] = {11, 3, 7, 1, 7}
 Output:
 Yes
 Explanation:
 a2[] is a subset of a1[]
 */
int isSubset(int a1[], int a2[], int n, int m) {
    
    for(int i = 0; i < n; i++) {
        
        for(int j = 0; j < m; j++) {
            if(a1[i] == a2[j]) {
                break;
            }
            if(j == m) {
                return 0;
            }
        }
        
    }
    return 1;
}

/*
 
 int main() {
 int  a1[] = {11, 7, 1, 13, 21, 3, 7, 3};
 int  a2[] = {11, 3, 7, 1, 7};
 int n = sizeof(a1) / sizeof(a1[0]);
 int m = sizeof(a2) / sizeof(a2[0]);
 
 }
 
 */


string isSubset2(int a1[], int a2[], int n, int m) {
    
    unordered_map<int, int> um, um2;
    
    for (int i = 0; i < n; i++) {
        um[a1[i]]++;
    }
    
    for (int i = 0; i < m; i++) {
        um2[a2[i]]++;
    }
    
    int count = 0;
    for (auto it = um2.begin(); it != um2.end(); it++) {
        if (um[it->first] >= it->second) {
            count+=it->second;
        }
    }
    
    if (count == m)
        return "Yes";
    else
        return "No";
}

///Cyclically rotate an array by one

/*
 Input:
 N = 5
 A[] = {1, 2, 3, 4, 5}
 Output:
 5 1 2 3 4
 */


/// Description
/// - Parameters:
///   - x: x description
///   - y: y description
void swaping(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/// Description
/// - Parameters:
///   - arr: arr description
///   - n: n description
void rotate(int arr[], int n) {
    
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        swaping(&arr[i], &arr[j]);
        i++;
    }
}

/// Description
/// - Parameters:
///   - arr: arr description
///   - n: n description
void rotate2(int arr[], int n)
{
    int x = arr[n - 1], i;
    for (i = n - 1; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
}
/*
 int main() {
 int  arr[] = {1, 2, 3, 4, 5};
 int size = sizeof(arr) / sizeof(arr[0]);
 rotate2(arr, size);
 Display(arr, size);
 }
 
 */

// MARK: Find minimum and maximum element in an array
/*
 Input:
 N = 6
 A[] = {3, 2, 1, 56, 10000, 167}
 Output: 1 10000
 Explanation: minimum and maximum elements of array are 1 and 10000.
 */

struct Pair {
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair minMax, mml, mmr;
    int mid;
    // If there is only one element
    if(low == high) {
        minMax.max = arr[low];
        minMax.min = arr[low];
    }
    // If there are two elements
    
    if(high == low + 1) {
        if(arr[low] > arr[high]) {
            minMax.max = arr[low];
            minMax.min = arr[high];
        } else {
            minMax.max = arr[high];
            minMax.min = low;
        }
        return minMax;
    }
    // If there are more than 2 elements
    mid = (low + high) / 2;
    
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);
    
    if (mml.min < mmr.min)
        minMax.min = mml.min;
    else
        minMax.min = mmr.min;
    
    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minMax.max = mml.max;
    else
        minMax.max = mmr.max;
    
    return minMax;
}
/*
 int main() {
     int  arr[] = {3, 2, 1, 56, 10000, 167};
     int size = sizeof(arr) / sizeof(arr[0]);
 }
 */


// MARK: Print first n Fibonacci Numbers


/*
 Input:
 N = 5
 Output: 1 1 2 3 5
 */
void printFibb(int n) {
   
}


// MARK: Main method ---------------------------

int main() {
    getAllSubSet();
}
