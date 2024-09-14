#include <bits/stdc++.h>
using namespace std;

#define faster                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
typedef long long ll;

const int mod = 1e9 + 7;
const ll MOD = 1e18;

void shortest_distance(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == -1)
				matrix[i][j] = 1e9;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
				{
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1e9)
				matrix[i][j] = -1;
		}
	}
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
		vector<vector<int>> matrix(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
			}
		}

		shortest_distance(matrix);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}
