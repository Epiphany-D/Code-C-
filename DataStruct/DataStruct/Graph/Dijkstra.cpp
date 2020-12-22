void dijkstra(int s) {  //记得处理第一个加入集合的点
    for (int i = 1; i <= n; i++) dis[i] = inf;//初始化,n为顶点个数
    dis[s] = 0;//处理加入集合的第一个点
    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (k == 0 || dis[j] < dis[k]))
                k = j;
        vis[k] = 1;//标记此节点已入栈
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[k] + a[k][j] < dis[j])
                dis[j] = dis[k] + a[k][j];
        }
    }
}