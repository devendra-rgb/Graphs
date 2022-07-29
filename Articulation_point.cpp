#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void find_articulation(int node,int parent,int &timer,vector<int>&tin,vector<int>&low,vector<int>&vis,vector<int>adj[],vector<int>&st)
{
	vis[node]=1;
	tin[node]=low[node]=timer++;
	int child=0;
	for(auto it:adj[node])
	{
		if(it==parent) continue;
		
		if(!vis[it])
		{
			find_articulation(it,node,timer,tin,low,vis,adj,st);
			low[node]=min(low[node],low[it]);
			child++; //it will help to know how many childs are there for the node
			if(low[it] >= tin[node] && parent!=-1 ) st[node]=1;
			
		}
		
		else
		{
			low[node]=min(low[node],tin[it]);

		}
			
		
			if(parent==-1 &&  child>1) st[node]=1;
		
	}
}



int main()
{
	ifstream fin;
	fin.open("ArticulationPoints.txt");
	int N,E;
	fin>>N>>E;
	N++;
	N++;
	vector<int>adj[N];

	for(int i=0;i<E;i++)
	{
		int u,v;
		fin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cout<<u<<" "<<v<<endl;
	}
	//cout<<"D";
	vector<int>vis(N,0);
	vector<int>tin(N,-1);
	vector<int>low(N,-1);
	vector<int>st(N,0);
	int timer=0;
	
	for(int i=1;i<=N;i++)
	{
		//cout<<i<<" ";
		if(!vis[i])
		{
			find_articulation(i,-1,timer,tin,low,vis,adj,st);	
		}		
	}
	
	for(int i=0;i<N;i++)
	{
		if(st[i]==1)
		cout<<i<<" ";
	}
	return 0;
}
