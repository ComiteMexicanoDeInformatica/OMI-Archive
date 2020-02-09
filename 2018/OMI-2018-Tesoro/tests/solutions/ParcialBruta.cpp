#include "tesoro.h"

const int maxn = 1001;
int grid[maxn][maxn];

void BuscaTesoros(int n, int m, int k){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			grid[i][j] = Preguntar(i,j);

	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			grid[i][j] -= grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (grid[i][j])
				Cavar(i, j);
}
