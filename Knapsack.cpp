#include <bits/stdc++.h>
using namespace std;

#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
typedef long long ll;

const int mod = 1e9 + 7;
const ll MOD = 1e18;

int calculate(int idx, int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{

    if (idx == n - 1)
    {
        if (wt[idx] <= W)
            return val[idx];
        return 0;
    }

    if (dp[idx][W] != -1)
        return dp[idx][W];
    int notTake = calculate(idx + 1, W, wt, val, n, dp);
    int take = 0;
    if (W >= wt[idx])
    {
        take = val[idx] + calculate(idx + 1, W - wt[idx], wt, val, n, dp);
    }

    return dp[idx][W] = max(take, notTake);
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> temp(W + 1, -1);
    vector<vector<int>> dp(n + 1, temp);
    return calculate(0, W, wt, val, n, dp);
}

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        vector<int> wt(n, 0);
        vector<int> val(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }

        cout << knapSack(w, wt, val, n) << "\n";
    }
    return 0;
}
