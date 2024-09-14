#include <bits/stdc++.h>
using namespace std;

#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
typedef long long ll;

const int mod = 1e9 + 7;
const ll MOD = 1e18;

int lcs(int n, int m, string s1, string s2)
{

    vector<int> temp(m + 1, 0);
    vector<vector<int>> dp(n + 1, temp);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string str1, str2;
        cin >> str1 >> str2;

        cout << lcs(n, m, str1, str2) << "\n";
    }
    return 0;
}