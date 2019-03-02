const int maxn = 1000000 + 10;
const int INF = int(1e9);
using namespace std;
int fa[maxn];  //父亲结点
int Rank[maxn];  //树的的高度
void init(int n)  //初始化所有结点
{
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
        Rank[i] = 0;
    }
}
int find(int x)  //查询树结点的根
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);  //并查集压缩路径
}
void unite(int x, int y)  //合并x结点和y结点所属的集合
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (Rank[x] < Rank[y])  //低的树接到高的树上面
        fa[x] = y;
    else
    {
        fa[y] = x;
        if (Rank[x] == Rank[y])
            Rank[x]++;
    }
}
bool same(int x, int y)    //判断x和y是否在同一集合上
{
    return find(x) == find(y);
}