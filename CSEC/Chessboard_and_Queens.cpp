#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void action(int step, bool (*board)[8]) {
    int dx[8] = {-1 , 1 , 0 , 0 , -1 , -1 , 1 , 1};
    int dy[8] = {0 , 0 , -1 , 1 , -1 , 1 , -1 , 1};
    bool temp_board[8][8];
    memcpy(temp_board, board, sizeof(bool) * 8 * 8);
    for (int i = 0; i < 8; i++) {
        if (step == 7 && board[step][i] == false) {
                ans++;
                break;
        }
        if (board[step][i] == false) {
            for (int k = 1; k <= 7; k++){
                for (int j = 0; j < 8; j++) {
                    int x = i+dx[j]*k , y = step+dy[j]*k;
                    if (y > 7 || y < 0 || x > 7 || x < 0) {
                        continue;
                    }
                    board[y][x] = true;
                }
            }
            action(step+1 , board);
            memcpy(board, temp_board, sizeof(bool) * 8 * 8);
        }
    } 
}
int main () {
    bool initial_board[8][8];
    string s;
    for (int i = 0; i < 8; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '.')
                initial_board[i][j] = false;
            else 
                initial_board[i][j] = true;
        }
    }
    bool board[8][8];
    memcpy(board, initial_board, sizeof(initial_board));
    action(0 , board);
    cout << ans << '\n';
    return 0;
}