#include<iostream>
#include<queue>
using namespace std;

#define MAX 20

int visited[MAX];
int map[MAX][MAX];

void BFS(int beg,int n){
	queue<int> q;
	int front;
	visited[beg]=1;
	//先将和起点相连的点入队
	for(int i=1;i<=n;i++){
		if(map[beg][i]==1&&visited[i]==0){
			q.push(i);
			cout<<"edge: 1 - "<<i<<endl;
			visited[i]=1;
		}
	}
	//出队一个，把其所有相连点入栈，直到队空
	while(!q.empty()){
		front=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(map[front][i]==1&&visited[i]==0){
				cout<<"edge: "<<front<<" - "<<i<<endl;
				q.push(i);
				visited[i]=1;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<pair<int,int>> v{make_pair(1,2),make_pair(2,5),make_pair(5,9),make_pair(1,3),make_pair(3,6),make_pair(6,10),make_pair(3,7),make_pair(1,4),make_pair(4,8)};
	for(int i=0;i<9;i++){
		map[v[i].first][v[i].second]=map[v[i].second][v[i].first]=1;
	}
	BFS(1,10);
	return 0;
}