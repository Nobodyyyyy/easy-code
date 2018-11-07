#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;
//素数筛选
bool visit[100000];
int main()
{
	int N;
	cin >> N;
	memset(visit, 0, sizeof(visit));
	for(int i = 2; i <= N; i++)
	{
		if(visit[i] == 0)
		{
			for(int j = i+i; j <= N; j+=i) visit[j] = 1;
				cout << i << endl;
		}
		else continue;  
	}
	return 0;
}