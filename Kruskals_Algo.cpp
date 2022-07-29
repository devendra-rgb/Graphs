#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


struct Node{
	int u;
	int v;
	int wt;
	Node (int first,int second,int weight)
	{
		u=first;
		v=second;
		wt=weight;
	}
};

//path compressing
int findparent(int node,vector<int> &parent)
{
	if(parent[node]==node) return node;
	
	return parent[node]=findparent(parent[node],parent);
}



void unionn (int u,int v,vector<int> &parent,vector<int> &ranking)
{
	u=findparent(u,parent);
	v=findparent(v,parent);
	if(ranking[u]>ranking[v])
	{
		parent[v]=u;
	}
	else if (ranking[v]>ranking[u])
	{
		parent[u]=v;
	}
	else
	{
		parent[v]=u;
		ranking[u]++;
	}
 } 



bool comp(Node a,Node b)
{
	return a.wt<b.wt;
}

int main()
{
	ifstream fin;
	fin.open("kruskal.txt");
	
	int N,m;
	N=5;
	m=12;
	
	vector<Node>edges;
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		fin>>u>>v>>wt;
		//cout<<u<<v<<wt<<endl;
		edges.push_back(Node(u,v,wt));
	}
	
	sort(edges.begin(),edges.end(),comp);
	
	vector<int>ranking(N,0);
	vector<int>parent(N,0);
	
	for(int i=1;i<=N;i++)
	{
		parent[i]=i;
	}
	
	int cost=0;
	//cout<<"Done";
	vector<pair<int,int>> mst;
	for(auto it:edges)
	{
		if(findparent(it.v,parent) != findparent(it.u,parent))
		{
			cost+=it.wt;
			mst.push_back({it.u,it.v});
			unionn(it.u,it.v,parent,ranking);
		}
	}
	cout<<"minimum cost : "<<cost<<endl;
	
	for(auto it:mst)
	{
		cout<<it.first<<" -- "<<it.second<<endl;
	}
	
	
	return 0;
	
}
