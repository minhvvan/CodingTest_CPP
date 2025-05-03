#include <stdio.h>

int main()
{
	int cmd, n;
	char v[21] = {0,};
	long long k, f[20];
	scanf("%d", &n);
	f[0] = 1;
	for(int i = 1; i < n; i++) f[i] = i*f[i-1];
	scanf("%d", &cmd);
	if(cmd == 1)
	{
		scanf("%lld", &k);
		k--;
		for(int s = n - 1; s>=0; s--)
		{
			int t = (int)(k / f[s])+1;
			int c = 1;
			while(t) if(v[c]) c++; else c++, t--;
			v[c-1] = 1;
			printf("%d ", c-1);
			k %= f[s];
		}
	}
	else
	{
		int t;
		k = 0;
		for(int s = n - 1; s >= 0; s--)
		{
			scanf("%d", &t);
			int c = 0;
			for(int i = 1; i < t; i++) if(!v[i]) c++;
			v[t] = 1;
			k += c * f[s];
		}
		printf("%lld\n", k+1);
	}
	return 0;
}