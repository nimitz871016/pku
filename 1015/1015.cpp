// 1015.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct Node{
	int j;
	int f;
};
bool cmp(const Node a, const Node b) {
	return a.j > b.j;
}
int main()
{
	int n, m;
	Node *a;
	while (scanf("%d %d",&m,&n)!=EOF) {
		if (n == -1 && m == -1) {
			break;
		}
		a = (Node *)malloc(sizeof(Node)*n);
		for (int i = 0; i < n; i++) {
			Node node;
			scanf("%d %d",&a[i].j,&a[i].f);
		}
		sort(a, a + n, cmp);
		double sum = 0.0;
		for (int i = 0; i < n; i++) {
			if (m >= a[i].f) {
				m -= a[i].f;
				sum += a[i].j;
			}
			else {
				sum += 1.0 * m / a[i].f * a[i].j;
			}
			if (m == 0) {
				break;
			}
		}
		printf("%.3f\n",sum);
		free(a);
	}

    return 0;
}

