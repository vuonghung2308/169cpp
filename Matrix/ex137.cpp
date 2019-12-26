#include <iostream>
#include <queue>
using namespace std;

const int rowNum[] = {-1, 0, 1, 0};
const int colNum[] = {0, -1, 0, 1};

struct Point {
	int x;
	int y;
};
struct queueNode {
	Point pt;
	int dist;
};
bool isSafe(int col, int row, int COL, int ROW) {
	return col >=0 && row >= 0 && col < COL && row < ROW;
}
int BFS(int **a, int COL, int ROW, Point src, Point dest) {
	if(!a[src.x][src.y] || !a[dest.x][dest.y])
		return -1;
	bool visited[ROW][COL] = {0};
	
	visited[src.x][src.y] = 1;
	queue<queueNode> q;
	queueNode s = {src, 0};
	q.push(s);
	
	while(!q.empty()) {
		queueNode curr = q.front();
		Point pt = curr.pt;
		if(pt.x == dest.x && pt.y == dest.y)
			return curr.dist;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			if(isSafe(col, row, COL, ROW) && !visited[row][col] && a[row][col]) {
				visited[row][col] = 1;
				queueNode Adjcell = {{row, col}, curr.dist+1};
				q.push(Adjcell);
			}
		}
	}
	return -1;
}
int main() {
	int t; cin >> t;
	for(int x = 1; x <= t; x++) {
		int m, n, **a;
		Point src, dest;
		cin >> n >> m >> src.x >> src.y >> dest.x >> dest.y;
		a = new int *[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		cout << BFS(a, m, n, src, dest) << endl;
	}
}
