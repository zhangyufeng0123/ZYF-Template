//解决多个不递减子序列的最大和
#include<bits/stdc++.h>

using namespace std;

const int maxn = (int) 1e4 + 100;
const int INF = INT_MAX;
typedef pair<int, int> p;

struct edge {
    int to, capacity, cost, rev;

    edge() {}

    edge(int to, int _capacity, int _cost, int _rev) : to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};

struct Min_Cost_Max_Flow {
    int V, H[maxn], dis[maxn], prev[maxn], pree[maxn];
    vector<edge> G[maxn];

    void init(int n) {
        V = n;
        for (int i = 0; i <= V; i++) {
            G[i].clear();
        }
    }

    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back(edge(to, cap, cost, G[to].size()));
        G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
    }

    int Min_cost_max_flow(int s, int t, int f, int &flow) {
        int res = 0;
        fill(H, H + 1 + V, 0);
        while (f) {
            priority_queue<p, vector<p>, greater<p> > q;
            fill(dis, dis + 1 + V, INF);
            dis[s] = 0;
            q.push(p(0, s));
            while (!q.empty()) {
                p now = q.top();
                q.pop();
                int v = now.second;
                if (dis[v] < now.first) {
                    continue;
                }
                for (int i = 0; i < G[v].size(); i++) {
                    edge &e = G[v][i];
                    if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
                        dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
                        pree[e.to] = i;
                        prev[e.to] = v;
                        q.push(p(dis[e.to], e.to));
                    }
                }
            }
            if (dis[t] == INF) {
                break;
            }
            for (int i = 0; i <= V; i++) {
                H[i] += dis[i];
            }
            int d = f;
            for (int v = t; v != s; v = prev[v]) {
                d = min(d, G[prev[v]][pree[v]].capacity);
            }
            f -= d;
            flow += d;
            res += d * H[t];
            for (int v = t; v != s; v = prev[v]) {
                edge &e = G[prev[v]][pree[v]];
                e.capacity -= d;
                G[v][e.rev].capacity += d;
            }

        }
        return res;
    }
    int Max_cost_max_flow(int s, int t, int f, int& flow) {
        int res = 0;
        fill(H, H + 1 + V, 0);
        while (f) {
            priority_queue <pair<int, int>> q;
            fill(dis, dis + 1 + V, -INF);
            dis[s] = 0;
            q.push(pair<int, int>(0, s));
            while (!q.empty()) {
                pair<int, int> now = q.top(); q.pop();
                int v = now.second;
                if (dis[v] > now.first)continue;
                for (int i = 0; i < G[v].size(); ++i) {
                    edge& e = G[v][i];
                    if (e.capacity > 0 && dis[e.to] < dis[v] + e.cost + H[v] - H[e.to]) {
                        dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
                        prev[e.to] = v;
                        pree[e.to] = i;
                        q.push(pair<int, int>(dis[e.to], e.to));
                    }
                }
            }
            if (dis[t] == -INF)break;
            for (int i = 0; i <= V; ++i)H[i] += dis[i];
            int d = f;
            for (int v = t; v != s; v = prev[v])d = min(d, G[prev[v]][pree[v]].capacity);
            f -= d; flow += d;
            res += d*H[t];
            for (int v = t; v != s; v = prev[v]) {
                edge& e = G[prev[v]][pree[v]];
                e.capacity -= d;
                G[v][e.rev].capacity += d;
            }
        }
        return res;
    }
};

int n, k, s1, s2, t, flow, arr[maxn];
Min_Cost_Max_Flow MCMF;

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        s1 = 0;
        s2 = 2 * n + 1;
        t = 2 * n + 2;
        MCMF.init(t);
        MCMF.add_edge(s1, s2, k, 0);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            MCMF.add_edge(i, i + n, 1, -arr[i]);
        }

        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(arr[i] <= arr[j]){
                    MCMF.add_edge(i + n, j, 1, 0);
                }
            }
        }

        for(int i = 1; i <= n; i++){
            MCMF.add_edge(s2, i, 1, 0);
            MCMF.add_edge(i + n, t, 1, 0);
        }
        cout << -MCMF.Min_cost_max_flow(s1, t, INF, flow) << endl;
    }
}