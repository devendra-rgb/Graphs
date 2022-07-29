#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct node
{
	int u;
	int v;
	int wt;
	node(int s,int e,int weight)
	{
		u=s;
		v=e;
		wt=weight;
	}
};
int main()
{
	ifstream fin;
	fin.open("BellManFord.txt");
	int N,E;
	fin>>N>>E;
	vector<node>adj;
	for(int i=0;i<E;i++)
	{
		int u,v,wt;
		fin>>u>>v>>wt;
		adj.push_back(node(u,v,wt));
	}
	
	vector<int>dist(N,INT_MAX);
	dist[0]=0;
	
	for(int j=1;j<=N-1;j++)
	{
		for(auto it:adj)
		{
			if(dist[it.u]+it.wt < dist[it.v])
			{
			
				dist[it.v]=dist[it.u]+it.wt;
				
			}	
		}
	
	}
	int fl=0;
	for(auto it:adj)
	{
		if(dist[it.u]+it.wt < dist[it.v])
		{
			cout<<"Negative Cycle";
			fl=1;
			break;
		}	
	}
	
	if(!fl)
	{
		for(auto it:dist)
		{
			cout<<it<<" ";
		}
	}
	
	
	 
}
