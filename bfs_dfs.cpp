#include <bits/stdc++.h>

using namespace std;

void bfs(int cur, int** ms, int n, int* parent, int* dist, int& r){
    for(int i = 1; i <= n; ++i)
        parent[i] = dist[i] = -1;
    dist[cur] = parent[cur] = 0;
    queue<int> q;
    q.push(cur);
    int i;
    r = 0;
    while(!q.empty()){
        i = q.front();
        q.pop();
        for(int j = 1; j <= n; ++j){
            if(ms[i][j] > 0 && parent[j] == -1){
                q.push(j);
                dist[j] = dist[i] + 1;
                parent[j] = i;
                if(dist[j] > r)
                    r = dist[j];
            }

        }
    }
}

void dfs(int cur, int n, int** ms, int* parent){
    int i = cur;
    for(int j = 1; j <= n; j++){
        if(ms[i][j] > 0 && parent[j] == -1){
            parent[j] = i;
            dfs(j, n, ms, parent);
        }
    }
    cout << cur << " ";
}

int main() {
    srand(time(0));
    int n, m, x, y;
    cin >> n >> m;

    // Обьявление и инициализация матрицы смежности, массива ребер и массива списка смежностей
    int** ms = new int *[n + 1];
    int** mr = new int *[m];
    vector<vector<int>> mss(n + 1, vector<int> (0));

    for(int i = 0; i <= n; i++) ms[i] = new int [n + 1];
    for(int i = 0; i < m; i++) mr[i] = new int [2];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ms[i][j] = 0;
        }
    }

    // Заполление данными матрицы смежности, массива ребер и массива списка смежностей
    for(int i = 0; i < m; i++){
        cin >> x >> y;

        ms[x][y] = 1;
        ms[y][x] = 1;
        mr[i][0] = x;
        mr[i][1] = y;
        mss[x].push_back(y);
        mss[y].push_back(x);
    }

    // BFS -----------------------------------
    int* parent = new int[n + 1];
    int* dist = new int[n + 1];
    int r, min_r = n + 1;
    vector<int> capitals;
    for(int first = 1; first <= n; ++first){
        bfs(first, ms, n, parent, dist, r);
        if(r < min_r){
            min_r = r;
            capitals.clear();
            capitals.push_back(first);
        } else if(r == min_r)
            capitals.push_back(first);
    }
    cout << min_r << "\n";
    for(int i = 0; i < capitals.size(); ++i)
        cout << capitals[i] << " ";
    // ---------------------------------------


    // Вывод матрицы смежности, массива ребер и массива списка смежностей 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ms[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for(int i = 0; i < m; i++) cout << mr[i][0] << " " << mr[i][1] << "\n";
    cout << "\n";

    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(int j = 0; j < mss[i].size(); j++){
            cout << mss[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
