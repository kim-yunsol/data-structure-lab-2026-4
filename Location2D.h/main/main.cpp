#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

class Location2D {
public:
    int row;
    int col;

    Location2D(int r = 0, int c = 0) {
        row = r;
        col = c;
    }

    bool operator==(Location2D p) {
        return row == p.row && col == p.col;
    }
};
const int MAZE_SIZE = 6;
// 0: 갈 수 있는 길
// 1: 벽
int map[MAZE_SIZE][MAZE_SIZE] = {
    { 1, 1, 1, 1, 1, 1 },
    { 0, 0, 1, 0, 0, 1 },
    { 1, 0, 1, 0, 1, 1 },
    { 1, 0, 1, 0, 1, 1 },
    { 1, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1 }
};


bool isValidLoc(int r, int c) {
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
        return false;

    return map[r][c] == 0;
}

void printLoc(Location2D loc, bool isLast = false) {
    cout << "(" << loc.row << "," << loc.col << ")";

    if (!isLast)
        cout << " -> ";
}

void DFS_stack() {
    bool visited[MAZE_SIZE][MAZE_SIZE] = { false };

    stack<Location2D> locStack;
    Location2D start(1, 0);
    Location2D exit(4, 5);

    locStack.push(start);

    cout << "# DFS 결과" << endl;

    bool first = true;

    while (!locStack.empty()) {
        Location2D here = locStack.top();
        locStack.pop();

        int r = here.row;
        int c = here.col;

        if (!isValidLoc(r, c) || visited[r][c])
            continue;

        visited[r][c] = true;

        if (!first)
            cout << " -> ";

        cout << "(" << r << "," << c << ")";
        first = false;

        if (here == exit)
            break;

        // stack은 나중에 넣은 것이 먼저 나오므로
        // 원하는 DFS 순서를 만들기 위해 역순으로 push
        locStack.push(Location2D(r - 1, c)); // 위
        locStack.push(Location2D(r, c - 1)); // 왼쪽
        locStack.push(Location2D(r, c + 1)); // 오른쪽
        locStack.push(Location2D(r + 1, c)); // 아래
    }

    cout << endl << endl;
}

void DFS_deque() {
    bool visited[MAZE_SIZE][MAZE_SIZE] = { false };

    deque<Location2D> locDeque;
    Location2D start(1, 0);
    Location2D exit(4, 5);

    locDeque.push_back(start);

    cout << "# DFS 결과" << endl;

    bool first = true;

    while (!locDeque.empty()) {
        Location2D here = locDeque.back();
        locDeque.pop_back();

        int r = here.row;
        int c = here.col;

        if (!isValidLoc(r, c) || visited[r][c])
            continue;

        visited[r][c] = true;

        if (!first)
            cout << " -> ";

        cout << "(" << r << "," << c << ")";
        first = false;

        if (here == exit)
            break;

        // deque을 stack처럼 사용
        locDeque.push_back(Location2D(r - 1, c)); // 위
        locDeque.push_back(Location2D(r, c - 1)); // 왼쪽
        locDeque.push_back(Location2D(r, c + 1)); // 오른쪽
        locDeque.push_back(Location2D(r + 1, c)); // 아래
    }

    cout << endl << endl;
}

void BFS_queue() {
    bool visited[MAZE_SIZE][MAZE_SIZE] = { false };

    queue<Location2D> locQueue;
    Location2D start(1, 0);
    Location2D exit(4, 5);

    locQueue.push(start);
    visited[start.row][start.col] = true;

    cout << "# BFS 결과" << endl;

    bool first = true;

    while (!locQueue.empty()) {
        Location2D here = locQueue.front();
        locQueue.pop();

        int r = here.row;
        int c = here.col;

        if (!first)
            cout << " -> ";

        cout << "(" << r << "," << c << ")";
        first = false;

        if (here == exit)
            break;

        // BFS는 queue라서 넣은 순서대로 탐색됨
        // 아래 -> 오른쪽 -> 위 -> 왼쪽 순서
        int dr[4] = { 1, 0, -1, 0 };
        int dc[4] = { 0, 1, 0, -1 };

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValidLoc(nr, nc) && !visited[nr][nc]) {
                visited[nr][nc] = true;
                locQueue.push(Location2D(nr, nc));
            }
        }
    }

    cout << endl;
}

int main() {
    int ds_num;

    printf("DFS 데이터 구조 라이브러리 선택: 1)stack, 2)deque \n");
    scanf("%d", &ds_num);

    switch (ds_num) {
    case 1:
        // Stack 데이터구조 사용
        DFS_stack();
        break;

    case 2:
        // Deque 데이터구조 사용
        DFS_deque();
        break;

    default:
        cout << "잘못된 입력입니다." << endl;
        return 0;
    }

    printf("BFS 미로탐색\n");
    BFS_queue();

    return 0;
}