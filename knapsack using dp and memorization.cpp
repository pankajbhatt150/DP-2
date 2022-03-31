Code: Knapsack (Memoization and DP)
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
  // solution
  int knapsack(int *weights, int *values, int n, int maxWeight, int **output)
{
	//write your code here
    	if(n == 0 || maxWeight == 0) {
		return 0;
	}

    if(output[n][maxWeight]!=-1)
    {
        return output[n][maxWeight];
    }
  
   

        if(weights[n-1] > maxWeight)
        {
            output[n][maxWeight] = knapsack(weights,values,n-1,maxWeight,output);
        }
    
        else
        {
            output[n][maxWeight] = max(knapsack(weights,values,n-1,maxWeight,output), values[n-1] + knapsack(weights,values,n-1,maxWeight-weights[n-1],output));
        }
    
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int ** output = new int*[n+1];
    for(int i=0; i<=n; i++)
    {
        output[i] = new int[maxWeight+1];
        for(int j =0; j<=maxWeight; j++ )
        output[i][j]= -1;
    }
    return knapsack(weights, values, n, maxWeight, output);
}
