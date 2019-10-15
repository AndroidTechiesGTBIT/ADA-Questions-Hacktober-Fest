#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define blue ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007;

/*

Probelm Statement:
    Given: A value N and some coins of marked denominations
    Task: Count the number of ways to make change for the value N using these coins.
    Conditions: You have infinite supply of coins of given denominations


Solution:
    Initially you have to make a value N using coins (c1, c2, .., cx)
    where x = number of diffrent coins

    Approach:
        Either you select a specific coin or reject it,
        if you select (N = N-coin(i) ) you can select again or may reject the second time (Remember infinite supply of coins)

        if you reject a coin you move to next coin, this goes on untill your value to make i.e. N = 0
                                    OR
        You stop if you have tried all the coins
*/

int dp[1000][1000];

int coin_change_dp(int coins[], int X, int N) {
    
    for(int i=0;i<X;i++) dp[0][i]=1; //Initializing the preconditions

    int include=0, exclude=0;

    for(int i=1;i<=N;i++) { // Iterate for all values of N

        for(int j=0;j<X;j++) { // Iterate for all the coins 
            
            include=0,exclude=0;
            if(i - coins[j] >= 0 ) include = dp[i-coins[j]][j]; // Count if we include coin number j (i.e. coins[j])

            if(j >= 1) exclude = dp[i][j-1]; // Count if we exclude coin number j (i.e. coins[j])

            dp[i][j] = include + exclude; // Total count is include + exclude
        }
    }
    return dp[N][X-1];
}

int main() {
    int N = 15; // Value to make change with coins

    int X = 3; // Number of diffrent coins

    int coins[] = {1, 2, 3}; // Values of coins

    int total_number_of_ways_to_make_coin_change;

    memset(dp,-1,sizeof(dp)); // Initializing the DP array with -1's

    total_number_of_ways_to_make_coin_change = coin_change_dp(coins,X, N);

    cout<<"The total number of ways to exchange "<<N<<" are: "<<total_number_of_ways_to_make_coin_change<<endl;
}

