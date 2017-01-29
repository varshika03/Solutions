#include<iostream>
#include<vector>
#define m 1000000000
#define ull unsigned long long
using namespace std;
int k;
vector<vector<ull> > multiply(vector<vector<ull> > a,vector<vector<ull> > b)
{
int n=k;
	vector<vector<ull> > c(n+1,vector<ull>(n+1));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			c[i][j]=0;
			for(int k=1;k<=n;++k)
			{
				c[i][j]=(c[i][j]+((a[i][k]*b[k][j])%m))%m;
			}
		}
	}
	return c;
	
	
}
vector<vector<ull> > func(vector<vector<ull> > t,long pow)
{
//	cout<<pow<<"\n";
	if(pow==1)
	return t;
	if(pow%2==0)
	{
		vector<vector<ull> > temp=func(t,pow/2);
		return multiply(temp,temp);
	}
	else
	{
		vector<vector<ull> > temp=func(t,pow/2);
		temp=multiply(temp,temp);
	return multiply(temp,t);	
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>k;
		vector<long> b(k),c(k);
		for(int i=0;i<k;++i)
		cin>>b[i];
		for(int i=0;i<k;++i)
		cin>>c[i];
		long n;
		cin>>n;
		if(n<=k)
		cout<<b[n-1]<<"\n";
		else
		{
			vector<vector<ull> > t(k+1,vector<ull>(k+1));//transformation matrix
			for(int i=1;i<k;++i)
			{
				for(int j=1;j<=k;++j)
				{
					if(j==i+1)
					t[i][j]=1;
					else
					t[i][j]=0;
					
				}
			}
			for(int j=1;j<=k;++j)
			{
				t[k][j]=c[k-j];
			}
		/*	t=multiply(t,t);
			cout<<"after\n";
			for(int i=1;i<=k;++i)
			{
				cout<<"\n";
				for(int j=1;j<=k;++j)
				cout<<t[i][j]<<" ";
			}
			*/
			long x=n-k;
		t=func(t,x);
		
			long long a=0;
			for(int j=1;j<=k;++j)
			{
				long term=((t[k][j]%m)*b[j-1])%m;
				a=(a+term)%m;	
			}
          cout<<a<<"\n";
			
		}
	}
}
