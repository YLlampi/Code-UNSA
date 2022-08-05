#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 15;
const int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};//up down down
const int dy[] = {1, -1, -1, 0, 1, -1, 0, 1};
char map[N][N];
int n;
struct Node
{
    int x, y;
    Node() {}
    Node(int a, int b){
        x = a;
        y = b;
    }
};

void bfs(int x, int y)
{
    queue<Node> q;
    q.push(Node(x, y));
    while(!q.empty()){
        Node tmp = q.front(), tmp1;
        if(map[tmp.x][tmp.y] == '0')
        for(int i = 0 ; i < 8; i ++){
            tmp1.x = tmp.x + dx[i]; tmp1.y = tmp.y + dy[i];
            if(tmp1.x < 1 || tmp1.x > n || tmp1.y < 1 || tmp1.y > n || map[tmp1.x][tmp1.y] == '@') continue;
            q.push(tmp1);
        }
        map[tmp.x][tmp.y] = '@';
        q.pop();
    }
    return ;
}
int main()
{
    int T, k = 1;
    cin >> T;
    while(T --){
        cin >> n;
        getchar();
        for(int i = 1; i <= n; i ++){
            for(int j  = 1; j <= n; j ++){
                scanf("%c", &map[i][j]);
            }
            getchar();
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(map[i][j] == '0'){
                    bfs(i, j);
                    ans ++;
                }

            }
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(map[i][j] != '@'){
                    ans ++;
                }
            }
        }
        cout << "Case " << k ++ << ": ";
        cout << ans << endl;
    }
    return 0;
}