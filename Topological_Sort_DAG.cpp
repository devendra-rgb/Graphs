#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;





void BFS(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans,queue<int>&q)
{
	vis[node]=1;
	q.push(node);
	
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		ans.push_back(f);
		for(auto it:adj[f])
		{
			if(!vis[it]) 
			{
				vis[it]=1;
				q.push(it);
			}
		}
	}
	
}




void DFS(int node, vector<int>adj[],vector<int>&vis,vector<int>&ans)
{
	vis[node]=1;
	ans.push_back(node);
	for(auto it:adj[node])
	{
		if(!vis[it]) 
		DFS(it,adj,vis,ans);
	}
}

void topological_sort_BFS(int V, vector<int>adj[],queue<int>q,vector<int>&ans)
{
	vector<int>indegree(V+1,0);
	for(int i=1;i<=V;i++)
	{
		for(auto ij:adj[i])
		{
			indegree[ij]++;
		}
	}
	
	for(int i=1;i<=V;i++)
	{
		if(indegree[i]==0) q.push(i);
	}
	
	while(!q.empty())
	{
		int f=q.front();
		ans.push_back(f);
		q.pop();
		for(auto it:adj[f])
		{
			indegree[it]--;
			if(indegree[it]==0) q.push(it);
			
		}
	}
	
	
	
}

void topological_sort_dfs(int node,vector<int>adj[],stack<int> &st,vector<int>&vis)
{
	
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
		topological_sort_dfs(it,adj,st,vis);
	}
	st.push(node);
	
}

//Bipartite Graph DFS
bool Bipartite_DFS(vector<int>&color,int node,vector<int>adj[])
{
	if(color[node]==-1) color[node]=1;
	for(auto it:adj[node])
	{
		if(color[it]==-1) 
		{
			
		color[it]=1-color[node];
		if(!Bipartite_DFS(color,node,adj)) return false;
		
		}
		else if(color[it]==color[node]) return false;
	}
	return true;
}


bool Bipartite_BFS(vector<int>&color,int node,vector<int>adj[],queue<int>&q)
{
	if(color[node]==-1) color[node]=1;
	
	q.push(node);
	
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto it:adj[top])
		{
			if(color[it]==-1) 
			{
				color[it]=1-color[top];
				q.push(it);
			}
			else if (color[it]==color[top]) return false;
		}
		
	}
	return true;
	
	
}


bool cycleDetectionDFS(vector<int>adj[],int parent,int node,vector<int>&vis)
{
	
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(vis[it]==0) 
		{
			if(!cycleDetectionDFS(adj,node,it,vis)) return true;
		}
		else if (it!=parent) return true;
	}
	return false;
	
}
bool cycleDetectionBFS(vector<int>adj[],int node, vector<int>&vis)
{
	queue<pair<int,int>>q;
	vis[node]=1;
	q.push({1,-1});
	
	while(!q.empty())
	{
		int nod=q.front().first;
		int parent=q.front().second;
		q.pop();
		for(auto it:adj[nod])
		{
			if(!vis[it])
			{
				q.push({it,nod});
			}
			else if(it!=parent) return true;
		}
	}
	return false;
	
}

int main()
{
	
	int E,V;
	 E=9;
	 V=9;
	
	vector<int>adj[V+1];
	
	adj[1].push_back(2);
	adj[2].push_back(1);

	adj[2].push_back(3);
	adj[3].push_back(2);

	adj[3].push_back(6);
	adj[6].push_back(3);

	adj[6].push_back(8);
	adj[8].push_back(6);

	adj[8].push_back(9);
	adj[9].push_back(8);

	adj[1].push_back(4);
	adj[4].push_back(1);

	adj[4].push_back(5);
	adj[5].push_back(4);

	adj[5].push_back(7);
	adj[7].push_back(4);

	adj[7].push_back(8);
	adj[8].push_back(7);

	
	
	vector<int>vis(V+1,0);
	vector<int>ans;
	stack<int>st;
	queue<int>q;
	vector<int>color(V,-1);

	color[1]=0;
	for(int i=1;i<V;i++)
	{
		if(!vis[i])
		{
			
			if(!cycleDetectionBFS(adj,i,vis)) 
			{
				cout<<"Not Possible";
				return 0;
			}
			
		}	
		
		cout<<" Possible";
		return 0;
	}
	
			
			
	/*
	
	for(auto it:ans)
	{
		cout<<it<<' ';
	}
	

while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
*/

}
