#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;
#define ll long long 
int N;
int x[100005];
int y[100005];
const int maks = -1e9+7;
const int mins =  1e9+7;
int maxx,minx,miny,maxy;
int main()
{

	cin>>N;
	maxx = maks;
	minx = mins;
	maxy = maks;
	miny = mins;
	for(int i=0;i<N;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<N;i++)
	{
		if(maxx<x[i])
		{
			maxx = x[i];
		}	
		if(minx>x[i])
		{
			minx = x[i];
		}
		if(maxy<y[i])
		{
			maxy = y[i];
		}	
		if(miny>y[i])
		{
			miny = y[i];
		}
	}
	cout<<(maxx-minx+1)/2<<" "<<(maxy-miny+1)/2<<endl;
}