# Stones
Boolean marking for the i-height pile. If the height is 0, it is definitely false.
If there exists a false, that means Second wins. Otherwise, First would win.
N is the number of elements in the given array a, K is the height of the pile.
dp[0] = false;
Taro plays first, which means if he cannot play, we suppose the opponent would win the match.
dp[i] = true if Second wins in their dp[i-a[j]] because Taro would pick a[j] to play optimally.