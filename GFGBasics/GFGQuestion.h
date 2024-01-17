//
//  GFGQuestion.h
//  GFGBasics
//
//  Created by suraj kumar on 16/01/24.
//

#ifndef GFGQuestion_h
#define GFGQuestion_h

// MARK: Subarray with given sum
/*
 
 Input:
 N = 5, S = 12
 A[] = {1,2,3,7,5}
 Output: 2 4
 Explanation: The sum of elements
 from 2nd position to 4th position
 is 12.
 */
/*
 Find subarray with given sum using Sliding Window
 */

vector<int> subarraySum(int arr[], int s, int n) {
    int cSum = arr[0];
    int start = 0;
    int found = false;
    vector<int>v;
    for(int i = 1; i <= n; i++) {
        while(cSum > s && start < i - 1) {
            cSum = cSum - arr[start];
            start++;
        }
        if(cSum == s) {
            v.push_back(start + 1);
            v.push_back(i);
            found = true;
            break;
        }
        cSum = cSum + arr[i];
    }
    if(found==false)
        v.push_back(-1);
    return v;
}

void subArraySum2(int arr[], int n, int sum) {
    for(int i = 0; i < n; i++) {
        int cSum = arr[i];
        if (cSum == sum) {
            cout << "Sum found at indexes " << i << endl;
            return;
        } else {
            for(int j = i + 1; j < n; j++) {
                cSum += arr[j];
                if(cSum == sum) {
                    cout << "Sum found between indexes "
                    << i << " and " << j << endl;
                    return;
                }
            }
        }
    }
    cout << "No subarray found";
    return;
}


void missingNumber(vector<int>&arr, int n) {
    int size = arr.size();
    int sum = 0;
    int tSum = n * (n - 1) / 2;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("%d ", sum);
    return;
}

void compileMethod() {
    vector<int>axArr;
    printf("Enter the size of the array:");
    int size;
    scanf("%d", &size);
    
    int *arr = (int*)malloc(size * sizeof(int));
    
    printf("Enter the elements:");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        axArr.push_back(arr[i]);
    }
    missingNumber(axArr, 5);
    //subarraySum(arr, 40, size);
    free(arr);
}




#endif /* GFGQuestion_h */
