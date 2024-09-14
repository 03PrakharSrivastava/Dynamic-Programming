#include <bits/stdc++.h>
using namespace std;

#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
typedef long long ll;

const int mod = 1e9 + 7;
const ll MOD = 1e18;

int calculate(int idx, vector<int> arr, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (idx >= arr.size())
        return 0;

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int notTake = calculate(idx + 1, arr, target, dp);
    int take = 0;
    if (target >= arr[idx])
    {
        take = calculate(idx + 1, arr, target - arr[idx], dp);
    }

    return dp[idx][target] = take | notTake;
}

bool isSubsetSum(vector<int> arr, int sum)
{

    vector<int> temp(sum + 1, -1);
    vector<vector<int>> dp(arr.size() + 1, temp);

    return calculate(0, arr, sum, dp);
}

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        cout << isSubsetSum(arr, sum) << "\n";
    }
    return 0;
}
