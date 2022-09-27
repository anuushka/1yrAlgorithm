#include <bits/stdc++.h>

int grid[100][100];

class Point
{
	public:
		int y;
		int x;
		int d;
    Point(int x, int y, int w) : y(x), x(y), d(w)
    {
	}
};

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int m,n;
    fin >> n >> m;
    char c;
    Point start(0,0,0), end(0,0,0);

    fin.get(c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            	fin.get(c);
            switch (c) {
                case '.':
                    grid[i][j] = INT32_MAX;
                    break;
                case '#':
                    grid[i][j] = -1;
                    break;
                case 'S':
                    grid[i][j] = 0;
                    start.x = j;
                    start.y = i;
                    start.d = 0;
                    break;
                case 'T':
                    grid[i][j] = INT32_MAX;
                    end.x = j;
                    end.y = i;
                    break;

                default: {

                }
            }
        }
        fin.get(c);
    }

    std::queue<Point> q;
    q.push(start);

    while (!q.empty()) {
         Point point = q.front();
        q.pop();

        if (point.x == end.x && point.y == end.y) {
            break;
        }

        if (point.x + 1 < m && grid[point.y][point.x + 1] == INT32_MAX) {
            grid[point.y][point.x + 1] = point.d + 1;
            Point p(point.y, point.x + 1, point.d + 1);
            q.push(p);
        }
        if (point.x - 1 >= 0 && grid[point.y][point.x - 1] == INT32_MAX) {
            grid[point.y][point.x - 1] = point.d + 1;
            Point p(point.y, point.x - 1, point.d + 1);
            q.push(p);
        }
        if (point.y + 1 < n && grid[point.y + 1][point.x] == INT32_MAX) {
            grid[point.y + 1][point.x] = point.d + 1;
            Point p(point.y + 1, point.x, point.d + 1);
            q.push(p);
        }
        if (point.y - 1 >= 0 && grid[point.y - 1][point.x] == INT32_MAX) {
            grid[point.y - 1][point.x] = point.d + 1;
            Point p(point.y - 1, point.x, point.d + 1);
            q.push(p);
        }
    }

    if (grid[end.y][end.x] == INT32_MAX) {
        fout << -1 << std::endl;
        return 0;
    }

    fout << grid[end.y][end.x] << std::endl;

    std::string s;
    int x = end.x, y = end.y;
    while (x != start.x || y != start.y) 
	{
        if (x - 1 >= 0 && grid[y][x-1] + 1 == grid[y][x]) {
            s = 'R' + s;
            x--;
            continue;
        }
        if (y - 1 >= 0 && grid[y-1][x] + 1 == grid[y][x]) {
            s = 'D' + s;
            y--;
            continue;
        }
        if (y + 1 < n && grid[y+1][x] + 1 == grid[y][x]) {
            s = 'U' + s;
            y++;
            continue;
        }
        if (x + 1 < n && grid[y][x+1] + 1 == grid[y][x]) {
            s = 'L' + s;
            x++;
            continue;
        }
    }

    fout << s;

    return 0;
}
