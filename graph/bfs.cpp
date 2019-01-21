#include<iostream>
#include<queue>
using namespace std;
const int INF = 100000000;
const int maxn = 10000;
typedef pair<int, int> P;	//储存坐标下x,y
int maze[maxn][maxn];
int d[maxn][maxn];			//储存每个坐标的最短路径
int sx, sy;					//起始坐标
int ex, ey;					//终点坐标
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int bfs()
{
	queue<P> que;			//bfs用队列
	for (int i = 0; i < maxn; i++) {		//初始化所有距离为极大
		for (int j = 0; j < maxn; j++) {
			d[i][j] = INF;
		}
	}
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	while (que.size()) {
		P p = que.front();
		que.pop();
		if (p.first == ex && p.second == ey)
			break;
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && d[nx][ny] == INF && maze[nx][ny] == ) {
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[ex][ey];
}
