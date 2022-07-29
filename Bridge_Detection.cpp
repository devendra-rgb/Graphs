#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void dfs_bridge(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,vector<int>adj[],int &timer)
{
	vis[node]=1;
	low[node]=tin[node]=timer++;
	
	for(auto it:adj[node])
	{
		if(it==parent) continue;
		
		if(!vis[it])
		{
			dfs_bridge(it,node,vis,tin,low,adj,timer);
			low[node]=min(low[node],low[it]);
			
			if(low[it]>tin[node]) 
				cout<<node<<" "<<it<<endl;
			
		}
		else 
		low[node]=min(low[node],tin[it]);
		
	}
	
	
}


int main()
{
	int N=13;
	int E=12;
	vector<int>adj[N];
	ifstream fin;
	fin.open("Bridges.txt");
	for(int i=0;i<E;i++)
	{
		int u,v;
		fin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>vis(N,0);
	vector<int>tin(N,-1);
	vector<int>low(N,-1);
	int timer=0;
	
	for(int i=1;i<N;i++)
	{
		if(!vis[i])
		dfs_bridge(i,-1,vis,tin,low,adj,timer);
	}
	
}
