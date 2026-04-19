class CountSquares {
public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int i = 1;
        int j = 1;
        int count = 0;
        while (x + i < 1001 && y + j < 1001) {
            count += points[x + i][y] * points[x][y + j] * points[x + i][y + j];
            i++; j++;
        }
        i = 1;
        j = 1;
        while (x - i >= 0 && y + j < 1001) {
            count += points[x - i][y] * points[x][y + j] * points[x - i][y + j];
            i++; j++;
        }
        i = 1;
        j = 1;
        while (x - i >= 0 && y - j >=  0) {
            count += points[x - i][y] * points[x][y - j] * points[x - i][y - j];
            i++; j++;
        }
        i = 1;
        j = 1;
        while (x + i < 1001 && y - j >= 0) {
            count += points[x + i][y] * points[x][y - j] * points[x + i][y - j];
            i++; j++;
        }
        return count;
    }
private:
    vector<vector<int>> points = vector<vector<int>>(1005, vector<int>(1005, 0));;
};
