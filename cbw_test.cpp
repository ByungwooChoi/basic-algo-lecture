#include <bits/stdc++.h>
#include <list>
using namespace std;
#define X first
#define Y second

int k, n, m;
char board[1002][1002];
int dist[2][12][1002][1002]; // dist[d][k][x][y] 는 x, y번에 말처럼 k번 이동한 상태의 거리. d는 day or night
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<tuple<int, int, int, int>> Q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    dist[0][0][0][0] = 1;
    Q.push({0, 0, 0, 0});
    while(!Q.empty()){
        auto [vd, vk, vx, vy] = Q.front(); Q.pop();
        int next_time = dist[vd][vk][vx][vy] + 1;
        int next_day = !vd;
        for(int i=0;i<4;i++){
            int nx = vx + dx[i];
            int ny = vy + dy[i];
            if(nx < 0 || ny < 0 || nx >=n || ny >= m){
                continue;
            }
            if(dist[next_day][vk][nx][ny] == 0 && board[nx][ny] == '0'){ // 빈 칸일 때
                dist[next_day][vk][nx][ny] = next_time;
                Q.push({next_day, vk, nx, ny});
            }else if(board[nx][ny] == '1' && vk < k){ // 벽일 때
                if(vd==0 && dist[next_day][vk+1][nx][ny] == 0){ // 낮이고 첫 방문일 때
                    dist[next_day][vk+1][nx][ny] = next_time;
                    Q.push({next_day, vk+1, nx, ny});
                }else if(vd==1 && dist[next_day][vk][nx][ny] == 0){ // 밤이고 첫방문이라 기다렸다가 가야할 때
                    dist[next_day][vk][vx][vy] = next_time;
                    Q.push({next_day, vk, vx, vy});
                }
            }
        }
    }
    int ans = 0x7f7f7f7f;
    for(int i=0;i<=k;i++){
        if(dist[0][i][n-1][m-1]) ans = min(ans, dist[0][i][n-1][m-1]);
        if(dist[1][i][n-1][m-1]) ans = min(ans, dist[1][i][n-1][m-1]);
    }
    if(ans == 0x7f7f7f7f) cout << -1;
    else cout << ans;
}   