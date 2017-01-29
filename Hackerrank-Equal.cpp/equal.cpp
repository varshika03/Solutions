#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
	int t;
	long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> list(n);
		int mini=INT_MAX;
		int maxi=0;
		for(long i=0;i<n;++i)
		{
			cin>>list[i];
			if(list[i]>maxi)
			maxi=list[i];
			if(list[i]<mini)
			mini=list[i];
		}
		vector<vector<int> >dp(mini+1,vector<int>(maxi+1));
		for(int i=0;i<=mini;++i)
		{
			for(int j=0;j<=maxi;++j)
			{
				if(j<i)
				dp[i][j]=-1;
				else if(j==i)
				dp[i][j]=0;
				else
				{
					int y;
				   if(j>=1&&dp[i][j-1]!=-1)	
				   y=dp[i][j-1];
				   if(j>=2&&dp[i][j-2]!=-1)
				   y=min(y,dp[i][j-2]);
				   if(j>=5&&dp[i][j-5]!=-1)
				   y=min(y,dp[i][j-5]);
				   dp[i][j]=y+1;
					
				}	
			}
		}

	long steps=LONG_MAX;
		for(int i=0;i<=mini;++i)
		{
			long o=0;
			for(long j=0;j<n;++j)
			{
				o+=(dp[i][list[j]]);	
			}
			steps=min(steps,o);
		}
		
		
		cout<<steps<<"\n";
	}
}
