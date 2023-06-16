#include <iostream>
#include <stdbool.h>

#define N 8 //�̷� �� �� ����
#define WAY 0 //������ ���� ��
#define WALL 1 //��
#define BLOCK 2 //visited�̸�, �ⱸ�� ��ΰ� �ƴ�
#define PASS 3 //visited�̸�, �ⱸ�� ��ΰ� �� �� ���� 

using namespace std;

class Maze {
public:
	int maze[N][N] = {
	{0, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 1, 0, 1, 1, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{0, 1, 0, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 0, 0, 1, 1},
	{0, 1, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{0, 1, 1, 1, 0, 1, 0, 0},
	};

	bool findMaze(int x, int y) { //x,y ��ǥ�κ��� ���� ã�´�
		if (x < 0 || y < 0 || x >= N || y >= N)
			return false;
		else if (maze[x][y] != WAY)
			return false;
		else if (x == N - 1 && y == N - 1) { //�ⱸ ����
			maze[x][y] = PASS;
			return true;
		}
		else {
			maze[x][y] = PASS;

			if (findMaze(x - 1, y) || findMaze(x, y + 1) //�������� ������ Ž��
				|| findMaze(x + 1, y) || findMaze(x, y - 1))
				return true;

			maze[x][y] = BLOCK; //dead end
			return false;
		}
	}

	void printMaze() {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (maze[x][y] == WAY)
					cout << "��\t";
				else if (maze[x][y] == WALL)
					cout << "��\t";
				else if (maze[x][y] == BLOCK)
					cout << "X\t";
				else if (maze[x][y] == PASS)
					cout << "O\t";
			}
			cout << endl;
		}
	}
};


int main() {
	Maze M;

	M.printMaze();
	M.findMaze(0, 0);

	cout << endl;
	M.printMaze();
}