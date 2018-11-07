#include <iostream>
#include <memory.h>
using namespace std;

int sum[500000];
bool visit[500000];

int main()
{
	memset(sum, 0, sizeof(sum));
	memset(visit, 0, sizeof(visit));
	int N;
	cin >> N;
	for(int i = 2; i <= N; i++)
	{
		if(visit[i] == 0)
		{
			sum[i] = sum[i-1] + i;
			for(int j = i+i; j <= N; j+=i) visit[j] = 1;
		}
		else sum[i] = sum[i-1];
	}
	cout << sum[N];
}