#pragma once

// Source : https://leetcode.com/problems/coin-change/
// Author : Calinescu Valentin, Hao Chen
// Date   : 2015-12-28

/***************************************************************************************
*
* You are given coins of different denominations and a total amount of money amount.
* Write a function to compute the fewest number of coins that you need to make up that
* amount. If that amount of money cannot be made up by any combination of the coins,
* return -1.
*
* Example 1:
* coins = [1, 2, 5], amount = 11
* return 3 (11 = 5 + 5 + 1)
*
* Example 2:
* coins = [2], amount = 3
* return -1.
*
* Note:
* You may assume that you have an infinite number of each kind of coin.
*
* Credits:
* Special thanks to @jianchao.li.fighter for adding this problem and creating all test
* cases.
*
***************************************************************************************/


/* Recursive solution - TIME LIMIT ERROR */
class CoinChangeSolution1 {
public:
	int coinChange(vector<int>& coins, int amount) {
		int result = INT_MAX;
		if (amount == 0) return 0;
		if (amount < 0) return -1;
		for (size_t i = 0; i<coins.size(); i++) {
			if (amount - coins[i] < 0) continue;
			int r = coinChange(coins, amount - coins[i]);
			if (r == -1) continue;
			if (result > r)  result = r + 1;
		}
		return result == INT_MAX ? -1 : result;
	}
};


//Another DP implmentation, same idea above 
class CoinChangeSolution2 {
public:
	int coinChange(vector<int>& coins, int amount) {
		const int MAX = amount + 1;
		vector<int> dp(amount + 1, MAX);
		dp[0] = 0;

		for (int i = 1; i <= amount; i++) {
			for (size_t j = 0; j<coins.size(); j++) {
				if (i >= coins[j]) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}

		return dp[amount] == MAX ? -1 : dp[amount];
	}
};
