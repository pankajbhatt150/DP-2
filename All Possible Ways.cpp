All possible ways
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Input Format:
The first line of input contains two space separated integers, that denote the value of a and b.
Output Format:
The first and only line of output contains count of ways in which a can be represented as sum of unique integers raised to power b.
Constraints :
1 <= a <= 10^4
1 < b <= 20
Time Limit: 1 second
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways: 
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2
//SOLUTION
#include<vector>
#include<cmath>
int vectorSum(int *arr, int size, int sum) {
    /* How many ways can elements of array arr add to sum. */
    if(size<=0) return 0;
    if(size==1) {
        if(arr[0]==sum) return 1;
        return 0;
    }
    int ans=0;
    // Can the last element of array be included
    if(arr[size-1]==sum) return 1+vectorSum(arr, size-1, sum);
    if(arr[size-1]<sum) return vectorSum(arr, size-1, sum-arr[size-1])+
        vectorSum(arr, size-1, sum);
    return vectorSum(arr, size-1, sum);
}

int getAllWays(int x, int n) {
    /* Given two integers a and b. You need to find and return the count of
     * possible ways in which we can represent the number a as the sum of unique
     * integers raise to the power b. For eg. if a = 10 and b = 2, only way to
     * represent 10 as: 10 = 1^2 + 3^2.
     * Hence, answer is 1. */
    vector<int> p;
    // p[i] represents i^n
    p.push_back(1);
    for (int i=2, j=pow(i,n);j<=x;j=pow(++i,n))
        p.push_back(j);
    return vectorSum(&p[0], p.size(), x);
}
