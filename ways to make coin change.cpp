Ways To Make Coin Change
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
  // solution
  int countWays(int deno[], int n, int value){
	int dp[n+1][value+1] = {};
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=value; j++) {
         	if(i==0 && j == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else {
                dp[i][j] = dp[i-1][j];
                if(deno[i-1] <= j)
                    dp[i][j] += dp[i][j-deno[i-1]];
            }
        }
    }
    return dp[n][value];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
 	
    return countWays(denominations,numDenominations,value);
}
