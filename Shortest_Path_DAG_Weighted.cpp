#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;



void topological_sort(vector<pair<int,int>> adj[],stack<int>&st,vector<int>&vis,int node)
{
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it.first])
		{
			
			topological_sort(adj,st,vis,it.first);
		}
	}
	st.push(node);
	cout<<node<<" ";
}



void shortest_path(vector<pair<int,int>> adj[],int N,int src)
{
	stack<int>st;
	vector<int>vis(N,0);
	for(int i=0;i<N;i++)
	{
		if(!vis[i]) topological_sort(adj,st,vis,i);
	}
	
	int dist[N];
	for(int i=0;i<N;i++)
	{
		dist[N]=INT_MAX;
	}
	dist[src]=0;
	
	while(!st.empty())
	{
	    int top=st.top();
		st.pop();
		if(dist[top]!=INT_MAX)
		{
		
			for(auto it:adj[top])
			{
				
					if(dist[top]+it.second < dist[it.first])
					{
						dist[it.first]=dist[top]+it.second;
						
					}
				
			}
		}
	}
	
	
	for(int i=0;i<N;i++)
	{
		if(dist[i]==INT_MAX) cout<<" INF";
		else cout<<dist[i]<<" ";
	}
	
	
	
	
}





int main()
{
	int N=6;
	int E=7;
	vector<pair<int,int>>adj[N];
	ifstream fin;
	fin.open("DAG.txt");
	for(int i=0;i<E;i++)
	{
		int u,v,w;
		fin>>u>>v>>w;
		adj[u].push_back({v,w});
		
	}
	shortest_path(adj,N,0);
	
}
