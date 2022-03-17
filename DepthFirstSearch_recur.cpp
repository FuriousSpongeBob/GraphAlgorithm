#include<iostream>
#include<vector>
using namespace std;
#define ParentNodesNum 6
#define NodesNum 10
vector<int> visited(NodesNum,0);
vector<vector<int> > graph;
/*
3 2 3 4
1 5
2 6 7
1 8
1 9
1 10
*/
void DFS(int beg){
	vector<int>::iterator it;
	visited[beg]=1;
	cout<<beg<<" - ";
	for(it=graph[beg].begin();it<graph[beg].end();it++)
		if(!visited[*it])
			DFS(*it);
}

 int main(int argc, char const *argv[])
{
	graph.push_back(vector<int>(1,0));//第0行填充
	for(int i=1;i<=ParentNodesNum;i++){
		int edgeNum,temp;
		cin>>edgeNum;
		graph.push_back(vector<int>(edgeNum,0));
		for(int j=0;j<edgeNum;j++){
			cin>>temp;
			graph[i][j]=temp;
		}
	}
	DFS(1);
	return 0;
}