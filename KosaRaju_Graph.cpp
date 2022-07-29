#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void topo_sort(int node,vector<int>&vis,vector<int>adj[],stack<int>&st)
{
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			topo_sort(it,vis,adj,st);
		}
	}
	st.push(node);
	
}


void kosaraju(int node,vector<int>&vis,vector<int>transpose[])
{
	vis[node]=1;
	cout<<node<<" ";
	for(auto it:transpose[node])
	{
		if(!vis[it])
		{
			kosaraju(it,vis,transpose);
		}
	}
}



int main()
{
	ifstream fin;
	fin.open("KosaRaju.txt");
	int N,E;
	fin>>N>>E;
	vector<int>adj[N+1];
	for(int i=0;i<E;i++)
	{
		int u,v;
		fin>>u>>v;
		cout<<u<<v<<" "<<endl;
		adj[u].push_back(v);
	}
	stack<int>st;
	
	vector<int>vis(N+1,0);
	
	for(int i=1;i<=N;i++)
	{
		if(!vis[i])
		{
			topo_sort(i,vis,adj,st);
		}
	}
	
	vector<int>transpose[N+1];
	for(int i=1;i<=N;i++)
	{
		vis[i]=0;
		for(auto it:adj[i])
		{
			transpose[it].push_back(i);
		}
		
	}
	
	while(!st.empty())
	{
		int node=st.top();
		st.pop();
		if(!vis[node])
		{
			cout<<"SCC: ";
			kosaraju(node,vis,transpose);
			cout<<endl;
		}
	}	
}
