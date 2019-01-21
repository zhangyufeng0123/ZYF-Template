//二分图匹配（匈牙利算法的DFS实现）(邻接矩阵形式)
//初始化：g[][]两侧顶点的可连接情况
//建立g[i][j]表示i->j的有向边就可以了，是左边向右边的匹配
//g没有边相连则初始化为0
//uN是左边的顶点数，vN是右边的顶点数
//lnk[]表示的是右侧点的归属，use是对某次查找时是否修改的标记
//调用：ans=hungary();输出最大匹配数
//优点：适用于稠密图，DFS找增广路，实现简洁易于理解
//时间复杂度:O(VE)
 
//该模板中 顶点的编号是从1开始的
 
int uN,vN; //u,v的数目，使用前面必须赋值 
int g[maxn][maxn]; 
int lnk[maxn],use[maxn];
 
int dfs(int u)
{
    for(int v=1;v<=vN;v++)
        if(g[u][v]&&!use[v]) //若 use=1 表示这次的查找 曾试图改变过该i的归属问题，但是没有成功，所以就不用费工夫了
        {
            use[v]=1;
            if(lnk[v]==-1||dfs(lnk[v]))
            {
                lnk[v]=u;
                return true;
            }
        }
    return false;
}
 
int hungary()
{
    int res=0;
    mst(lnk,-1);
    for(int u=1;u<=uN;u++)
    {
        mst(use,0);
        if(dfs(u)) res++;
    }
    return res;
}
