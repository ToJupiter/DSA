# Coins
dp[i][j] means the first i coins, and j in i are heads.
dp[0][0] = 1
More heads than tails, means in the last row we start from n/2 + 1.
dp[i][j] = dp[i-1][j-1] * head[i] + dp[i-1][j] * tail[i]
if (i == j) dp[i][j] = dp[i-1][j-1] * head[i]