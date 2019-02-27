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

#include<iostream>
#include<cstring>
using namespace std;
//节点的信息
struct node
{
    int x;
    int y;
    int z;
    int num;
} link[30000];
//每个节点包括x,y,z坐标
//num表示开始访问当前节点的时间
int vis[31][31][31];//标记节点是否入队
char mapp[31][31][31];//搜索地图
int pp,qq,t,l,r,c;//当前指针和入队指针,最小时间
int step[6][3]= {{1,0,0},{-1,0,0},{0,0,1},{0,0,-1},{0,1,0},{0,-1,0}};
int flag;//标志有没有搜索到目标节点
bool judge(int x,int y,int z)
{
    if(mapp[x][y][z]=='#'||x<0||x>=l||y<0||y>=r||z<0||z>=c)
        return false;
    else
        return true;
}
void bfs()
{
    while(pp<qq)//队列非空
    {
        //访问节点时的操作
//对节点的访问就是对节点周围节点的搜索
        for(int i=0; i<6; i++)
        {
            int x=link[pp].x+step[i][0];
            int y=link[pp].y+step[i][1];
            int z=link[pp].z+step[i][2];
            if(judge(x,y,z)&&vis[x][y][z]==0)//尚未入队并符合条件
            {
                if(mapp[x][y][z]=='.')
                {
                    //节点入队
                    vis[x][y][z]=1;
                    link[qq].x=x;
                    link[qq].y=y;
                    link[qq].z=z;
                    link[qq].num=link[pp].num+1;//开始访问邻接点的时间相差为1
                    qq++;
                }
                else if(mapp[x][y][z]=='E')//目标节点寻找成功
                {
                    flag=1;
                    t=link[pp].num+1;
                    break;
                }
            }
        }
        if(flag)
            break;
        pp++;//pp出队，遍历队列中的下一个节点
    }
}
int main()
{
    while(cin>>l>>r>>c)
    {
        if(l==0&&r==0&&c==0)
            break;
        memset(vis,0,sizeof(vis));
        pp=qq=t=0;
        link[qq].num=0;
        for(int i=0; i<l; i++)
            for(int j=0; j<r; j++)
                for(int k=0; k<c; k++)
                {
                    cin>>mapp[i][j][k];
                    if(mapp[i][j][k]=='S')//第一个节点入队
                    {
                        vis[i][j][k]=1;
                        link[qq].x=i;
                        link[qq].y=j;
                        link[qq].z=k;
                        qq++;//对头指针+1，节点入队
                    }
                }
        flag=0;
        bfs();
        if(flag)
            cout<<"Escaped in "<<t<<" minute(s)."<<endl;
        else
            cout<<"Trapped!"<<endl;
    }
    return 0;
}


#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=(int)1e6+1000;
int vis[maxn];
int d[2]={1,-1};
int ex, ey;
int t;

struct node{
    int x;
    int num;
};

void bfs(){
    queue<node> q;
    node now, next;
    node nod={ex, 0};
    q.push(nod);
    vis[ex]=1;
    while(!q.empty()){
        now=q.front();
        if(now.x == ey){
            t=now.num;
            return;
        }
        for(int i=0;i<3;i++){
            if(i==2){
                next.x=now.x*2;
                next.num = now.num + 1;
                if(vis[next.x] == 0 && next.x>=0 && next.x<=100000){
                    q.push(next);
                    vis[next.x] = 1;
                }
            }else{
                next.x = now.x + d[i];
                next.num = now.num + 1;
                if(vis[next.x] == 0 && next.x>=0 && next.x<=100000){
                    q.push(next);
                    vis[next.x] = 1;
                }
            }
        }
        q.pop();
    }
}

int main(void){
    while(cin >> ex >> ey){
        memset(vis,0, sizeof(vis));
        bfs();
        cout << t << endl;
    }
}
