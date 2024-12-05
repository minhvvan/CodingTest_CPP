#include <stdio.h>
 
const int MAX_N = 10000;
const int MAX_M = 100;
int ans, N, L, M, idx;
char section[MAX_N + 5][MAX_N + 5];
struct Node {
    int x, y;
}fish[MAX_M], chk[MAX_M * MAX_M];
 
void fishing(int sx, int sy, int l1, int l2) {
    int cnt = 0;
    int ex = sx + l1, ey = sy + l2;
    // 잡을 수 있는 물고기 개수 확인
    for (int i = 0; i < M; ++i) {
        if (sx <= fish[i].x && fish[i].x <= ex &&
            sy <= fish[i].y && fish[i].y <= ey)
            cnt++;
    }
    // 가장 많이 잡은 경우
    ans = ans < cnt ? cnt : ans;
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &N, &L, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &fish[i].x, &fish[i].y);
        // 물고기가 존재하는 위치 설정
        section[fish[i].x][fish[i].y] = 'Y';
        chk[idx++] = { fish[i].x, fish[i].y };
 
    }
 
    // 중복여부를 확인하면서 물고기들 교차점 위치 확인 
    for (int i = 0; i < M - 1; ++i) {
        for (int j = i; j < M; ++j) {
            if (section[fish[i].x][fish[j].y] != 'Y') {
                chk[idx++] = { fish[i].x, fish[j].y };
                section[fish[i].x][fish[j].y] = 'Y';
            }
            if (section[fish[j].x][fish[i].y] != 'Y') {
                chk[idx++] = { fish[j].x, fish[i].y };
                section[fish[j].x][fish[i].y] = 'Y';
            }
        }
    }
 
    int l1 = 1, l2 = (L - 2) / 2;
    while (l2 > 0) {
        for (int i = 0; i < idx; ++i) {
            // 찾은 교차점과 물고기 위치에서 그물 치기
            fishing(chk[i].x, chk[i].y, l1, l2);
        }
        l1++; l2--;
    }
    printf("%d\n", ans);
}