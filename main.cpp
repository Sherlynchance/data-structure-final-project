#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Maze.cpp"
#include "Mover.cpp"
#include "Player.cpp"
#include "Enemy.cpp"

using namespace std;
void detectKey(Player &player, Maze m) {
    if (GetAsyncKeyState(VK_DOWN)) {
        player.move(3, m);
    } else if (GetAsyncKeyState(VK_RIGHT)) {
        player.move(1, m);
    } else if (GetAsyncKeyState(VK_UP)) {
        player.move(2, m);
    } else if (GetAsyncKeyState(VK_LEFT)) {
        player.move(0, m);
    }
}

Node findRandomEnemyPos(Maze m) {
    for (int i = 10; i < 15; i++) {
        for (int j = 10; j < 15; j++) {
            if (m.isWalkable(i, j)) {
                return { i, j };
            }
        }
    }
}

int main() {
	Maze m(20);
	m.generateMaze();
	m.printMaze();

	bool playing = true;
	Player player(2, 1);

	Node enemyPos = findRandomEnemyPos(m);
	Enemy enemy(enemyPos.x, enemyPos.y);

	while (playing){
        detectKey(player, m);
       	player.printMover();

       	enemy.move();
        enemy.bfs(player.getX(), player.getY(), m);

        if (player.getX() == enemy.getX() && player.getY() == enemy.getY()) {
            break;
        }

        Sleep(100);
	}
}
