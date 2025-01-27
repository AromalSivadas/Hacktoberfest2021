#include <stdio.h>
int main()
{

	int n, m, i, j, k,alloc[10][10],max[10][10],avail[10];
    printf("Enter the number of processes");
    scanf("%d",&n);
    printf("Enter the number of resources");
    scanf("%d",&m);
	printf("Enter the allocation matrix");
	for(i=0;i<n;i++)
	    for(j=0;j<m;j++)
	        scanf("%d",&alloc[i][j]);
	printf("Enter the maximum requirement");
	for(i=0;i<n;i++)
	    for(j=0;j<m;j++)
	        scanf("%d",&max[i][j]);
	printf("Enter the available resources");
	for(j=0;j<m;j++)
	    scanf("%d",&avail[i]);

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] <= avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 1) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);

	return (0);


}
