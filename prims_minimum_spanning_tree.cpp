#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main()
{
	ifstream fin;
	fin.open("prims.txt");
	int V=5;
	int E=6;
	vector<pair<int,int>>adj[V];
	for(int i=0;i<E;i++)
	{
		int u,v,wt;
		fin>>u>>v>>wt;
		adj[v].push_back({u,wt});
		adj[u].push_back({v,wt});
	}
	
	
	int parent[V];
	int weights[V];
	bool mstset[V];
	
	for(int i=0;i<V;i++)
	{
		parent[i]=-1;
		weights[i]=INT_MAX;
		mstset[i]=false;
	}
	
	weights[0]=0;
	parent[0]=-1;
	
	
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
	
	pq.push({0,0});//{node,index}
	
	for(int count=0;count<V-1;count++)
	{
		/*int mini=INT_MAX,node;
		
		for(int j=0;j<V-1;j++)
		{
			if(mstset[j]==false && weights[j]<mini)
			{
				 node=j;
				mini=weights[j];
			}
		}
		
		*/
		int node=pq.top().second;
		pq.pop();
		
		mstset[node]=true;

		for (auto it:adj[node])
		{
			int next=it.first;
			int next_wt=it.second;
			
			if(mstset[next]==false &&  next_wt < weights[next])
			{
				weights[next]=next_wt;
				parent[next]=node;
				pq.push({weights[next],next});
			
				
			}
			
		}
	}
	
	
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<" -"<<weights[i]<<"- "<< i<<endl;
		
	}
	
	
	
	
}
