#include <bits/stdc++.h>
using namespace std;

#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
typedef long long ll;

const int mod = 1e9 + 7;
const ll MOD = 1e18;

int longestSubsequence(int n, int a[])
{
    vector<int> temp;
    temp.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] > temp.back())
        {
            temp.push_back(a[i]);
        }
        else
        {
            int idx = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[idx] = a[i];
        }
    }

    return temp.size();
}

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << longestSubsequence(n, a) << endl;
    }
    return 0;
}
