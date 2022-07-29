#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void shortestPath(vector<int>adj[],int N,int src)
{
	//vector<int>distance(N,INT_MAX);
	int distance[N];
	for(int i=0;i<N;i++) distance[i]=INT_MAX;
	queue<int>q;
	q.push(src);
	distance[src]=0;
	
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto it:adj[top])
		{
			if(distance[top]+1 < distance[it])
			{
				distance[it]=distance[top]+1;
				q.push(it);
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		cout<<distance[i]<<" ";
	}
}







int main()
{
	int N=9;
	int E=11;
	
	vector<int>adj[9];
	
	ifstream fin;
	fin.open("simple_cyclic_graph.txt");
	for(int i=0;i<E;i++)
	{
		int u,v;
		fin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	shortestPath(adj,N,0);
	
	
	
}
