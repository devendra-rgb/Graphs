#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main()
{
	ifstream fin;
	fin.open("dijkstra.txt");
	int u,v,wt;
	int V=6;
	int E=6;
	vector<pair<int,int>>adj[V];
	for(int i=0;i<E;i++)
	{
		fin>>u>>v>>wt;
		
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}	
	int source=1;
	
	priority_queue< pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> > que;
	vector<int>distTo(V+1,INT_MAX);
	distTo[source]=0;
	que.push(make_pair(0,source));
	
	while(!que.empty())
	{
		int dist=que.top().first;
		int prev= que.top().second;
		que.pop();
		for(auto it:adj[prev])
		{
			int next=it.first;
			int nextdist=it.second;

			
			if(dist+nextdist < distTo[next])
			{
				distTo[next]=dist+nextdist;
				que.push({distTo[next],next});
			}
		}
		
		
		
	}	
	cout<<endl;
	for(int i=1;i<6;i++) cout<<distTo[i]<<" ";
	
}
