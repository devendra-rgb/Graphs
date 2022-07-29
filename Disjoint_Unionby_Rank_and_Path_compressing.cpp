#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int parent[10000];
int ranking[10000];


int makeset()
{
	for(int i=0;i<7;i++)
	{
		parent[i]=i;
		ranking[i]=0;
	}
}


int find_parent(int node)
{
	if(parent[node]=node)
	{
		return node;
	}
	
	return parent[node]=find_parent(node);
}


void union(int u,int v)
{
	u=find_parent(u);
	v=find_parent(v);
	
	if(ranking[u]<ranking[v])
	{
		parent[u]=v;
	}
	else if(ranking[v]<ranking[u])
	{
		parent[v]=u;
	}
	else
	{
		prent[v]=u;
		ranking[u]+=1;
	}
}


int main()
{
	makeset();
	int m;
	cin>>m;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		union(u,v);
	}
	
	
}
