#include <bits/stdc++.h>
using namespace std;

#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
typedef long long ll;

const int mod = 1e9 + 7;
const ll MOD = 1e18;

int calculate(int idx, vector<int> coins, int amount, vector<vector<int>> &dp)
{
    if (idx >= coins.size())
    {
        if (amount == 0)
            return 0;
        return 1e9;
    }

    if (dp[idx][amount] != -1)
        return dp[idx][amount];

    int numTotal = amount / coins[idx];
    int take = 1e9;
    for (int i = 0; i <= numTotal; i++)
    {
        take = min(take, i + calculate(idx + 1, coins, amount - i * coins[idx], dp));
    }

    return dp[idx][amount] = take;
}

int coinChange(vector<int> &coins, int A)
{
    vector<vector<int>> dp(coins.size() + 1, vector<int>(A + 1, 0));

    for (int i = 1; i <= A; i++)
        dp[coins.size()][i] = 1e9;
    dp[coins.size()][0] = 0;

    for (int idx = coins.size() - 1; idx >= 0; idx--)
    {
        for (int amount = A; amount >= 0; amount--)
        {

            int numTotal = amount / coins[idx];
            int take = 1e9;
            for (int i = 0; i <= numTotal; i++)
            {
                take = min(take, i + dp[idx + 1][amount - i * coins[idx]]);
            }

            dp[idx][amount] = take;
        }
    }

    int ans = dp[0][A];
    if (ans == 1e9)
        return -1;
    return ans;
}

int main()
{
    faster;
    int t;
    cin>>t;

    while(t--){
        int n, A;
        cin >> n >> A;

        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << coinChange(arr, A);
    }
    
    return 0;
}