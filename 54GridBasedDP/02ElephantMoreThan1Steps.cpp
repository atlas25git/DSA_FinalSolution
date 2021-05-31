 simply use a 2d matrix with first row and cil i=0,j=0
 put these row with the cumulative sum of these row's prev
 row and col, now for other cells
    dp[x][y] = sum[k=0,X-1](dp[k][y]) + sum[k=0,Y-1](dp[x][k])